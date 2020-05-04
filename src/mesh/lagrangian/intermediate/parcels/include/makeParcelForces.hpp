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

#ifndef makeParcelForces_H
#define makeParcelForces_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "lagrangian/intermediate/submodels/Kinematic/ParticleForces/Drag/SphereDrag/SphereDragForce.hpp"
#include "lagrangian/intermediate/submodels/Kinematic/ParticleForces/Drag/NonSphereDrag/NonSphereDragForce.hpp"
#include "lagrangian/intermediate/submodels/Kinematic/ParticleForces/Drag/WenYuDrag/WenYuDragForce.hpp"
#include "lagrangian/intermediate/submodels/Kinematic/ParticleForces/Drag/ErgunWenYuDrag/ErgunWenYuDragForce.hpp"
#include "lagrangian/intermediate/submodels/Kinematic/ParticleForces/Drag/PlessisMasliyahDrag/PlessisMasliyahDragForce.hpp"

#include "lagrangian/intermediate/submodels/Kinematic/ParticleForces/Lift/SaffmanMeiLift/SaffmanMeiLiftForce.hpp"
#include "lagrangian/intermediate/submodels/Kinematic/ParticleForces/Lift/TomiyamaLift/TomiyamaLiftForce.hpp"

#include "lagrangian/intermediate/submodels/Kinematic/ParticleForces/Gravity/GravityForce.hpp"
#include "lagrangian/intermediate/submodels/Kinematic/ParticleForces/NonInertialFrame/NonInertialFrameForce.hpp"
#include "lagrangian/intermediate/submodels/Kinematic/ParticleForces/Paramagnetic/ParamagneticForce.hpp"
#include "lagrangian/intermediate/submodels/Kinematic/ParticleForces/PressureGradient/PressureGradientForce.hpp"
#include "lagrangian/intermediate/submodels/Kinematic/ParticleForces/SRF/SRFForce.hpp"
#include "lagrangian/intermediate/submodels/Kinematic/ParticleForces/VirtualMass/VirtualMassForce.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define makeParcelForces(CloudType)                                            \
                                                                               \
    makeParticleForceModel(CloudType);                                         \
    makeParticleForceModelType(SphereDragForce, CloudType);                    \
    makeParticleForceModelType(NonSphereDragForce, CloudType);                 \
    makeParticleForceModelType(WenYuDragForce, CloudType);                     \
    makeParticleForceModelType(ErgunWenYuDragForce, CloudType);                \
    makeParticleForceModelType(PlessisMasliyahDragForce, CloudType);           \
    makeParticleForceModelType(SaffmanMeiLiftForce, CloudType);                \
    makeParticleForceModelType(TomiyamaLiftForce, CloudType);                  \
    makeParticleForceModelType(GravityForce, CloudType);                       \
    makeParticleForceModelType(NonInertialFrameForce, CloudType);              \
    makeParticleForceModelType(ParamagneticForce, CloudType);                  \
    makeParticleForceModelType(PressureGradientForce, CloudType);              \
    makeParticleForceModelType(SRFForce, CloudType);                           \
    makeParticleForceModelType(VirtualMassForce, CloudType);


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
