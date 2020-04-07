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

#include "functionObjects/field/PecletNo/PecletNo.hpp"
#include "TurbulenceModels/turbulenceModels/turbulenceModel.hpp"
#include "functionObjects/field/surfaceInterpolate/surfaceInterpolate.hpp"
#include "OpenFOAM/db/runTimeSelection/construction/addToRunTimeSelectionTable.hpp"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace functionObjects
{
    defineTypeNameAndDebug(PecletNo, 0);

    addToRunTimeSelectionTable
    (
        functionObject,
        PecletNo,
        dictionary
    );
}
}


// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //

bool Foam::functionObjects::PecletNo::calc()
{
    if (foundObject<surfaceScalarField>(fieldName_))
    {
        tmp<volScalarField> nuEff
        (
            mesh_.lookupObject<turbulenceModel>
            (
                turbulenceModel::propertiesName
            ).nuEff()
        );

        const surfaceScalarField& phi =
            mesh_.lookupObject<surfaceScalarField>(fieldName_);

        return store
        (
            resultName_,
            mag(phi)
           /(
                mesh_.magSf()
               *mesh_.surfaceInterpolation::deltaCoeffs()
               *fvc::interpolate(nuEff)
            )
        );
    }
    else
    {
        return false;
    }
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::functionObjects::PecletNo::PecletNo
(
    const word& name,
    const Time& runTime,
    const dictionary& dict
)
:
    fieldExpression(name, runTime, dict, "phi")
{
    setResultName("Pe", "phi");
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::functionObjects::PecletNo::~PecletNo()
{}


// ************************************************************************* //
