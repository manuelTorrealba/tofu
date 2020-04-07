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

#include "fvMotionSolver/motionDiffusivity/motionDiffusivity/motionDiffusivity.hpp"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(motionDiffusivity, 0);
    defineRunTimeSelectionTable(motionDiffusivity, Istream);
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::motionDiffusivity::motionDiffusivity(const fvMesh& mesh)
:
    mesh_(mesh)
{}


// * * * * * * * * * * * * * * * * Selectors * * * * * * * * * * * * * * * * //

Foam::autoPtr<Foam::motionDiffusivity> Foam::motionDiffusivity::New
(
    const fvMesh& mesh,
    Istream& mdData
)
{
    const word motionType(mdData);

    Info<< "Selecting motion diffusion: " << motionType << endl;

    IstreamConstructorTable::iterator cstrIter =
        IstreamConstructorTablePtr_->find(motionType);

    if (cstrIter == IstreamConstructorTablePtr_->end())
    {
        FatalErrorInFunction
            << "Unknown diffusion type "
            << motionType << nl << nl
            << "Valid diffusion types are :" << endl
            << IstreamConstructorTablePtr_->sortedToc()
            << exit(FatalError);
    }

    return autoPtr<motionDiffusivity>(cstrIter()(mesh, mdData));
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::motionDiffusivity::~motionDiffusivity()
{}


// ************************************************************************* //
