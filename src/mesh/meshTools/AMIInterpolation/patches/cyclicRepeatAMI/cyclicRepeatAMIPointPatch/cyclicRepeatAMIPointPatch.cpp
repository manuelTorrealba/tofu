/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2018 OpenFOAM Foundation
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

#include "meshTools/AMIInterpolation/patches/cyclicRepeatAMI/cyclicRepeatAMIPointPatch/cyclicRepeatAMIPointPatch.hpp"
#include "OpenFOAM/db/runTimeSelection/construction/addToRunTimeSelectionTable.hpp"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(cyclicRepeatAMIPointPatch, 0);
    addToRunTimeSelectionTable
    (
        facePointPatch,
        cyclicRepeatAMIPointPatch,
        polyPatch
    );
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::cyclicRepeatAMIPointPatch::cyclicRepeatAMIPointPatch
(
    const polyPatch& patch,
    const pointBoundaryMesh& bm
)
:
    cyclicAMIPointPatch(patch, bm)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::cyclicRepeatAMIPointPatch::~cyclicRepeatAMIPointPatch()
{}


// ************************************************************************* //
