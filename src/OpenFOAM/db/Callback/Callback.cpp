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

#include "OpenFOAM/db/Callback/Callback.hpp"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class CallbackType>
Foam::Callback<CallbackType>::Callback(CallbackRegistry<CallbackType>& cbr)
:
    cbr_(cbr)
{
    checkIn();
}


template<class CallbackType>
Foam::Callback<CallbackType>::Callback(const Callback<CallbackType>& cb)
:
    cbr_(cb.cbr_)
{
    checkIn();
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

template<class CallbackType>
Foam::Callback<CallbackType>::~Callback()
{
    checkOut();
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class CallbackType>
bool Foam::Callback<CallbackType>::checkIn()
{
    if (!Callback<CallbackType>::link::registered())
    {
        cbr_.append(static_cast<CallbackType*>(this));
        return true;
    }
    else
    {
        return false;
    }
}


template<class CallbackType>
bool Foam::Callback<CallbackType>::checkOut()
{
    if (Callback<CallbackType>::link::registered())
    {
        CallbackType* cbPtr = cbr_.remove(static_cast<CallbackType*>(this));

        if (cbPtr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}


// ************************************************************************* //
