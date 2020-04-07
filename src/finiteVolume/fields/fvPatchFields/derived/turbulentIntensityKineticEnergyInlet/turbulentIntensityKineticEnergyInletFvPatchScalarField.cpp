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

#include "finiteVolume/fields/fvPatchFields/derived/turbulentIntensityKineticEnergyInlet/turbulentIntensityKineticEnergyInletFvPatchScalarField.hpp"
#include "OpenFOAM/db/runTimeSelection/construction/addToRunTimeSelectionTable.hpp"
#include "finiteVolume/fields/fvPatchFields/fvPatchField/fvPatchFieldMapper.hpp"
#include "finiteVolume/fields/surfaceFields/surfaceFields.hpp"
#include "finiteVolume/fields/volFields/volFields.hpp"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::turbulentIntensityKineticEnergyInletFvPatchScalarField::
turbulentIntensityKineticEnergyInletFvPatchScalarField
(
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF
)
:
    inletOutletFvPatchScalarField(p, iF),
    intensity_(0.0),
    UName_("U")
{
    this->refValue() = 0.0;
    this->refGrad() = 0.0;
    this->valueFraction() = 0.0;
}

Foam::turbulentIntensityKineticEnergyInletFvPatchScalarField::
turbulentIntensityKineticEnergyInletFvPatchScalarField
(
    const turbulentIntensityKineticEnergyInletFvPatchScalarField& ptf,
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF,
    const fvPatchFieldMapper& mapper
)
:
    inletOutletFvPatchScalarField(ptf, p, iF, mapper),
    intensity_(ptf.intensity_),
    UName_(ptf.UName_)
{}

Foam::turbulentIntensityKineticEnergyInletFvPatchScalarField::
turbulentIntensityKineticEnergyInletFvPatchScalarField
(
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF,
    const dictionary& dict
)
:
    inletOutletFvPatchScalarField(p, iF),
    intensity_(readScalar(dict.lookup("intensity"))),
    UName_(dict.lookupOrDefault<word>("U", "U"))
{
    this->phiName_ = dict.lookupOrDefault<word>("phi", "phi");

    if (intensity_ < 0 || intensity_ > 1)
    {
        FatalErrorInFunction
            << "Turbulence intensity should be specified as a fraction 0-1 "
               "of the mean velocity\n"
               "    value given is " << intensity_ << nl
            << "    on patch " << this->patch().name()
            << " of field " << this->internalField().name()
            << " in file " << this->internalField().objectPath()
            << exit(FatalError);
    }

    fvPatchScalarField::operator=(scalarField("value", dict, p.size()));

    this->refValue() = 0.0;
    this->refGrad() = 0.0;
    this->valueFraction() = 0.0;
}

Foam::turbulentIntensityKineticEnergyInletFvPatchScalarField::
turbulentIntensityKineticEnergyInletFvPatchScalarField
(
    const turbulentIntensityKineticEnergyInletFvPatchScalarField& ptf
)
:
    inletOutletFvPatchScalarField(ptf),
    intensity_(ptf.intensity_),
    UName_(ptf.UName_)
{}


Foam::turbulentIntensityKineticEnergyInletFvPatchScalarField::
turbulentIntensityKineticEnergyInletFvPatchScalarField
(
    const turbulentIntensityKineticEnergyInletFvPatchScalarField& ptf,
    const DimensionedField<scalar, volMesh>& iF
)
:
    inletOutletFvPatchScalarField(ptf, iF),
    intensity_(ptf.intensity_),
    UName_(ptf.UName_)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void Foam::turbulentIntensityKineticEnergyInletFvPatchScalarField::
updateCoeffs()
{
    if (updated())
    {
        return;
    }

    const fvPatchVectorField& Up =
        patch().lookupPatchField<volVectorField, vector>(UName_);

    const fvsPatchScalarField& phip =
        patch().lookupPatchField<surfaceScalarField, scalar>(this->phiName_);

    this->refValue() = 1.5*sqr(intensity_)*magSqr(Up);
    this->valueFraction() = 1.0 - pos0(phip);

    inletOutletFvPatchScalarField::updateCoeffs();
}


void Foam::turbulentIntensityKineticEnergyInletFvPatchScalarField::write
(
    Ostream& os
) const
{
    fvPatchScalarField::write(os);
    os.writeKeyword("intensity") << intensity_ << token::END_STATEMENT << nl;
    writeEntryIfDifferent<word>(os, "U", "U", UName_);
    writeEntryIfDifferent<word>(os, "phi", "phi", this->phiName_);
    writeEntry("value", os);
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
    makePatchTypeField
    (
        fvPatchScalarField,
        turbulentIntensityKineticEnergyInletFvPatchScalarField
    );
}

// ************************************************************************* //
