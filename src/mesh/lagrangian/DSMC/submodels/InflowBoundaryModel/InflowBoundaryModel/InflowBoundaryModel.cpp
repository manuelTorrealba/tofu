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

#include "lagrangian/DSMC/submodels/InflowBoundaryModel/InflowBoundaryModel/InflowBoundaryModel.hpp"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class CloudType>
Foam::InflowBoundaryModel<CloudType>::InflowBoundaryModel(CloudType& owner)
:
    dict_(dictionary::null),
    owner_(owner),
    coeffDict_(dictionary::null)
{}


template<class CloudType>
Foam::InflowBoundaryModel<CloudType>::InflowBoundaryModel
(
    const dictionary& dict,
    CloudType& owner,
    const word& type
)
:
    dict_(dict),
    owner_(owner),
    coeffDict_(dict.subDict(type + "Coeffs"))
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

template<class CloudType>
Foam::InflowBoundaryModel<CloudType>::~InflowBoundaryModel()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class CloudType>
const CloudType& Foam::InflowBoundaryModel<CloudType>::owner() const
{
    return owner_;
}


template<class CloudType>
CloudType& Foam::InflowBoundaryModel<CloudType>::owner()
{
    return owner_;
}


template<class CloudType>
const Foam::dictionary& Foam::InflowBoundaryModel<CloudType>::dict() const
{
    return dict_;
}


template<class CloudType>
const Foam::dictionary& Foam::InflowBoundaryModel<CloudType>::coeffDict() const
{
    return coeffDict_;
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "lagrangian/DSMC/submodels/InflowBoundaryModel/InflowBoundaryModel/InflowBoundaryModelNew.cpp"

// ************************************************************************* //
