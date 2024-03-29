/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2014-2018 OpenFOAM Foundation
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

#include "lagrangian/intermediate/submodels/Kinematic/ParticleForces/Drag/DistortedSphereDrag/DistortedSphereDragForce.hpp"

// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //

template<class CloudType>
Foam::scalar Foam::DistortedSphereDragForce<CloudType>::CdRe
(
    const scalar Re
) const
{
    if (Re > 1000.0)
    {
        return 0.424*Re;
    }
    else
    {
        return 24.0*(1.0 + (1.0/6.0)*pow(Re, 2.0/3.0));
    }
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class CloudType>
Foam::DistortedSphereDragForce<CloudType>::DistortedSphereDragForce
(
    CloudType& owner,
    const fvMesh& mesh,
    const dictionary& dict
)
:
    ParticleForce<CloudType>(owner, mesh, dict, typeName, false)
{}


template<class CloudType>
Foam::DistortedSphereDragForce<CloudType>::DistortedSphereDragForce
(
    const DistortedSphereDragForce<CloudType>& df
)
:
    ParticleForce<CloudType>(df)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

template<class CloudType>
Foam::DistortedSphereDragForce<CloudType>::~DistortedSphereDragForce()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class CloudType>
Foam::forceSuSp Foam::DistortedSphereDragForce<CloudType>::calcCoupled
(
    const typename CloudType::parcelType& p,
    const typename CloudType::parcelType::trackingData& td,
    const scalar dt,
    const scalar mass,
    const scalar Re,
    const scalar muc
) const
{
    forceSuSp value(Zero, 0.0);

    // Limit the drop distortion to y=0 (sphere) and y=1 (disk)
    scalar y = min(max(p.y(), 0), 1);

    value.Sp() = mass*0.75*muc*CdRe(Re)*(1 + 2.632*y)/(p.rho()*sqr(p.d()));

    return value;
}


// ************************************************************************* //
