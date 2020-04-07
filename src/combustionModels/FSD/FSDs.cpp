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

#include "combustionModels/combustionModel/makeCombustionTypes.hpp"

#include "thermophysicalModels/specie/include/thermoPhysicsTypes.hpp"
#include "thermophysicalModels/reactionThermo/psiReactionThermo/psiReactionThermo.hpp"
#include "thermophysicalModels/reactionThermo/rhoReactionThermo/rhoReactionThermo.hpp"
#include "combustionModels/FSD/FSD.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Combustion models based on sensibleEnthalpy
makeCombustionTypesThermo
(
    FSD,
    psiReactionThermo,
    gasHThermoPhysics
);

makeCombustionTypesThermo
(
    FSD,
    psiReactionThermo,
    constGasHThermoPhysics
);

makeCombustionTypesThermo
(
    FSD,
    rhoReactionThermo,
    gasHThermoPhysics
);

makeCombustionTypesThermo
(
    FSD,
    rhoReactionThermo,
    constGasHThermoPhysics
);

// Combustion models based on sensibleInternalEnergy
makeCombustionTypesThermo
(
    FSD,
    psiReactionThermo,
    gasEThermoPhysics
);

makeCombustionTypesThermo
(
    FSD,
    psiReactionThermo,
    constGasEThermoPhysics
);

makeCombustionTypesThermo
(
    FSD,
    rhoReactionThermo,
    gasEThermoPhysics
);

makeCombustionTypesThermo
(
    FSD,
    rhoReactionThermo,
    constGasEThermoPhysics
);

}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
