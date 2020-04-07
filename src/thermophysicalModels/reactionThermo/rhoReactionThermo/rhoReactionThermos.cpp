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

#include "thermophysicalModels/reactionThermo/makeReactionThermo.hpp"

#include "thermophysicalModels/reactionThermo/rhoReactionThermo/rhoReactionThermo.hpp"
#include "thermophysicalModels/basic/rhoThermo/heRhoThermo.hpp"

#include "thermophysicalModels/specie/specie/specie.hpp"
#include "thermophysicalModels/specie/equationOfState/perfectGas/perfectGas.hpp"
#include "thermophysicalModels/specie/equationOfState/incompressiblePerfectGas/incompressiblePerfectGas.hpp"
#include "thermophysicalModels/specie/thermo/hConst/hConstThermo.hpp"
#include "thermophysicalModels/specie/thermo/janaf/janafThermo.hpp"
#include "thermophysicalModels/specie/thermo/sensibleEnthalpy/sensibleEnthalpy.hpp"
#include "thermophysicalModels/specie/thermo/thermo/thermo.hpp"
#include "thermophysicalModels/specie/equationOfState/rhoConst/rhoConst.hpp"
#include "thermophysicalModels/specie/equationOfState/perfectFluid/perfectFluid.hpp"
#include "thermophysicalModels/specie/equationOfState/adiabaticPerfectFluid/adiabaticPerfectFluid.hpp"
#include "thermophysicalModels/specie/equationOfState/Boussinesq/Boussinesq.hpp"

#include "thermophysicalModels/specie/transport/const/constTransport.hpp"
#include "thermophysicalModels/specie/transport/sutherland/sutherlandTransport.hpp"

#include "thermophysicalModels/reactionThermo/mixtures/homogeneousMixture/homogeneousMixture.hpp"
#include "thermophysicalModels/reactionThermo/mixtures/inhomogeneousMixture/inhomogeneousMixture.hpp"
#include "thermophysicalModels/reactionThermo/mixtures/veryInhomogeneousMixture/veryInhomogeneousMixture.hpp"
#include "thermophysicalModels/reactionThermo/mixtures/multiComponentMixture/multiComponentMixture.hpp"
#include "thermophysicalModels/reactionThermo/mixtures/reactingMixture/reactingMixture.hpp"
#include "thermophysicalModels/reactionThermo/mixtures/singleStepReactingMixture/singleStepReactingMixture.hpp"
#include "thermophysicalModels/reactionThermo/mixtures/singleComponentMixture/singleComponentMixture.hpp"

#include "thermophysicalModels/specie/include/thermoPhysicsTypes.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

makeReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    homogeneousMixture,
    constTransport,
    sensibleEnthalpy,
    hConstThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    inhomogeneousMixture,
    constTransport,
    sensibleEnthalpy,
    hConstThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    veryInhomogeneousMixture,
    constTransport,
    sensibleEnthalpy,
    hConstThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    homogeneousMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    janafThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    inhomogeneousMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    janafThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    veryInhomogeneousMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    janafThermo,
    perfectGas,
    specie
);


makeReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    homogeneousMixture,
    constTransport,
    sensibleEnthalpy,
    hConstThermo,
    incompressiblePerfectGas,
    specie
);

makeReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    inhomogeneousMixture,
    constTransport,
    sensibleEnthalpy,
    hConstThermo,
    incompressiblePerfectGas,
    specie
);

makeReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    veryInhomogeneousMixture,
    constTransport,
    sensibleEnthalpy,
    hConstThermo,
    incompressiblePerfectGas,
    specie
);

makeReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    homogeneousMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    janafThermo,
    incompressiblePerfectGas,
    specie
);

makeReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    inhomogeneousMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    janafThermo,
    incompressiblePerfectGas,
    specie
);

makeReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    veryInhomogeneousMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    janafThermo,
    incompressiblePerfectGas,
    specie
);

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

// Multi-component thermo for internal energy

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    constGasEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    gasEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    constIncompressibleGasEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    incompressibleGasEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    icoPoly8EThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    constFluidEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    constAdiabaticFluidEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    constEThermoPhysics
);


// Reaction thermo for internal energy

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    constGasEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    gasEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    constIncompressibleGasEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    incompressibleGasEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    icoPoly8EThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    constFluidEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    constAdiabaticFluidEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    constEThermoPhysics
);


