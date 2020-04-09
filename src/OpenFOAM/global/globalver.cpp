/*--------------------------------*- C++ -*----------------------------------*\
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

Description
    Define the globals used in the OpenFOAM library.
    It is important that these are constructed in the appropriate order to
    avoid the use of unconstructed data in the global namespace.

    This file has the extension .Cver to trigger a Makefile rule that converts
    'VERSION\_STRING' and 'BUILD\_STRING' into the appropriate strings.

\*---------------------------------------------------------------------------*/

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
#include "OpenFOAM/global/foamVersion.hpp"

const char* const Foam::FOAMversion = "tofu_1.0";
const char* const Foam::FOAMbuild = "manuelTorrealba_tofu_1.0";

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
// Setup an error handler for the global new operator

#include "OpenFOAM/global/new.cpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
// Create the nullObject singleton

#include "OpenFOAM/primitives/nullObject/nullObject.cpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
// Global IO streams

#include "OpenFOAM/db/IOstreams/IOstreams.cpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "OpenFOAM/global/jobInfo/jobInfo.hpp"
bool Foam::jobInfo::constructed(false);

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
// Global error definitions (initialised by construction)

#include "OpenFOAM/db/error/messageStream.cpp"
#include "OpenFOAM/db/error/error.cpp"
#include "OpenFOAM/db/error/IOerror.cpp"
#include "OpenFOAM/db/IOstreams/token/token.cpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
// Read the debug and info switches

#include "OpenFOAM/global/debug/debug.cpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
// Read file modification checking switches

#include "OpenFOAM/db/regIOobject/regIOobject.cpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
// Read parallel communication switches

#include "OpenFOAM/db/IOstreams/Pstreams/UPstream.cpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
// Read constants

#include "OpenFOAM/global/constants/constants.cpp"
#include "OpenFOAM/global/constants/dimensionedConstants.cpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
// Create the jobInfo file in the $FOAM_JOB_DIR/runningJobs directory

#include "OpenFOAM/global/jobInfo/jobInfo.cpp"

// ************************************************************************* //
