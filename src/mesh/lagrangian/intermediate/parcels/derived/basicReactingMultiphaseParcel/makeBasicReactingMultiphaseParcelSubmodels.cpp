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

#include "lagrangian/intermediate/clouds/derived/basicReactingMultiphaseCloud/basicReactingMultiphaseCloud.hpp"

#include "lagrangian/intermediate/parcels/include/makeParcelCloudFunctionObjects.hpp"

// Kinematic
#include "lagrangian/intermediate/parcels/include/makeThermoParcelForces.hpp"
#include "lagrangian/intermediate/parcels/include/makeParcelDispersionModels.hpp"
#include "lagrangian/intermediate/parcels/include/makeReactingMultiphaseParcelInjectionModels.hpp"
#include "lagrangian/intermediate/parcels/include/makeParcelPatchInteractionModels.hpp"
#include "lagrangian/intermediate/parcels/include/makeReactingMultiphaseParcelStochasticCollisionModels.hpp"
#include "lagrangian/intermediate/parcels/include/makeReactingParcelSurfaceFilmModels.hpp"

// Thermodynamic
#include "lagrangian/intermediate/parcels/include/makeParcelHeatTransferModels.hpp"

// Reacting
#include "lagrangian/intermediate/parcels/include/makeReactingMultiphaseParcelCompositionModels.hpp"
#include "lagrangian/intermediate/parcels/include/makeReactingParcelPhaseChangeModels.hpp"

// Reacting multiphase
#include "lagrangian/intermediate/parcels/include/makeReactingMultiphaseParcelDevolatilisationModels.hpp"
#include "lagrangian/intermediate/parcels/include/makeReactingMultiphaseParcelSurfaceReactionModels.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

makeParcelCloudFunctionObjects(basicReactingMultiphaseCloud);

// Kinematic sub-models
makeThermoParcelForces(basicReactingMultiphaseCloud);
makeParcelDispersionModels(basicReactingMultiphaseCloud);
makeReactingMultiphaseParcelInjectionModels(basicReactingMultiphaseCloud);
makeParcelPatchInteractionModels(basicReactingMultiphaseCloud);
makeReactingMultiphaseParcelStochasticCollisionModels
(
    basicReactingMultiphaseCloud
);
makeReactingParcelSurfaceFilmModels(basicReactingMultiphaseCloud);

// Thermo sub-models
makeParcelHeatTransferModels(basicReactingMultiphaseCloud);

// Reacting sub-models
makeReactingMultiphaseParcelCompositionModels
(
    basicReactingMultiphaseCloud
);
makeReactingParcelPhaseChangeModels(basicReactingMultiphaseCloud);

// Reacting multiphase sub-models
makeReactingMultiphaseParcelDevolatilisationModels
(
    basicReactingMultiphaseCloud
);
makeReactingMultiphaseParcelSurfaceReactionModels
(
    basicReactingMultiphaseCloud
);


// ************************************************************************* //
