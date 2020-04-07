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

#include "meshTools/sets/faceSources/normalToFace/normalToFace.hpp"
#include "OpenFOAM/meshes/polyMesh/polyMesh.hpp"
#include "meshTools/sets/topoSets/faceSet.hpp"
#include "OpenFOAM/db/runTimeSelection/construction/addToRunTimeSelectionTable.hpp"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(normalToFace, 0);
    addToRunTimeSelectionTable(topoSetSource, normalToFace, word);
    addToRunTimeSelectionTable(topoSetSource, normalToFace, istream);
}


Foam::topoSetSource::addToUsageTable Foam::normalToFace::usage_
(
    normalToFace::typeName,
    "\n    Usage: normalToFace (nx ny nz) <tol>\n\n"
    "    Select faces with normal aligned to unit vector (nx ny nz)\n"
    "    to within tol\n"
);


// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //

void Foam::normalToFace::setNormal()
{
    normal_ /= mag(normal_) + vSmall;

    Info<< "    normalToFace : Normalized vector to " << normal_ << endl;

    if (tol_ < -1 || tol_ > 1)
    {
        FatalErrorInFunction
            << "tolerance not within range -1..1 : " << tol_
            << exit(FatalError);
    }
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::normalToFace::normalToFace
(
    const polyMesh& mesh,
    const vector& normal,
    const scalar tol
)
:
    topoSetSource(mesh),
    normal_(normal),
    tol_(tol)
{
    setNormal();
}


Foam::normalToFace::normalToFace(const polyMesh& mesh, const dictionary& dict)
:
    topoSetSource(mesh),
    normal_(dict.lookup("normal")),
    tol_(readScalar(dict.lookup("cos")))
{
    setNormal();
}


Foam::normalToFace::normalToFace(const polyMesh& mesh, Istream& is)
:
    topoSetSource(mesh),
    normal_(checkIs(is)),
    tol_(readScalar(checkIs(is)))
{
    setNormal();
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::normalToFace::~normalToFace()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void Foam::normalToFace::applyToSet
(
    const topoSetSource::setAction action,
    topoSet& set
) const
{
    if ((action == topoSetSource::NEW) || (action == topoSetSource::ADD))
    {
        Info<< "    Adding faces according to normal being aligned with "
            << normal_ << " (to within " << tol_ << ") ..." << endl;

        forAll(mesh_.faceAreas(), facei)
        {
            vector n = mesh_.faceAreas()[facei];
            n /= mag(n) + vSmall;

            if (mag(1 - (n & normal_)) < tol_)
            {
                set.insert(facei);
            }
        }
    }
    else if (action == topoSetSource::DELETE)
    {
        Info<< "    Removing faces according to normal being aligned with "
            << normal_ << " (to within " << tol_ << ") ..." << endl;


        DynamicList<label> toBeRemoved(set.size()/10);

        forAllConstIter(topoSet, set, iter)
        {
            const label facei = iter.key();

            vector n = mesh_.faceAreas()[facei];
            n /= mag(n) + vSmall;

            if (mag(1 - (n & normal_)) < tol_)
            {
                toBeRemoved.append(facei);
            }
        }

        forAll(toBeRemoved, i)
        {
            set.erase(toBeRemoved[i]);
        }
    }
}


// ************************************************************************* //
