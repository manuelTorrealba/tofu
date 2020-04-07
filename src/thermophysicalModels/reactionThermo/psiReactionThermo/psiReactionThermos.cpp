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

#include "thermophysicalModels/reactionThermo/makeReactionThermo.hpp"

#include "thermophysicalModels/reactionThermo/psiReactionThermo/psiReactionThermo.hpp"
#include "thermophysicalModels/basic/psiThermo/hePsiThermo.hpp"

#include "thermophysicalModels/specie/specie/specie.hpp"
#include "thermophysicalModels/specie/equationOfState/perfectGas/perfectGas.hpp"
#include "thermophysicalModels/specie/thermo/hConst/hConstThermo.hpp"
#include "thermophysicalModels/specie/thermo/janaf/janafThermo.hpp"
#include "thermophysicalModels/specie/thermo/sensibleEnthalpy/sensibleEnthalpy.hpp"
#include "thermophysicalModels/specie/thermo/thermo/thermo.hpp"
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

// constTransport, hConstThermo

makeReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    homogeneousMixture,
    constTransport,
    sensibleEnthalpy,
    hConstThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    inhomogeneousMixture,
    constTransport,
    sensibleEnthalpy,
    hConstThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    veryInhomogeneousMixture,
    constTransport,
    sensibleEnthalpy,
    hConstThermo,
    perfectGas,
    specie
);


// sutherlandTransport, hConstThermo

makeReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    homogeneousMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    hConstThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    inhomogeneousMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    hConstThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    veryInhomogeneousMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    hConstThermo,
    perfectGas,
    specie
);


// sutherlandTransport, janafThermo

makeReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    homogeneousMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    janafThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    inhomogeneousMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    janafThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    veryInhomogeneousMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    janafThermo,
    perfectGas,
    specie
);

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

// Multi-component thermo for sensible enthalpy

makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    multiComponentMixture,
    constGasHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    multiComponentMixture,
    gasHThermoPhysics
);


// Multi-component thermo for internal energy

makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    multiComponentMixture,
    constGasEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    multiComponentMixture,
    gasEThermoPhysics
);


// Reaction thermo for sensible enthalpy

makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    reactingMixture,
    constGasHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    reactingMixture,
    gasHThermoPhysics
);


// Single-step reaction thermo for sensible enthalpy

makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    singleStepReactingMixture,
    gasHThermoPhysics
);


// Reaction thermo for internal energy

makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    reactingMixture,
    constGasEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    reactingMixture,
    gasEThermoPhysics
);


// Single-step reaction thermo for internal energy

makeThermoPhysicsReactionThermos
(
    psiThermo,
    psiReactionThermo,
    hePsiThermo,
    singleStepReactingMixture,
    gasEThermoPhysics
);


// Single-component thermo for sensible enthalpy

makeThermoPhysicsReactionThermo
(
    psiReactionThermo,
    hePsiThermo,
    singleComponentMixture,
    constGasHThermoPhysics
);

makeThermoPhysicsReactionThermo
(
    psiReactionThermo,
    hePsiThermo,
    singleComponentMixture,
    gasHThermoPhysics
);


// Single-component thermo for internal energy

makeThermoPhysicsReactionThermo
(
    psiReactionThermo,
    hePsiThermo,
    singleComponentMixture,
    constGasEThermoPhysics
);

makeThermoPhysicsReactionThermo
(
    psiReactionThermo,
    hePsiThermo,
    singleComponentMixture,
    gasEThermoPhysics
);

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //
