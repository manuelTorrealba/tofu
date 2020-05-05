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

#include "lagrangian/intermediate/integrationScheme/analytical/analytical.hpp"
#include "OpenFOAM/db/runTimeSelection/construction/addToRunTimeSelectionTable.hpp"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace integrationSchemes
{
    defineTypeNameAndDebug(analytical, 0);
    addToRunTimeSelectionTable(integrationScheme, analytical, word);
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::integrationSchemes::analytical::analytical()
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::integrationSchemes::analytical::~analytical()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::scalar Foam::integrationSchemes::analytical::dtEff
(
    const scalar dt,
    const scalar Beta
) const
{
    return
        mag(Beta*dt) > small
      ? (1 - exp(- Beta*dt))/Beta
      : dt;
}


Foam::scalar Foam::integrationSchemes::analytical::sumDtEff
(
    const scalar dt,
    const scalar Beta
) const
{
    return
        mag(Beta*dt) > small
      ? dt/Beta - (1 - exp(- Beta*dt))/sqr(Beta)
      : sqr(dt);
}


// ************************************************************************* //