// Single-step reaction thermo for internal energy

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    singleStepReactingMixture,
    gasEThermoPhysics
);


// Single-component thermo for internal energy

makeThermoPhysicsReactionThermo
(
    rhoReactionThermo,
    heRhoThermo,
    singleComponentMixture,
    constGasEThermoPhysics
);

makeThermoPhysicsReactionThermo
(
    rhoReactionThermo,
    heRhoThermo,
    singleComponentMixture,
    gasEThermoPhysics
);

makeThermoPhysicsReactionThermo
(
    rhoReactionThermo,
    heRhoThermo,
    singleComponentMixture,
    constIncompressibleGasEThermoPhysics
);

makeThermoPhysicsReactionThermo
(
    rhoReactionThermo,
    heRhoThermo,
    singleComponentMixture,
    incompressibleGasEThermoPhysics
);

makeThermoPhysicsReactionThermo
(
    rhoReactionThermo,
    heRhoThermo,
    singleComponentMixture,
    icoPoly8EThermoPhysics
);

makeThermoPhysicsReactionThermo
(
    rhoReactionThermo,
    heRhoThermo,
    singleComponentMixture,
    constFluidEThermoPhysics
);

makeThermoPhysicsReactionThermo
(
    rhoReactionThermo,
    heRhoThermo,
    singleComponentMixture,
    constAdiabaticFluidEThermoPhysics
);

makeThermoPhysicsReactionThermo
(
    rhoReactionThermo,
    heRhoThermo,
    singleComponentMixture,
    constEThermoPhysics
);

makeReactionThermo
(
    rhoReactionThermo,
    heRhoThermo,
    singleComponentMixture,
    constTransport,
    sensibleInternalEnergy,
    hConstThermo,
    Boussinesq,
    specie
);

makeReactionThermo
(
    rhoReactionThermo,
    heRhoThermo,
    singleComponentMixture,
    sutherlandTransport,
    sensibleInternalEnergy,
    janafThermo,
    Boussinesq,
    specie
);



// Multi-component thermo for sensible enthalpy

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    constGasHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    gasHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    constIncompressibleGasHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    incompressibleGasHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    icoPoly8HThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    constFluidHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    constAdiabaticFluidHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    constHThermoPhysics
);


// Reaction thermo for sensible enthalpy

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    constGasHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    gasHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    constIncompressibleGasHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    incompressibleGasHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    icoPoly8HThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    constFluidHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    constAdiabaticFluidHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    constHThermoPhysics
);


// Single-step reaction thermo for sensible enthalpy

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    singleStepReactingMixture,
    gasHThermoPhysics
);


// Single-component thermo for sensible enthalpy

makeThermoPhysicsReactionThermo
(
    rhoReactionThermo,
    heRhoThermo,
    singleComponentMixture,
    constGasHThermoPhysics
);

makeThermoPhysicsReactionThermo
(
    rhoReactionThermo,
    heRhoThermo,
    singleComponentMixture,
    gasHThermoPhysics
);

makeThermoPhysicsReactionThermo
(
    rhoReactionThermo,
    heRhoThermo,
    singleComponentMixture,
    constIncompressibleGasHThermoPhysics
);

makeThermoPhysicsReactionThermo
(
    rhoReactionThermo,
    heRhoThermo,
    singleComponentMixture,
    incompressibleGasHThermoPhysics
);

makeThermoPhysicsReactionThermo
(
    rhoReactionThermo,
    heRhoThermo,
    singleComponentMixture,
    icoPoly8HThermoPhysics
);

makeThermoPhysicsReactionThermo
(
    rhoReactionThermo,
    heRhoThermo,
    singleComponentMixture,
    constFluidHThermoPhysics
);

makeThermoPhysicsReactionThermo
(
    rhoReactionThermo,
    heRhoThermo,
    singleComponentMixture,
    constAdiabaticFluidHThermoPhysics
);

makeThermoPhysicsReactionThermo
(
    rhoReactionThermo,
    heRhoThermo,
    singleComponentMixture,
    constHThermoPhysics
);

makeReactionThermo
(
    rhoReactionThermo,
    heRhoThermo,
    singleComponentMixture,
    constTransport,
    sensibleEnthalpy,
    hConstThermo,
    Boussinesq,
    specie
);

makeReactionThermo
(
    rhoReactionThermo,
    heRhoThermo,
    singleComponentMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    janafThermo,
    Boussinesq,
    specie
);

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //
