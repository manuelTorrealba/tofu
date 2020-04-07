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

#include "lagrangian/intermediate/clouds/derived/basicKinematicCloud/basicKinematicCloud.hpp"

#include "lagrangian/intermediate/parcels/include/makeParcelCloudFunctionObjects.hpp"

// Kinematic
#include "lagrangian/intermediate/parcels/include/makeParcelForces.hpp"
#include "lagrangian/intermediate/parcels/include/makeParcelDispersionModels.hpp"
#include "lagrangian/intermediate/parcels/include/makeParcelInjectionModels.hpp"
#include "lagrangian/intermediate/parcels/include/makeParcelPatchInteractionModels.hpp"
#include "lagrangian/intermediate/parcels/include/makeParcelStochasticCollisionModels.hpp"
#include "lagrangian/intermediate/parcels/include/makeParcelSurfaceFilmModels.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

makeParcelCloudFunctionObjects(basicKinematicCloud);

// Kinematic sub-models
makeParcelForces(basicKinematicCloud);
makeParcelDispersionModels(basicKinematicCloud);
makeParcelInjectionModels(basicKinematicCloud);
makeParcelPatchInteractionModels(basicKinematicCloud);
makeParcelStochasticCollisionModels(basicKinematicCloud);
makeParcelSurfaceFilmModels(basicKinematicCloud);


// ************************************************************************* //
