/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2018 OpenFOAM Foundation
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

#include "dynamicMesh/motionSmoother/motionSmootherAlgo.hpp"
#include "meshTools/meshTools/meshTools.hpp"
#include "OpenFOAM/fields/pointPatchFields/constraint/processor/processorPointPatchFields.hpp"
#include "OpenFOAM/fields/pointPatchFields/pointPatchField/pointConstraint/pointConstraint.hpp"
#include "finiteVolume/interpolation/volPointInterpolation/pointConstraints.hpp"
#include "OpenFOAM/meshes/polyMesh/syncTools/syncTools.hpp"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

template<class Type>
void Foam::motionSmootherAlgo::checkConstraints
(
    GeometricField<Type, pointPatchField, pointMesh>& pf
)
{
    typedef GeometricField<Type, pointPatchField, pointMesh> FldType;

    const polyMesh& mesh = pf.mesh();

    const polyBoundaryMesh& bm = mesh.boundaryMesh();

    // first count the total number of patch-patch points

    label nPatchPatchPoints = 0;

    forAll(bm, patchi)
    {
        if (!isA<emptyPolyPatch>(bm[patchi]))
        {
            nPatchPatchPoints += bm[patchi].boundaryPoints().size();
        }
    }


    typename FldType::Boundary& bFld = pf.boundaryField();


    // Evaluate in reverse order

    forAllReverse(bFld, patchi)
    {
        bFld[patchi].initEvaluate(Pstream::commsTypes::blocking);   // buffered
    }

    forAllReverse(bFld, patchi)
    {
        bFld[patchi].evaluate(Pstream::commsTypes::blocking);
    }


    // Save the values

    Field<Type> boundaryPointValues(nPatchPatchPoints);
    nPatchPatchPoints = 0;

    forAll(bm, patchi)
    {
        if (!isA<emptyPolyPatch>(bm[patchi]))
        {
            const labelList& bp = bm[patchi].boundaryPoints();
            const labelList& meshPoints = bm[patchi].meshPoints();

            forAll(bp, pointi)
            {
                label ppp = meshPoints[bp[pointi]];
                boundaryPointValues[nPatchPatchPoints++] = pf[ppp];
            }
        }
    }


    // Forward evaluation

    bFld.evaluate();


    // Check

    nPatchPatchPoints = 0;

    forAll(bm, patchi)
    {
        if (!isA<emptyPolyPatch>(bm[patchi]))
        {
            const labelList& bp = bm[patchi].boundaryPoints();
            const labelList& meshPoints = bm[patchi].meshPoints();

            forAll(bp, pointi)
            {
                label ppp = meshPoints[bp[pointi]];

                const Type& savedVal = boundaryPointValues[nPatchPatchPoints++];

                if (savedVal != pf[ppp])
                {
                    FatalErrorInFunction
                        << "Patch fields are not consistent on mesh point "
                        << ppp << " coordinate " << mesh.points()[ppp]
                        << " at patch " << bm[patchi].name() << '.'
                        << endl
                        << "Reverse evaluation gives value " << savedVal
                        << " , forward evaluation gives value " << pf[ppp]
                        << abort(FatalError);
                }
            }
        }
    }
}


template<class Type>
Foam::tmp<Foam::GeometricField<Type, Foam::pointPatchField, Foam::pointMesh>>
Foam::motionSmootherAlgo::avg
(
    const GeometricField<Type, pointPatchField, pointMesh>& fld,
    const scalarField& edgeWeight
) const
{
    tmp<GeometricField<Type, pointPatchField, pointMesh>> tres
    (
        new GeometricField<Type, pointPatchField, pointMesh>
        (
            IOobject
            (
                "avg("+fld.name()+')',
                fld.time().timeName(),
                fld.db(),
                IOobject::NO_READ,
                IOobject::NO_WRITE,
                false
            ),
            fld.mesh(),
            dimensioned<Type>("zero", fld.dimensions(), Zero)
        )
    );
    GeometricField<Type, pointPatchField, pointMesh>& res = tres.ref();

    const polyMesh& mesh = fld.mesh()();


    // Sum local weighted values and weights
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // Note: on coupled edges use only one edge (through isMasterEdge)
    // This is done so coupled edges do not get counted double.

    scalarField sumWeight(mesh.nPoints(), 0.0);

    const edgeList& edges = mesh.edges();

    forAll(edges, edgeI)
    {
        if (isMasterEdge_.get(edgeI) == 1)
        {
            const edge& e = edges[edgeI];
            const scalar w = edgeWeight[edgeI];

            res[e[0]] += w*fld[e[1]];
            sumWeight[e[0]] += w;

            res[e[1]] += w*fld[e[0]];
            sumWeight[e[1]] += w;
        }
    }


    // Add coupled contributions
    // ~~~~~~~~~~~~~~~~~~~~~~~~~

    syncTools::syncPointList
    (
        mesh,
        res,
        plusEqOp<Type>(),
        Type(Zero)     // null value
    );
    syncTools::syncPointList
    (
        mesh,
        sumWeight,
        plusEqOp<scalar>(),
        scalar(0)               // null value
    );


    // Average
    // ~~~~~~~

    forAll(res, pointi)
    {
        if (mag(sumWeight[pointi]) < vSmall)
        {
            // Unconnected point. Take over original value
            res[pointi] = fld[pointi];
        }
        else
        {
            res[pointi] /= sumWeight[pointi];
        }
    }

    // Single and multi-patch constraints
    pointConstraints::New(fld.mesh()).constrain(res, false);

    return tres;
}


template<class Type>
void Foam::motionSmootherAlgo::smooth
(
    const GeometricField<Type, pointPatchField, pointMesh>& fld,
    const scalarField& edgeWeight,
    GeometricField<Type, pointPatchField, pointMesh>& newFld
) const
{
    tmp<pointVectorField> tavgFld = avg(fld, edgeWeight);
    const pointVectorField& avgFld = tavgFld();

    forAll(fld, pointi)
    {
        if (isInternalPoint(pointi))
        {
            newFld[pointi] = 0.5*fld[pointi] + 0.5*avgFld[pointi];
        }
    }

    // Single and multi-patch constraints
    pointConstraints::New(fld.mesh()).constrain(newFld, false);
}


template<class Type, class CombineOp>
void Foam::motionSmootherAlgo::testSyncField
(
    const Field<Type>& fld,
    const CombineOp& cop,
    const Type& zero,
    const scalar maxMag
) const
{
    if (debug)
    {
        Pout<< "testSyncField : testing synchronisation of Field<Type>."
            << endl;
    }

    Field<Type> syncedFld(fld);

    syncTools::syncPointList
    (
        mesh_,
        syncedFld,
        cop,
        zero
    );

    forAll(syncedFld, i)
    {
        if (mag(syncedFld[i] - fld[i]) > maxMag)
        {
            FatalErrorInFunction
                << "On element " << i << " value:" << fld[i]
                << " synchronised value:" << syncedFld[i]
                << abort(FatalError);
        }
    }
}


// ************************************************************************* //
