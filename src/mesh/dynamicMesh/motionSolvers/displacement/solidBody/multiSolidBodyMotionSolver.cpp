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

#include "dynamicMesh/motionSolvers/displacement/solidBody/multiSolidBodyMotionSolver.hpp"
#include "OpenFOAM/db/runTimeSelection/construction/addToRunTimeSelectionTable.hpp"
#include "OpenFOAM/fields/Fields/transformField/transformField.hpp"
#include "OpenFOAM/meshes/polyMesh/zones/ZoneMesh/cellZoneMesh.hpp"
#include "OpenFOAM/primitives/bools/lists/boolList.hpp"
#include "OpenFOAM/meshes/polyMesh/syncTools/syncTools.hpp"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(multiSolidBodyMotionSolver, 0);
    addToRunTimeSelectionTable
    (
        motionSolver,
        multiSolidBodyMotionSolver,
        dictionary
    );
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::multiSolidBodyMotionSolver::multiSolidBodyMotionSolver
(
    const polyMesh& mesh,
    const IOdictionary& dict
)
:
    points0MotionSolver(mesh, dict, typeName)
{
    zoneIDs_.setSize(coeffDict().size());
    SBMFs_.setSize(coeffDict().size());
    pointIDs_.setSize(coeffDict().size());
    label zonei = 0;

    forAllConstIter(dictionary, coeffDict(), iter)
    {
        if (iter().isDict())
        {
            zoneIDs_[zonei] = mesh.cellZones().findZoneID(iter().keyword());

            if (zoneIDs_[zonei] == -1)
            {
                FatalIOErrorInFunction
                (
                    coeffDict()
                )   << "Cannot find cellZone named " << iter().keyword()
                    << ". Valid zones are " << mesh.cellZones().names()
                    << exit(FatalIOError);
            }

            const dictionary& subDict = iter().dict();

            SBMFs_.set
            (
                zonei,
                solidBodyMotionFunction::New(subDict, mesh.time())
            );

            // Collect points of cell zone.
            const cellZone& cz = mesh.cellZones()[zoneIDs_[zonei]];

            boolList movePts(mesh.nPoints(), false);

            forAll(cz, i)
            {
                label celli = cz[i];
                const cell& c = mesh.cells()[celli];
                forAll(c, j)
                {
                    const face& f = mesh.faces()[c[j]];
                    forAll(f, k)
                    {
                        label pointi = f[k];
                        movePts[pointi] = true;
                    }
                }
            }

            syncTools::syncPointList(mesh, movePts, orEqOp<bool>(), false);

            DynamicList<label> ptIDs(mesh.nPoints());
            forAll(movePts, i)
            {
                if (movePts[i])
                {
                    ptIDs.append(i);
                }
            }

            pointIDs_[zonei].transfer(ptIDs);

            Info<< "Applying solid body motion " << SBMFs_[zonei].type()
                << " to " << pointIDs_[zonei].size() << " points of cellZone "
                << iter().keyword() << endl;

            zonei++;
        }
    }
    zoneIDs_.setSize(zonei);
    SBMFs_.setSize(zonei);
    pointIDs_.setSize(zonei);
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::multiSolidBodyMotionSolver::~multiSolidBodyMotionSolver()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::pointField> Foam::multiSolidBodyMotionSolver::curPoints() const
{
    tmp<pointField> ttransformedPts(new pointField(mesh().points()));
    pointField& transformedPts = ttransformedPts.ref();

    forAll(zoneIDs_, i)
    {
        const labelList& zonePoints = pointIDs_[i];

        UIndirectList<point>(transformedPts, zonePoints) = transformPoints
        (
            SBMFs_[i].transformation(),
            pointField(points0_, zonePoints)
        );
    }

    return ttransformedPts;
}


// ************************************************************************* //
