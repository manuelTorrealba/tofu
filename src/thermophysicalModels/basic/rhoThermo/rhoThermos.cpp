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

#include "thermophysicalModels/basic/rhoThermo/rhoThermo.hpp"
#include "thermophysicalModels/basic/fluidThermo/makeThermo.hpp"

#include "thermophysicalModels/specie/specie/specie.hpp"
#include "thermophysicalModels/specie/equationOfState/perfectGas/perfectGas.hpp"
#include "thermophysicalModels/specie/equationOfState/incompressiblePerfectGas/incompressiblePerfectGas.hpp"
#include "thermophysicalModels/specie/equationOfState/Boussinesq/Boussinesq.hpp"
#include "thermophysicalModels/specie/equationOfState/rhoConst/rhoConst.hpp"
#include "thermophysicalModels/specie/equationOfState/perfectFluid/perfectFluid.hpp"
#include "thermophysicalModels/specie/equationOfState/PengRobinsonGas/PengRobinsonGas.hpp"
#include "thermophysicalModels/specie/equationOfState/adiabaticPerfectFluid/adiabaticPerfectFluid.hpp"

#include "thermophysicalModels/specie/thermo/hConst/hConstThermo.hpp"
#include "thermophysicalModels/specie/thermo/janaf/janafThermo.hpp"
#include "thermophysicalModels/specie/thermo/sensibleEnthalpy/sensibleEnthalpy.hpp"
#include "thermophysicalModels/specie/thermo/sensibleInternalEnergy/sensibleInternalEnergy.hpp"
#include "thermophysicalModels/specie/thermo/thermo/thermo.hpp"

#include "thermophysicalModels/specie/transport/const/constTransport.hpp"
#include "thermophysicalModels/specie/transport/sutherland/sutherlandTransport.hpp"

#include "thermophysicalModels/specie/equationOfState/icoPolynomial/icoPolynomial.hpp"
#include "thermophysicalModels/specie/thermo/hPolynomial/hPolynomialThermo.hpp"
#include "thermophysicalModels/specie/transport/polynomial/polynomialTransport.hpp"

#include "thermophysicalModels/basic/rhoThermo/heRhoThermo.hpp"
#include "thermophysicalModels/basic/mixtures/pureMixture/pureMixture.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/* * * * * * * * * * * * * * * private static data * * * * * * * * * * * * * */

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    constTransport,
    sensibleEnthalpy,
    hConstThermo,
    perfectGas,
    specie
);

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    hConstThermo,
    perfectGas,
    specie
);

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    janafThermo,
    perfectGas,
    specie
);

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    constTransport,
    sensibleEnthalpy,
    hConstThermo,
    rhoConst,
    specie
);

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    constTransport,
    sensibleEnthalpy,
    hConstThermo,
    perfectFluid,
    specie
);

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    constTransport,
    sensibleEnthalpy,
    hConstThermo,
    adiabaticPerfectFluid,
    specie
);

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    polynomialTransport,
    sensibleEnthalpy,
    hPolynomialThermo,
    icoPolynomial,
    specie
);

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    constTransport,
    sensibleEnthalpy,
    hConstThermo,
    incompressiblePerfectGas,
    specie
);

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    hConstThermo,
    incompressiblePerfectGas,
    specie
);

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    janafThermo,
    incompressiblePerfectGas,
    specie
);

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    constTransport,
    sensibleEnthalpy,
    hConstThermo,
    Boussinesq,
    specie
);

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    hConstThermo,
    Boussinesq,
    specie
);

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    janafThermo,
    Boussinesq,
    specie
);

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    sutherlandTransport,
    sensibleEnthalpy,
    hConstThermo,
    PengRobinsonGas,
    specie
);

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    polynomialTransport,
    sensibleEnthalpy,
    hPolynomialThermo,
    PengRobinsonGas,
    specie
);

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    polynomialTransport,
    sensibleEnthalpy,
    janafThermo,
    PengRobinsonGas,
    specie
);

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    constTransport,
    sensibleInternalEnergy,
    hConstThermo,
    perfectGas,
    specie
);

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    sutherlandTransport,
    sensibleInternalEnergy,
    hConstThermo,
    perfectGas,
    specie
);

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    sutherlandTransport,
    sensibleInternalEnergy,
    janafThermo,
    perfectGas,
    specie
);

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    constTransport,
    sensibleInternalEnergy,
    hConstThermo,
    rhoConst,
    specie
);

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    constTransport,
    sensibleInternalEnergy,
    hConstThermo,
    perfectFluid,
    specie
);

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    constTransport,
    sensibleInternalEnergy,
    hConstThermo,
    adiabaticPerfectFluid,
    specie
);

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    polynomialTransport,
    sensibleInternalEnergy,
    hPolynomialThermo,
    icoPolynomial,
    specie
);

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    constTransport,
    sensibleInternalEnergy,
    hConstThermo,
    incompressiblePerfectGas,
    specie
);

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    sutherlandTransport,
    sensibleInternalEnergy,
    hConstThermo,
    incompressiblePerfectGas,
    specie
);

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    sutherlandTransport,
    sensibleInternalEnergy,
    janafThermo,
    incompressiblePerfectGas,
    specie
);

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    constTransport,
    sensibleInternalEnergy,
    hConstThermo,
    Boussinesq,
    specie
);

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    sutherlandTransport,
    sensibleInternalEnergy,
    hConstThermo,
    Boussinesq,
    specie
);

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    sutherlandTransport,
    sensibleInternalEnergy,
    janafThermo,
    Boussinesq,
    specie
);


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //
