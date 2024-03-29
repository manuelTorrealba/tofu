/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2017-2018 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "finiteVolume/cfdTools/general/levelSet/levelSet.hpp"
#include "OpenFOAM/meshes/primitiveShapes/cut/cut.hpp"
#include "OpenFOAM/meshes/polyMesh/polyMeshTetDecomposition/polyMeshTetDecomposition.hpp"
#include "OpenFOAM/meshes/polyMesh/polyMeshTetDecomposition/tetIndices.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

template<class Type>
Foam::tmp<Foam::Field<Type>> Foam::levelSetAverage
(
    const fvMesh& mesh,
    const scalarField& levelC,
    const scalarField& levelP,
    const Field<Type>& positiveC,
    const Field<Type>& positiveP,
    const Field<Type>& negativeC,
    const Field<Type>& negativeP
)
{
    tmp<Field<Type>> tResult(new Field<Type>(mesh.nCells(), Zero));
    Field<Type>& result = tResult.ref();

    forAll(result, cI)
    {
        const List<tetIndices> cellTetIs =
            polyMeshTetDecomposition::cellTetIndices(mesh, cI);

        scalar v = 0;
        Type r = Zero;

        forAll(cellTetIs, cellTetI)
        {
            const triFace triIs = cellTetIs[cellTetI].faceTriIs(mesh);

            const FixedList<point, 4>
                tet =
                {
                    mesh.cellCentres()[cI],
                    mesh.points()[triIs[0]],
                    mesh.points()[triIs[1]],
                    mesh.points()[triIs[2]]
                };
            const FixedList<scalar, 4>
                level =
                {
                    levelC[cI],
                    levelP[triIs[0]],
                    levelP[triIs[1]],
                    levelP[triIs[2]]
                };
            const cut::volumeIntegrateOp<Type>
                positive = FixedList<Type, 4>
                ({
                    positiveC[cI],
                    positiveP[triIs[0]],
                    positiveP[triIs[1]],
                    positiveP[triIs[2]]
                });
            const cut::volumeIntegrateOp<Type>
                negative = FixedList<Type, 4>
                ({
                    negativeC[cI],
                    negativeP[triIs[0]],
                    negativeP[triIs[1]],
                    negativeP[triIs[2]]
                });

            v += cut::volumeOp()(tet);

            r += tetCut(tet, level, positive, negative);
        }

        result[cI] = r/v;
    }

    return tResult;
}


template<class Type>
Foam::tmp<Foam::Field<Type>> Foam::levelSetAverage
(
    const fvPatch& patch,
    const scalarField& levelF,
    const scalarField& levelP,
    const Field<Type>& positiveF,
    const Field<Type>& positiveP,
    const Field<Type>& negativeF,
    const Field<Type>& negativeP
)
{
    typedef typename outerProduct<Type, vector>::type sumType;

    tmp<Field<Type>> tResult(new Field<Type>(patch.size(), Zero));
    Field<Type>& result = tResult.ref();

    forAll(result, fI)
    {
        const face& f = patch.patch().localFaces()[fI];

        vector a = vector::zero;
        sumType r = Zero;

        for(label eI = 0; eI < f.size(); ++ eI)
        {
            const edge e = f.faceEdge(eI);

            const FixedList<point, 3>
                tri =
                {
                    patch.patch().faceCentres()[fI],
                    patch.patch().localPoints()[e[0]],
                    patch.patch().localPoints()[e[1]]
                };
            const FixedList<scalar, 3>
                level =
                {
                    levelF[fI],
                    levelP[e[0]],
                    levelP[e[1]]
                };
            const cut::areaIntegrateOp<Type>
                positive = FixedList<Type, 3>
                ({
                    positiveF[fI],
                    positiveP[e[0]],
                    positiveP[e[1]]
                });
            const cut::areaIntegrateOp<Type>
                negative = FixedList<Type, 3>
                ({
                    negativeF[fI],
                    negativeP[e[0]],
                    negativeP[e[1]]
                });

            a += cut::areaOp()(tri);

            r += triCut(tri, level, positive, negative);
        }

        result[fI] = a/magSqr(a) & r;
    }

    return tResult;
}


template<class Type>
Foam::tmp<Foam::GeometricField<Type, Foam::fvPatchField, Foam::volMesh>>
Foam::levelSetAverage
(
    const volScalarField& levelC,
    const pointScalarField& levelP,
    const GeometricField<Type, fvPatchField, volMesh>& positiveC,
    const GeometricField<Type, pointPatchField, pointMesh>& positiveP,
    const GeometricField<Type, fvPatchField, volMesh>& negativeC,
    const GeometricField<Type, pointPatchField, pointMesh>& negativeP
)
{
    const fvMesh& mesh = levelC.mesh();

    tmp<GeometricField<Type, fvPatchField, volMesh>> tResult
    (
        new GeometricField<Type, fvPatchField, volMesh>
        (
            IOobject
            (
                positiveC.name() + ":levelSetAverage",
                mesh.time().timeName(),
                mesh
            ),
            mesh,
            dimensioned<Type>("0", positiveC.dimensions(), Zero)
        )
    );
    GeometricField<Type, fvPatchField, volMesh>& result = tResult.ref();

    result.primitiveFieldRef() =
        levelSetAverage
        (
            mesh,
            levelC.primitiveField(),
            levelP.primitiveField(),
            positiveC.primitiveField(),
            positiveP.primitiveField(),
            negativeC.primitiveField(),
            negativeP.primitiveField()
        );

    forAll(mesh.boundary(), patchi)
    {
        result.boundaryFieldRef()[patchi] =
            levelSetAverage
            (
                mesh.boundary()[patchi],
                levelC.boundaryField()[patchi],
                levelP.boundaryField()[patchi].patchInternalField()(),
                positiveC.boundaryField()[patchi],
                negativeP.boundaryField()[patchi].patchInternalField()(),
                positiveC.boundaryField()[patchi],
                negativeP.boundaryField()[patchi].patchInternalField()()
            );
    }

    return tResult;
}


// ************************************************************************* //
