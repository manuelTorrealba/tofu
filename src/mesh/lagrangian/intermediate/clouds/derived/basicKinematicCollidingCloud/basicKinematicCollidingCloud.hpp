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

Class
    Foam::basicKinematicCollidingCloud

Description
    Cloud class to introduce kinematic colliding parcels

\*---------------------------------------------------------------------------*/

#ifndef basicKinematicCollidingCloud_H
#define basicKinematicCollidingCloud_H

#include "lagrangian/basic/Cloud/Cloud.hpp"
#include "lagrangian/intermediate/clouds/Templates/KinematicCloud/KinematicCloud.hpp"
#include "lagrangian/intermediate/clouds/Templates/CollidingCloud/CollidingCloud.hpp"
#include "lagrangian/intermediate/parcels/derived/basicKinematicCollidingParcel/basicKinematicCollidingParcel.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
    typedef CollidingCloud
    <
        KinematicCloud
        <
            Cloud
            <
                basicKinematicCollidingParcel
            >
        >
    > basicKinematicCollidingCloud;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
