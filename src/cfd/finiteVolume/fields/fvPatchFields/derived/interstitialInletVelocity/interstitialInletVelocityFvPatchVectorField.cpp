/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2013-2018 OpenFOAM Foundation
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

#include "finiteVolume/fields/fvPatchFields/derived/interstitialInletVelocity/interstitialInletVelocityFvPatchVectorField.hpp"
#include "finiteVolume/fields/volFields/volFields.hpp"
#include "OpenFOAM/db/runTimeSelection/construction/addToRunTimeSelectionTable.hpp"
#include "finiteVolume/fields/fvPatchFields/fvPatchField/fvPatchFieldMapper.hpp"
#include "finiteVolume/fields/surfaceFields/surfaceFields.hpp"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::interstitialInletVelocityFvPatchVectorField::
interstitialInletVelocityFvPatchVectorField
(
    const fvPatch& p,
    const DimensionedField<vector, volMesh>& iF
)
:
    fixedValueFvPatchVectorField(p, iF),
    inletVelocity_(p.size(), Zero),
    alphaName_("alpha")
{}


Foam::interstitialInletVelocityFvPatchVectorField::
interstitialInletVelocityFvPatchVectorField
(
    const interstitialInletVelocityFvPatchVectorField& ptf,
    const fvPatch& p,
    const DimensionedField<vector, volMesh>& iF,
    const fvPatchFieldMapper& mapper
)
:
    fixedValueFvPatchVectorField(ptf, p, iF, mapper),
    inletVelocity_(ptf.inletVelocity_, mapper),
    alphaName_(ptf.alphaName_)
{}


Foam::interstitialInletVelocityFvPatchVectorField::
interstitialInletVelocityFvPatchVectorField
(
    const fvPatch& p,
    const DimensionedField<vector, volMesh>& iF,
    const dictionary& dict
)
:
    fixedValueFvPatchVectorField(p, iF, dict),
    inletVelocity_("inletVelocity", dict, p.size()),
    alphaName_(dict.lookupOrDefault<word>("alpha", "alpha"))
{}


Foam::interstitialInletVelocityFvPatchVectorField::
interstitialInletVelocityFvPatchVectorField
(
    const interstitialInletVelocityFvPatchVectorField& ptf
)
:
    fixedValueFvPatchVectorField(ptf),
    inletVelocity_(ptf.inletVelocity_),
    alphaName_(ptf.alphaName_)
{}


Foam::interstitialInletVelocityFvPatchVectorField::
interstitialInletVelocityFvPatchVectorField
(
    const interstitialInletVelocityFvPatchVectorField& ptf,
    const DimensionedField<vector, volMesh>& iF
)
:
    fixedValueFvPatchVectorField(ptf, iF),
    inletVelocity_(ptf.inletVelocity_),
    alphaName_(ptf.alphaName_)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void Foam::interstitialInletVelocityFvPatchVectorField::autoMap
(
    const fvPatchFieldMapper& m
)
{
    fixedValueFvPatchVectorField::autoMap(m);
    inletVelocity_.autoMap(m);
}


void Foam::interstitialInletVelocityFvPatchVectorField::rmap
(
    const fvPatchVectorField& ptf,
    const labelList& addr
)
{
    fixedValueFvPatchVectorField::rmap(ptf, addr);

    const interstitialInletVelocityFvPatchVectorField& tiptf =
        refCast<const interstitialInletVelocityFvPatchVectorField>(ptf);

    inletVelocity_.rmap(tiptf.inletVelocity_, addr);
}


void Foam::interstitialInletVelocityFvPatchVectorField::updateCoeffs()
{
    if (updated())
    {
        return;
    }

    const fvPatchField<scalar>& alphap =
        patch().lookupPatchField<volScalarField, scalar>(alphaName_);

    operator==(inletVelocity_/alphap);
    fixedValueFvPatchVectorField::updateCoeffs();
}


void Foam::interstitialInletVelocityFvPatchVectorField::write(Ostream& os) const
{
    fvPatchField<vector>::write(os);
    writeEntryIfDifferent<word>(os, "alpha", "alpha", alphaName_);
    inletVelocity_.writeEntry("inletVelocity", os);
    writeEntry("value", os);
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
   makePatchTypeField
   (
       fvPatchVectorField,
       interstitialInletVelocityFvPatchVectorField
   );
}


// ************************************************************************* //
