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

#include "thermophysicalModels/reactionThermo/derivedFvPatchFields/mixedUnburntEnthalpy/mixedUnburntEnthalpyFvPatchScalarField.hpp"
#include "OpenFOAM/db/runTimeSelection/construction/addToRunTimeSelectionTable.hpp"
#include "finiteVolume/fields/fvPatchFields/fvPatchField/fvPatchFieldMapper.hpp"
#include "finiteVolume/fields/volFields/volFields.hpp"
#include "thermophysicalModels/reactionThermo/psiuReactionThermo/psiuReactionThermo.hpp"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::mixedUnburntEnthalpyFvPatchScalarField::
mixedUnburntEnthalpyFvPatchScalarField
(
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF
)
:
    mixedFvPatchScalarField(p, iF)
{
    valueFraction() = 0.0;
    refValue() = 0.0;
    refGrad() = 0.0;
}


Foam::mixedUnburntEnthalpyFvPatchScalarField::
mixedUnburntEnthalpyFvPatchScalarField
(
    const mixedUnburntEnthalpyFvPatchScalarField& ptf,
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF,
    const fvPatchFieldMapper& mapper
)
:
    mixedFvPatchScalarField(ptf, p, iF, mapper)
{}


Foam::mixedUnburntEnthalpyFvPatchScalarField::
mixedUnburntEnthalpyFvPatchScalarField
(
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF,
    const dictionary& dict
)
:
    mixedFvPatchScalarField(p, iF, dict)
{}


Foam::mixedUnburntEnthalpyFvPatchScalarField::
mixedUnburntEnthalpyFvPatchScalarField
(
    const mixedUnburntEnthalpyFvPatchScalarField& tppsf
)
:
    mixedFvPatchScalarField(tppsf)
{}


Foam::mixedUnburntEnthalpyFvPatchScalarField::
mixedUnburntEnthalpyFvPatchScalarField
(
    const mixedUnburntEnthalpyFvPatchScalarField& tppsf,
    const DimensionedField<scalar, volMesh>& iF
)
:
    mixedFvPatchScalarField(tppsf, iF)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void Foam::mixedUnburntEnthalpyFvPatchScalarField::updateCoeffs()
{
    if (updated())
    {
        return;
    }

    const psiuReactionThermo& thermo = db().lookupObject<psiuReactionThermo>
    (
        basicThermo::dictName
    );

    const label patchi = patch().index();

    const scalarField& pw = thermo.p().boundaryField()[patchi];
    mixedFvPatchScalarField& Tw = refCast<mixedFvPatchScalarField>
    (
        const_cast<fvPatchScalarField&>(thermo.Tu().boundaryField()[patchi])
    );

    Tw.evaluate();

    valueFraction() = Tw.valueFraction();
    refValue() = thermo.heu(pw, Tw.refValue(), patchi);
    refGrad() = thermo.Cp(pw, Tw, patchi)*Tw.refGrad()
      + patch().deltaCoeffs()*
        (
            thermo.heu(pw, Tw, patchi)
          - thermo.heu(pw, Tw, patch().faceCells())
        );

    mixedFvPatchScalarField::updateCoeffs();
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
    makePatchTypeField
    (
        fvPatchScalarField,
        mixedUnburntEnthalpyFvPatchScalarField
    );
}

// ************************************************************************* //
