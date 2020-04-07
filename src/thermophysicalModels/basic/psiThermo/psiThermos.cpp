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

#include "thermophysicalModels/basic/psiThermo/psiThermo.hpp"
#include "thermophysicalModels/basic/fluidThermo/makeThermo.hpp"

#include "thermophysicalModels/specie/specie/specie.hpp"
#include "thermophysicalModels/specie/equationOfState/perfectGas/perfectGas.hpp"
#include "thermophysicalModels/specie/equationOfState/PengRobinsonGas/PengRobinsonGas.hpp"
#include "thermophysicalModels/specie/thermo/hConst/hConstThermo.hpp"
#include "thermophysicalModels/specie/thermo/eConst/eConstThermo.hpp"
#include "thermophysicalModels/specie/thermo/janaf/janafThermo.hpp"
#include "thermophysicalModels/specie/thermo/sensibleEnthalpy/sensibleEnthalpy.hpp"
#include "thermophysicalModels/specie/thermo/sensibleInternalEnergy/sensibleInternalEnergy.hpp"
#include "thermophysicalModels/specie/thermo/thermo/thermo.hpp"

#include "thermophysicalModels/specie/transport/const/constTransport.hpp"
#include "thermophysicalModels/specie/transport/sutherland/sutherlandTransport.hpp"

#include "thermophysicalModels/specie/thermo/hPolynomial/hPolynomialThermo.hpp"
#include "thermophysicalModels/specie/transport/polynomial/polynomialTransport.hpp"

#include "thermophysicalModels/basic/psiThermo/hePsiThermo.hpp"
#include "thermophysicalModels/basic/mixtures/pureMixture/pureMixture.hpp"

#include "thermophysicalModels/specie/include/thermoPhysicsTypes.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/* * * * * * * * * * * * * * * * * Enthalpy-based * * * * * * * * * * * * * */

makeThermos
(
    psiThermo,
    hePsiThermo,
    pureMixture,
    constTransport,
    sensibleEnthalpy,
    hConstThermo,
    perfectGas,
    specie
);

makeThermos
(
    psiThermo,
    hePsiThermo,
    pureMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    hConstThermo,
    perfectGas,
    specie
);

makeThermos
(
    psiThermo,
    hePsiThermo,
    pureMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    janafThermo,
    perfectGas,
    specie
);

makeThermos
(
    psiThermo,
    hePsiThermo,
    pureMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    hConstThermo,
    PengRobinsonGas,
    specie
);

makeThermos
(
    psiThermo,
    hePsiThermo,
    pureMixture,
    polynomialTransport,
    sensibleEnthalpy,
    hPolynomialThermo,
    PengRobinsonGas,
    specie
);

makeThermos
(
    psiThermo,
    hePsiThermo,
    pureMixture,
    polynomialTransport,
    sensibleEnthalpy,
    janafThermo,
    PengRobinsonGas,
    specie
);

makeThermos
(
    psiThermo,
    hePsiThermo,
    pureMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    janafThermo,
    PengRobinsonGas,
    specie
);


/* * * * * * * * * * * * * * Internal-energy-based * * * * * * * * * * * * * */

makeThermos
(
    psiThermo,
    hePsiThermo,
    pureMixture,
    constTransport,
    sensibleInternalEnergy,
    eConstThermo,
    perfectGas,
    specie
);

makeThermos
(
    psiThermo,
    hePsiThermo,
    pureMixture,
    sutherlandTransport,
    sensibleInternalEnergy,
    eConstThermo,
    perfectGas,
    specie
);

makeThermos
(
    psiThermo,
    hePsiThermo,
    pureMixture,
    constTransport,
    sensibleInternalEnergy,
    hConstThermo,
    perfectGas,
    specie
);

makeThermos
(
    psiThermo,
    hePsiThermo,
    pureMixture,
    sutherlandTransport,
    sensibleInternalEnergy,
    hConstThermo,
    perfectGas,
    specie
);

makeThermos
(
    psiThermo,
    hePsiThermo,
    pureMixture,
    sutherlandTransport,
    sensibleInternalEnergy,
    janafThermo,
    perfectGas,
    specie
);

makeThermos
(
    psiThermo,
    hePsiThermo,
    pureMixture,
    sutherlandTransport,
    sensibleInternalEnergy,
    janafThermo,
    PengRobinsonGas,
    specie
);


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //
