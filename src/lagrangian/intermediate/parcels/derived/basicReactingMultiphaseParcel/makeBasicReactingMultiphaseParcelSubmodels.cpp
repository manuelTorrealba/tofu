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

#include "basicReactingMultiphaseCloud.H"

#include "makeParcelCloudFunctionObjects.H"

// Kinematic
#include "makeThermoParcelForces.H" // thermo variant
#include "makeParcelDispersionModels.H"
#include "makeReactingMultiphaseParcelInjectionModels.H" // MP variant
#include "makeParcelPatchInteractionModels.H"
#include "makeReactingMultiphaseParcelStochasticCollisionModels.H" // MP variant
#include "makeReactingParcelSurfaceFilmModels.H" // Reacting variant

// Thermodynamic
#include "makeParcelHeatTransferModels.H"

// Reacting
#include "makeReactingMultiphaseParcelCompositionModels.H" // MP Variant
#include "makeReactingParcelPhaseChangeModels.H"

// Reacting multiphase
#include "makeReactingMultiphaseParcelDevolatilisationModels.H"
#include "makeReactingMultiphaseParcelSurfaceReactionModels.H"

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
