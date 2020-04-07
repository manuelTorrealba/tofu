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

#include "thermophysicalModels/solidThermo/solidThermo/makeSolidThermo.hpp"
#include "thermophysicalModels/solidThermo/solidThermo/solidThermo.hpp"
#include "thermophysicalModels/solidThermo/solidThermo/heSolidThermo.hpp"

#include "thermophysicalModels/specie/specie/specie.hpp"
#include "thermophysicalModels/specie/equationOfState/rhoConst/rhoConst.hpp"
#include "thermophysicalModels/specie/thermo/hConst/hConstThermo.hpp"
#include "thermophysicalModels/specie/thermo/hPower/hPowerThermo.hpp"
#include "thermophysicalModels/specie/thermo/hPolynomial/hPolynomialThermo.hpp"
#include "thermophysicalModels/solidSpecie/transport/const/constIsoSolidTransport.hpp"
#include "thermophysicalModels/solidSpecie/transport/const/constAnIsoSolidTransport.hpp"
#include "thermophysicalModels/solidSpecie/transport/exponential/exponentialSolidTransport.hpp"
#include "thermophysicalModels/solidSpecie/transport/polynomial/polynomialSolidTransport.hpp"
#include "thermophysicalModels/basic/mixtures/pureMixture/pureMixture.hpp"
#include "thermophysicalModels/specie/thermo/sensibleEnthalpy/sensibleEnthalpy.hpp"
#include "thermophysicalModels/specie/thermo/sensibleInternalEnergy/sensibleInternalEnergy.hpp"
#include "thermophysicalModels/specie/thermo/thermo/thermo.hpp"

#include "thermophysicalModels/solidSpecie/include/solidThermoPhysicsTypes.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/* * * * * * * * * * * * * * * * * Enthalpy-based * * * * * * * * * * * * * */

makeSolidThermo
(
    solidThermo,
    heSolidThermo,
    pureMixture,
    constIsoSolidTransport,
    sensibleEnthalpy,
    hConstThermo,
    rhoConst,
    specie
);

makeSolidThermo
(
    solidThermo,
    heSolidThermo,
    pureMixture,
    constAnIsoSolidTransport,
    sensibleEnthalpy,
    hConstThermo,
    rhoConst,
    specie
);

makeSolidThermo
(
    solidThermo,
    heSolidThermo,
    pureMixture,
    exponentialSolidTransport,
    sensibleEnthalpy,
    hPowerThermo,
    rhoConst,
    specie
);

makeSolidThermoPhysicsType
(
    solidThermo,
    heSolidThermo,
    pureMixture,
    hTransportThermoPoly8SolidThermoPhysics
);

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //
