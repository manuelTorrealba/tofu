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

#include "finiteVolume/fields/fvPatchFields/derived/movingWallVelocity/movingWallVelocityFvPatchVectorField.hpp"
#include "finiteVolume/fields/volFields/volFields.hpp"
#include "finiteVolume/fields/surfaceFields/surfaceFields.hpp"
#include "finiteVolume/finiteVolume/fvc/fvcMeshPhi.hpp"
#include "OpenFOAM/db/runTimeSelection/construction/addToRunTimeSelectionTable.hpp"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::movingWallVelocityFvPatchVectorField::
movingWallVelocityFvPatchVectorField
(
    const fvPatch& p,
    const DimensionedField<vector, volMesh>& iF
)
:
    fixedValueFvPatchVectorField(p, iF)
{}


Foam::movingWallVelocityFvPatchVectorField::
movingWallVelocityFvPatchVectorField
(
    const fvPatch& p,
    const DimensionedField<vector, volMesh>& iF,
    const dictionary& dict
)
:
    fixedValueFvPatchVectorField(p, iF, dict)
{}


Foam::movingWallVelocityFvPatchVectorField::
movingWallVelocityFvPatchVectorField
(
    const movingWallVelocityFvPatchVectorField& ptf,
    const fvPatch& p,
    const DimensionedField<vector, volMesh>& iF,
    const fvPatchFieldMapper& mapper
)
:
    fixedValueFvPatchVectorField(ptf, p, iF, mapper)
{}


Foam::movingWallVelocityFvPatchVectorField::
movingWallVelocityFvPatchVectorField
(
    const movingWallVelocityFvPatchVectorField& mwvpvf
)
:
    fixedValueFvPatchVectorField(mwvpvf)
{}


Foam::movingWallVelocityFvPatchVectorField::
movingWallVelocityFvPatchVectorField
(
    const movingWallVelocityFvPatchVectorField& mwvpvf,
    const DimensionedField<vector, volMesh>& iF
)
:
    fixedValueFvPatchVectorField(mwvpvf, iF)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void Foam::movingWallVelocityFvPatchVectorField::updateCoeffs()
{
    if (updated())
    {
        return;
    }

    const fvMesh& mesh = internalField().mesh();

    if (mesh.moving())
    {
        const fvPatch& p = patch();
        const polyPatch& pp = p.patch();
        const pointField& oldPoints = mesh.oldPoints();

        vectorField oldFc(pp.size());

        forAll(oldFc, i)
        {
            oldFc[i] = pp[i].centre(oldPoints);
        }

        const scalar deltaT = mesh.time().deltaTValue();

        const vectorField Up((pp.faceCentres() - oldFc)/deltaT);

        const volVectorField& U =
            static_cast<const volVectorField&>(internalField());

        scalarField phip
        (
            p.patchField<surfaceScalarField, scalar>(fvc::meshPhi(U))
        );

        const vectorField n(p.nf());
        const scalarField& magSf = p.magSf();
        tmp<scalarField> Un = phip/(magSf + vSmall);


        vectorField::operator=(Up + n*(Un - (n & Up)));
    }

    fixedValueFvPatchVectorField::updateCoeffs();
}


void Foam::movingWallVelocityFvPatchVectorField::write(Ostream& os) const
{
    fvPatchVectorField::write(os);
    writeEntry("value", os);
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
    makePatchTypeField
    (
        fvPatchVectorField,
        movingWallVelocityFvPatchVectorField
    );
}

// ************************************************************************* //
