/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2016-2018 OpenFOAM Foundation
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

#include "finiteVolume/cfdTools/general/constrainHbyA/constrainHbyA.hpp"
#include "finiteVolume/fields/volFields/volFields.hpp"
#include "finiteVolume/fields/fvPatchFields/derived/fixedFluxExtrapolatedPressure/fixedFluxExtrapolatedPressureFvPatchScalarField.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

Foam::tmp<Foam::volVectorField> Foam::constrainHbyA
(
    const tmp<volVectorField>& tHbyA,
    const volVectorField& U,
    const volScalarField& p
)
{
    tmp<volVectorField> tHbyANew;

    if (tHbyA.isTmp())
    {
        tHbyANew = tHbyA;
        tHbyANew.ref().rename("HbyA");
    }
    else
    {
        tHbyANew = new volVectorField("HbyA", tHbyA);
    }

    volVectorField& HbyA = tHbyANew.ref();
    volVectorField::Boundary& HbyAbf = HbyA.boundaryFieldRef();

    forAll(U.boundaryField(), patchi)
    {
        if
        (
           !U.boundaryField()[patchi].assignable()
        && !isA<fixedFluxExtrapolatedPressureFvPatchScalarField>
            (
                p.boundaryField()[patchi]
            )
        )
        {
            HbyAbf[patchi] = U.boundaryField()[patchi];
        }
    }

    return tHbyANew;
}


// ************************************************************************* //
