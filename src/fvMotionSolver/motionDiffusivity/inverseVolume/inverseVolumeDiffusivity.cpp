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

#include "fvMotionSolver/motionDiffusivity/inverseVolume/inverseVolumeDiffusivity.hpp"
#include "OpenFOAM/db/runTimeSelection/construction/addToRunTimeSelectionTable.hpp"
#include "meshTools/cellDist/patchWave/patchWave.hpp"
#include "OpenFOAM/containers/HashTables/HashSet/HashSet.hpp"
#include "functionObjects/field/surfaceInterpolate/surfaceInterpolate.hpp"
#include "finiteVolume/fields/fvPatchFields/basic/zeroGradient/zeroGradientFvPatchFields.hpp"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(inverseVolumeDiffusivity, 0);

    addToRunTimeSelectionTable
    (
        motionDiffusivity,
        inverseVolumeDiffusivity,
        Istream
    );
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::inverseVolumeDiffusivity::inverseVolumeDiffusivity
(
    const fvMesh& mesh,
    Istream& mdData
)
:
    uniformDiffusivity(mesh, mdData)
{
    correct();
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::inverseVolumeDiffusivity::~inverseVolumeDiffusivity()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void Foam::inverseVolumeDiffusivity::correct()
{
    volScalarField V
    (
        IOobject
        (
            "V",
            mesh().time().timeName(),
            mesh(),
            IOobject::NO_READ,
            IOobject::NO_WRITE,
            false
        ),
        mesh(),
        dimless,
        zeroGradientFvPatchScalarField::typeName
    );

    V.primitiveFieldRef() = mesh().V();
    V.correctBoundaryConditions();

    faceDiffusivity_ = 1.0/fvc::interpolate(V);
}


// ************************************************************************* //
