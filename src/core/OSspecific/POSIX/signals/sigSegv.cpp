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

#include "OSspecific/POSIX/signals/sigSegv.hpp"
#include "OpenFOAM/db/error/error.hpp"
#include "OpenFOAM/global/jobInfo/jobInfo.hpp"
#include "OpenFOAM/db/IOstreams/IOstreams.hpp"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

struct sigaction Foam::sigSegv::oldAction_;


// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //

void Foam::sigSegv::sigHandler(int)
{
    // Reset old handling
    if (sigaction(SIGSEGV, &oldAction_, nullptr) < 0)
    {
        FatalErrorInFunction
            << "Cannot reset SIGSEGV trapping"
            << abort(FatalError);
    }

    // Update jobInfo file
    jobInfo_.signalEnd();

    error::printStack(Perr);

    // Throw signal (to old handler)
    raise(SIGSEGV);
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::sigSegv::sigSegv()
{
    oldAction_.sa_handler = nullptr;
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::sigSegv::~sigSegv()
{
    // Reset old handling
    if (sigaction(SIGSEGV, &oldAction_, nullptr) < 0)
    {
        FatalErrorInFunction
            << "Cannot reset SIGSEGV trapping"
            << abort(FatalError);
    }
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void Foam::sigSegv::set(const bool)
{
    if (oldAction_.sa_handler)
    {
        FatalErrorInFunction
            << "Cannot call sigSegv::set() more than once"
            << abort(FatalError);
    }

    struct sigaction newAction;
    newAction.sa_handler = sigHandler;
    newAction.sa_flags = SA_NODEFER;
    sigemptyset(&newAction.sa_mask);
    if (sigaction(SIGSEGV, &newAction, &oldAction_) < 0)
    {
        FatalErrorInFunction
            << "Cannot set SIGSEGV trapping"
            << abort(FatalError);
    }
}


// ************************************************************************* //
