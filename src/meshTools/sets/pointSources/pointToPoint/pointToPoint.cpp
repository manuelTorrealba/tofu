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

#include "meshTools/sets/pointSources/pointToPoint/pointToPoint.hpp"
#include "OpenFOAM/meshes/polyMesh/polyMesh.hpp"
#include "meshTools/sets/topoSets/pointSet.hpp"
#include "OpenFOAM/db/runTimeSelection/construction/addToRunTimeSelectionTable.hpp"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(pointToPoint, 0);
    addToRunTimeSelectionTable(topoSetSource, pointToPoint, word);
    addToRunTimeSelectionTable(topoSetSource, pointToPoint, istream);
}


Foam::topoSetSource::addToUsageTable Foam::pointToPoint::usage_
(
    pointToPoint::typeName,
    "\n    Usage: pointToPoint <pointSet>\n\n"
    "    Select all points in the pointSet\n\n"
);


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::pointToPoint::pointToPoint
(
    const polyMesh& mesh,
    const word& setName
)
:
    topoSetSource(mesh),
    setName_(setName)
{}


Foam::pointToPoint::pointToPoint
(
    const polyMesh& mesh,
    const dictionary& dict
)
:
    topoSetSource(mesh),
    setName_(dict.lookup("set"))
{}


Foam::pointToPoint::pointToPoint
(
    const polyMesh& mesh,
    Istream& is
)
:
    topoSetSource(mesh),
    setName_(checkIs(is))
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::pointToPoint::~pointToPoint()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void Foam::pointToPoint::applyToSet
(
    const topoSetSource::setAction action,
    topoSet& set
) const
{
    if ((action == topoSetSource::NEW) || (action == topoSetSource::ADD))
    {
        Info<< "    Adding all from pointSet " << setName_ << " ..." << endl;

        // Load the set
        pointSet loadedSet(mesh_, setName_);

        set.addSet(loadedSet);
    }
    else if (action == topoSetSource::DELETE)
    {
        Info<< "    Removing all from pointSet " << setName_ << " ..." << endl;

        // Load the set
        pointSet loadedSet(mesh_, setName_);

        set.deleteSet(loadedSet);
    }
}


// ************************************************************************* //
