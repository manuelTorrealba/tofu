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
    Foam::basicKinematicParcel

Description
    Definition of basic kinematic parcel

SourceFiles
    basicKinematicParcel.H

\*---------------------------------------------------------------------------*/

#ifndef basicKinematicParcel_H
#define basicKinematicParcel_H

#include "OpenFOAM/primitives/contiguous/contiguous.hpp"
#include "lagrangian/basic/particle/particle.hpp"
#include "lagrangian/intermediate/parcels/Templates/KinematicParcel/KinematicParcel.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
    typedef KinematicParcel<particle> basicKinematicParcel;

    template<>
    inline bool contiguous<basicKinematicParcel>()
    {
        return true;
    }
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
