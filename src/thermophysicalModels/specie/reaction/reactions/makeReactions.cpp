/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2012-2018 OpenFOAM Foundation
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

#include "thermophysicalModels/specie/include/reactionTypes.hpp"
#include "thermophysicalModels/specie/reaction/reactions/makeReaction.hpp"

#include "thermophysicalModels/specie/reaction/reactionRate/ArrheniusReactionRate/ArrheniusReactionRate.hpp"
#include "thermophysicalModels/specie/reaction/reactionRate/infiniteReactionRate/infiniteReactionRate.hpp"
#include "thermophysicalModels/specie/reaction/reactionRate/LandauTellerReactionRate/LandauTellerReactionRate.hpp"
#include "thermophysicalModels/specie/reaction/reactionRate/thirdBodyArrheniusReactionRate/thirdBodyArrheniusReactionRate.hpp"

#include "thermophysicalModels/specie/reaction/reactionRate/ChemicallyActivatedReactionRate/ChemicallyActivatedReactionRate.hpp"
#include "thermophysicalModels/specie/reaction/reactionRate/JanevReactionRate/JanevReactionRate.hpp"
#include "thermophysicalModels/specie/reaction/reactionRate/powerSeries/powerSeriesReactionRate.hpp"

#include "thermophysicalModels/specie/reaction/reactionRate/FallOffReactionRate/FallOffReactionRate.hpp"
#include "thermophysicalModels/specie/reaction/reactionRate/fallOffFunctions/LindemannFallOffFunction/LindemannFallOffFunction.hpp"
#include "thermophysicalModels/specie/reaction/reactionRate/fallOffFunctions/SRIFallOffFunction/SRIFallOffFunction.hpp"
#include "thermophysicalModels/specie/reaction/reactionRate/fallOffFunctions/TroeFallOffFunction/TroeFallOffFunction.hpp"


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define makeReactions(Thermo, Reaction)                                        \
                                                                               \
    defineTemplateTypeNameAndDebug(Reaction, 0);                               \
    defineTemplateRunTimeSelectionTable(Reaction, dictionary);                 \
                                                                               \
    makeIRNReactions(Thermo, ArrheniusReactionRate)                            \
    makeIRNReactions(Thermo, infiniteReactionRate)                             \
    makeIRNReactions(Thermo, LandauTellerReactionRate)                         \
    makeIRNReactions(Thermo, thirdBodyArrheniusReactionRate)                   \
                                                                               \
    makeIRReactions(Thermo, JanevReactionRate)                                 \
    makeIRReactions(Thermo, powerSeriesReactionRate)                           \
                                                                               \
    makePressureDependentReactions                                             \
    (                                                                          \
       Thermo,                                                                 \
       ArrheniusReactionRate,                                                  \
       LindemannFallOffFunction                                                \
    )                                                                          \
                                                                               \
    makePressureDependentReactions                                             \
    (                                                                          \
       Thermo,                                                                 \
       ArrheniusReactionRate,                                                  \
       TroeFallOffFunction                                                     \
    )                                                                          \
                                                                               \
    makePressureDependentReactions                                             \
    (                                                                          \
       Thermo,                                                                 \
       ArrheniusReactionRate,                                                  \
       SRIFallOffFunction                                                      \
    )


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
    // sensible enthalpy based reactions
    makeReactions(constGasHThermoPhysics, constGasHReaction)
    makeReactions(gasHThermoPhysics, gasHReaction)
    makeReactions
    (
        constIncompressibleGasHThermoPhysics,
        constIncompressibleGasHReaction
    )
    makeReactions(incompressibleGasHThermoPhysics, incompressibleGasHReaction)
    makeReactions(icoPoly8HThermoPhysics, icoPoly8HReaction)
    makeReactions(constFluidHThermoPhysics, constFluidHReaction)
    makeReactions
    (
        constAdiabaticFluidHThermoPhysics,
        constAdiabaticFluidHReaction
    )
    makeReactions(constHThermoPhysics, constHReaction)

    makeReactions(constGasEThermoPhysics, constGasEReaction)
    makeReactions(gasEThermoPhysics, gasEReaction)
    makeReactions
    (
        constIncompressibleGasEThermoPhysics,
        constIncompressibleGasEReaction
    )
    makeReactions(incompressibleGasEThermoPhysics, incompressibleGasEReaction)
    makeReactions(icoPoly8EThermoPhysics, icoPoly8EReaction)
    makeReactions(constFluidEThermoPhysics, constFluidEReaction)
    makeReactions
    (
        constAdiabaticFluidEThermoPhysics,
        constAdiabaticFluidEReaction
    )
    makeReactions(constEThermoPhysics, constEReaction)
}

// ************************************************************************* //
