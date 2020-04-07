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

#include "thermophysicalModels/solidThermo/solidReactionThermo/makeReactingSolidThermo.hpp"
#include "thermophysicalModels/solidThermo/solidReactionThermo/solidReactionThermo.hpp"
#include "thermophysicalModels/solidThermo/solidThermo/heSolidThermo.hpp"

#include "thermophysicalModels/specie/specie/specie.hpp"
#include "thermophysicalModels/specie/equationOfState/rhoConst/rhoConst.hpp"
#include "thermophysicalModels/specie/thermo/hConst/hConstThermo.hpp"
#include "thermophysicalModels/specie/thermo/hPower/hPowerThermo.hpp"
#include "thermophysicalModels/solidSpecie/transport/const/constIsoSolidTransport.hpp"
#include "thermophysicalModels/solidSpecie/transport/const/constAnIsoSolidTransport.hpp"
#include "thermophysicalModels/solidSpecie/transport/exponential/exponentialSolidTransport.hpp"

#include "thermophysicalModels/reactionThermo/mixtures/reactingMixture/reactingMixture.hpp"
#include "thermophysicalModels/reactionThermo/mixtures/multiComponentMixture/multiComponentMixture.hpp"

#include "thermophysicalModels/specie/thermo/sensibleEnthalpy/sensibleEnthalpy.hpp"
#include "thermophysicalModels/specie/thermo/thermo/thermo.hpp"


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/* * * * * * * * * * * * * * * * * Enthalpy-based * * * * * * * * * * * * * */

makeReactingSolidThermo
(
    solidReactionThermo,
    heSolidThermo,
    reactingMixture,
    constIsoSolidTransport,
    sensibleEnthalpy,
    hConstThermo,
    rhoConst,
    specie
);


makeReactingSolidThermo
(
    solidReactionThermo,
    heSolidThermo,
    reactingMixture,
    constIsoSolidTransport,
    sensibleEnthalpy,
    hPowerThermo,
    rhoConst,
    specie
);


makeReactingSolidThermo
(
    solidThermo,
    heSolidThermo,
    multiComponentMixture,
    constIsoSolidTransport,
    sensibleEnthalpy,
    hConstThermo,
    rhoConst,
    specie
);


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //
