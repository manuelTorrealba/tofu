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

#include "thermophysicalModels/reactionThermo/psiuReactionThermo/psiuReactionThermo.hpp"
#include "thermophysicalModels/reactionThermo/psiuReactionThermo/heheuPsiThermo.hpp"

#include "thermophysicalModels/reactionThermo/makeReactionThermo.hpp"
#include "OpenFOAM/db/runTimeSelection/construction/addToRunTimeSelectionTable.hpp"

#include "thermophysicalModels/specie/specie/specie.hpp"
#include "thermophysicalModels/specie/equationOfState/perfectGas/perfectGas.hpp"
#include "thermophysicalModels/specie/thermo/hConst/hConstThermo.hpp"
#include "thermophysicalModels/specie/thermo/janaf/janafThermo.hpp"
#include "thermophysicalModels/specie/thermo/thermo/thermo.hpp"
#include "thermophysicalModels/specie/transport/const/constTransport.hpp"
#include "thermophysicalModels/specie/transport/sutherland/sutherlandTransport.hpp"

#include "thermophysicalModels/specie/thermo/absoluteEnthalpy/absoluteEnthalpy.hpp"
#include "thermophysicalModels/specie/thermo/absoluteInternalEnergy/absoluteInternalEnergy.hpp"

#include "thermophysicalModels/reactionThermo/mixtures/homogeneousMixture/homogeneousMixture.hpp"
#include "thermophysicalModels/reactionThermo/mixtures/inhomogeneousMixture/inhomogeneousMixture.hpp"
#include "thermophysicalModels/reactionThermo/mixtures/veryInhomogeneousMixture/veryInhomogeneousMixture.hpp"
#include "thermophysicalModels/reactionThermo/mixtures/multiComponentMixture/multiComponentMixture.hpp"
#include "thermophysicalModels/reactionThermo/mixtures/egrMixture/egrMixture.hpp"


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * * h-hu-Thermos * * * * * * * * * * * * * * * //

makeReactionThermos
(
    psiThermo,
    psiuReactionThermo,
    heheuPsiThermo,
    homogeneousMixture,
    constTransport,
    absoluteEnthalpy,
    hConstThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiuReactionThermo,
    heheuPsiThermo,
    inhomogeneousMixture,
    constTransport,
    absoluteEnthalpy,
    hConstThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiuReactionThermo,
    heheuPsiThermo,
    veryInhomogeneousMixture,
    constTransport,
    absoluteEnthalpy,
    hConstThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiuReactionThermo,
    heheuPsiThermo,
    egrMixture,
    constTransport,
    absoluteEnthalpy,
    hConstThermo,
    perfectGas,
    specie
);


makeReactionThermos
(
    psiThermo,
    psiuReactionThermo,
    heheuPsiThermo,
    homogeneousMixture,
    constTransport,
    absoluteEnthalpy,
    janafThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiuReactionThermo,
    heheuPsiThermo,
    homogeneousMixture,
    sutherlandTransport,
    absoluteEnthalpy,
    janafThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiuReactionThermo,
    heheuPsiThermo,
    inhomogeneousMixture,
    sutherlandTransport,
    absoluteEnthalpy,
    janafThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiuReactionThermo,
    heheuPsiThermo,
    veryInhomogeneousMixture,
    sutherlandTransport,
    absoluteEnthalpy,
    janafThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiuReactionThermo,
    heheuPsiThermo,
    egrMixture,
    sutherlandTransport,
    absoluteEnthalpy,
    janafThermo,
    perfectGas,
    specie
);


makeReactionThermos
(
    psiThermo,
    psiuReactionThermo,
    heheuPsiThermo,
    homogeneousMixture,
    sutherlandTransport,
    absoluteInternalEnergy,
    janafThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiuReactionThermo,
    heheuPsiThermo,
    inhomogeneousMixture,
    sutherlandTransport,
    absoluteInternalEnergy,
    janafThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiuReactionThermo,
    heheuPsiThermo,
    veryInhomogeneousMixture,
    sutherlandTransport,
    absoluteInternalEnergy,
    janafThermo,
    perfectGas,
    specie
);

makeReactionThermos
(
    psiThermo,
    psiuReactionThermo,
    heheuPsiThermo,
    egrMixture,
    sutherlandTransport,
    absoluteInternalEnergy,
    janafThermo,
    perfectGas,
    specie
);


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //
