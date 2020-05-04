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

#include "lagrangian/spray/clouds/derived/basicSprayCloud/basicSprayCloud.hpp"

#include "lagrangian/intermediate/parcels/include/makeParcelCloudFunctionObjects.hpp"

// Kinematic
#include "lagrangian/intermediate/parcels/include/makeThermoParcelForces.hpp"
#include "lagrangian/turbulence/parcels/include/makeThermoParcelTurbulenceForces.hpp"
#include "lagrangian/intermediate/parcels/include/makeParcelDispersionModels.hpp"
#include "lagrangian/turbulence/parcels/include/makeParcelTurbulenceDispersionModels.hpp"
#include "lagrangian/spray/parcels/include/makeSprayParcelInjectionModels.hpp"
#include "lagrangian/intermediate/parcels/include/makeParcelPatchInteractionModels.hpp"
#include "lagrangian/spray/parcels/include/makeSprayParcelStochasticCollisionModels.hpp"

// Thermodynamic
#include "lagrangian/intermediate/parcels/include/makeParcelHeatTransferModels.hpp"

// Reacting
#include "lagrangian/intermediate/parcels/include/makeReactingParcelCompositionModels.hpp"
#include "lagrangian/intermediate/parcels/include/makeReactingParcelPhaseChangeModels.hpp"
#include "lagrangian/intermediate/parcels/include/makeReactingParcelSurfaceFilmModels.hpp"

// Spray
#include "lagrangian/intermediate/submodels/Kinematic/ParticleForces/Drag/DistortedSphereDrag/DistortedSphereDragForce.hpp"
#include "lagrangian/spray/parcels/include/makeSprayParcelAtomizationModels.hpp"
#include "lagrangian/spray/parcels/include/makeSprayParcelBreakupModels.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

makeParcelCloudFunctionObjects(basicSprayCloud);

// Kinematic sub-models
makeThermoParcelForces(basicSprayCloud);
makeThermoParcelTurbulenceForces(basicSprayCloud);
makeParcelDispersionModels(basicSprayCloud);
makeParcelTurbulenceDispersionModels(basicSprayCloud);
makeSprayParcelInjectionModels(basicSprayCloud);
makeParcelPatchInteractionModels(basicSprayCloud);
makeSprayParcelStochasticCollisionModels(basicSprayCloud);

// Thermo sub-models
makeParcelHeatTransferModels(basicSprayCloud);

// Reacting sub-models
makeReactingParcelCompositionModels(basicSprayCloud);
makeReactingParcelPhaseChangeModels(basicSprayCloud);
makeReactingParcelSurfaceFilmModels(basicSprayCloud);

// Spray sub-models
makeParticleForceModelType(DistortedSphereDragForce, basicSprayCloud);
makeSprayParcelAtomizationModels(basicSprayCloud);
makeSprayParcelBreakupModels(basicSprayCloud);


// ************************************************************************* //
