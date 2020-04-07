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

#include "lagrangian/intermediate/clouds/derived/basicReactingCloud/basicReactingCloud.hpp"

#include "lagrangian/intermediate/parcels/include/makeParcelCloudFunctionObjects.hpp"

// Kinematic
#include "lagrangian/intermediate/parcels/include/makeThermoParcelForces.hpp"
#include "lagrangian/intermediate/parcels/include/makeParcelDispersionModels.hpp"
#include "lagrangian/intermediate/parcels/include/makeReactingParcelInjectionModels.hpp"
#include "lagrangian/intermediate/parcels/include/makeParcelPatchInteractionModels.hpp"
#include "lagrangian/intermediate/parcels/include/makeParcelStochasticCollisionModels.hpp"
#include "lagrangian/intermediate/parcels/include/makeReactingParcelSurfaceFilmModels.hpp"

// Thermodynamic
#include "lagrangian/intermediate/parcels/include/makeParcelHeatTransferModels.hpp"

// Reacting
#include "lagrangian/intermediate/parcels/include/makeReactingParcelCompositionModels.hpp"
#include "lagrangian/intermediate/parcels/include/makeReactingParcelPhaseChangeModels.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

makeParcelCloudFunctionObjects(basicReactingCloud);

// Kinematic sub-models
makeThermoParcelForces(basicReactingCloud);
makeParcelDispersionModels(basicReactingCloud);
makeReactingParcelInjectionModels(basicReactingCloud);
makeParcelPatchInteractionModels(basicReactingCloud);
makeParcelStochasticCollisionModels(basicReactingCloud);
makeReactingParcelSurfaceFilmModels(basicReactingCloud);

// Thermo sub-models
makeParcelHeatTransferModels(basicReactingCloud);

// Reacting sub-models
makeReactingParcelCompositionModels(basicReactingCloud);
makeReactingParcelPhaseChangeModels(basicReactingCloud);


// ************************************************************************* //
