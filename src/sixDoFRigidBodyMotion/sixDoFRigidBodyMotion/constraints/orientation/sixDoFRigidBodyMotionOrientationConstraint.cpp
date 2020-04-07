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

#include "sixDoFRigidBodyMotion/sixDoFRigidBodyMotion/constraints/orientation/sixDoFRigidBodyMotionOrientationConstraint.hpp"
#include "OpenFOAM/db/runTimeSelection/construction/addToRunTimeSelectionTable.hpp"
#include "sixDoFRigidBodyMotion/sixDoFRigidBodyMotion/sixDoFRigidBodyMotion.hpp"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace sixDoFRigidBodyMotionConstraints
{
    defineTypeNameAndDebug(orientation, 0);

    addToRunTimeSelectionTable
    (
        sixDoFRigidBodyMotionConstraint,
        orientation,
        dictionary
    );
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::sixDoFRigidBodyMotionConstraints::orientation::orientation
(
    const word& name,
    const dictionary& sDoFRBMCDict,
    const sixDoFRigidBodyMotion& motion
)
:
    sixDoFRigidBodyMotionConstraint(name, sDoFRBMCDict, motion)
{
    read(sDoFRBMCDict);
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::sixDoFRigidBodyMotionConstraints::orientation::~orientation()
{}


// * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * * //

void Foam::sixDoFRigidBodyMotionConstraints::orientation::
constrainTranslation
(
    pointConstraint& pc
) const
{}


void Foam::sixDoFRigidBodyMotionConstraints::orientation::
constrainRotation
(
    pointConstraint& pc
) const
{
    pc.combine(pointConstraint(Tuple2<label, vector>(3, Zero)));
}


bool Foam::sixDoFRigidBodyMotionConstraints::orientation::read
(
    const dictionary& sDoFRBMCDict
)
{
    sixDoFRigidBodyMotionConstraint::read(sDoFRBMCDict);

    return true;
}


void Foam::sixDoFRigidBodyMotionConstraints::orientation::write
(
    Ostream& os
) const
{
}

// ************************************************************************* //
