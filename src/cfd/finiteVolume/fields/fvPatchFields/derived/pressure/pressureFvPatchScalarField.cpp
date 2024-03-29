/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2018 OpenFOAM Foundation
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

#include "finiteVolume/fields/fvPatchFields/derived/pressure/pressureFvPatchScalarField.hpp"
#include "OpenFOAM/db/runTimeSelection/construction/addToRunTimeSelectionTable.hpp"
#include "finiteVolume/fields/fvPatchFields/fvPatchField/fvPatchFieldMapper.hpp"
#include "finiteVolume/fields/volFields/volFields.hpp"
#include "OpenFOAM/fields/UniformDimensionedFields/uniformDimensionedFields.hpp"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::pressureFvPatchScalarField::pressureFvPatchScalarField
(
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF
)
:
    fixedValueFvPatchScalarField(p, iF),
    p_(p.size(), 0.0)
{}


Foam::pressureFvPatchScalarField::pressureFvPatchScalarField
(
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF,
    const dictionary& dict
)
:
    fixedValueFvPatchScalarField(p, iF, dict, false),
    p_("p", dict, p.size())
{
    if (dict.found("value"))
    {
        fvPatchScalarField::operator=
        (
            scalarField("value", dict, p.size())
        );
    }
    else
    {
        fvPatchField<scalar>::operator=(p_);
    }
}


Foam::pressureFvPatchScalarField::pressureFvPatchScalarField
(
    const pressureFvPatchScalarField& ptf,
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF,
    const fvPatchFieldMapper& mapper
)
:
    fixedValueFvPatchScalarField(ptf, p, iF, mapper),
    p_(ptf.p_, mapper)
{}


Foam::pressureFvPatchScalarField::pressureFvPatchScalarField
(
    const pressureFvPatchScalarField& ptf
)
:
    fixedValueFvPatchScalarField(ptf),
    p_(ptf.p_)
{}


Foam::pressureFvPatchScalarField::pressureFvPatchScalarField
(
    const pressureFvPatchScalarField& ptf,
    const DimensionedField<scalar, volMesh>& iF
)
:
    fixedValueFvPatchScalarField(ptf, iF),
    p_(ptf.p_)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void Foam::pressureFvPatchScalarField::autoMap
(
    const fvPatchFieldMapper& m
)
{
    fixedValueFvPatchScalarField::autoMap(m);
    p_.autoMap(m);
}


void Foam::pressureFvPatchScalarField::rmap
(
    const fvPatchScalarField& ptf,
    const labelList& addr
)
{
    fixedValueFvPatchScalarField::rmap(ptf, addr);

    const pressureFvPatchScalarField& tiptf =
        refCast<const pressureFvPatchScalarField>(ptf);

    p_.rmap(tiptf.p_, addr);
}


void Foam::pressureFvPatchScalarField::updateCoeffs()
{
    if (updated())
    {
        return;
    }

    operator==(p_);

    fixedValueFvPatchScalarField::updateCoeffs();
}


void Foam::pressureFvPatchScalarField::write(Ostream& os) const
{
    fvPatchScalarField::write(os);
    p_.writeEntry("p", os);
    writeEntry("value", os);
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
    makePatchTypeField
    (
        fvPatchScalarField,
        pressureFvPatchScalarField
    );
}

// ************************************************************************* //
