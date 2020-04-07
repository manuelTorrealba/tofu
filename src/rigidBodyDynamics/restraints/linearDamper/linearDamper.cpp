/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2016-2018 OpenFOAM Foundation
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

#include "sixDoFRigidBodyMotion/sixDoFRigidBodyMotion/restraints/linearDamper/linearDamper.hpp"
#include "rigidBodyDynamics/rigidBodyModel/rigidBodyModel.hpp"
#include "OpenFOAM/db/runTimeSelection/construction/addToRunTimeSelectionTable.hpp"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace RBD
{
namespace restraints
{
    defineTypeNameAndDebug(linearDamper, 0);

    addToRunTimeSelectionTable
    (
        restraint,
        linearDamper,
        dictionary
    );
}
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::RBD::restraints::linearDamper::linearDamper
(
    const word& name,
    const dictionary& dict,
    const rigidBodyModel& model
)
:
    restraint(name, dict, model)
{
    read(dict);
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::RBD::restraints::linearDamper::~linearDamper()
{}


// * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * * //

void Foam::RBD::restraints::linearDamper::restrain
(
    scalarField& tau,
    Field<spatialVector>& fx
) const
{
    vector force = -coeff_*model_.v(model_.master(bodyID_)).l();

    if (model_.debug)
    {
        Info<< " force " << force << endl;
    }

    // Accumulate the force for the restrained body
    fx[bodyIndex_] += model_.X0(bodyID_).T() & spatialVector(Zero, force);
}


bool Foam::RBD::restraints::linearDamper::read
(
    const dictionary& dict
)
{
    restraint::read(dict);

    coeffs_.lookup("coeff") >> coeff_;

    return true;
}


void Foam::RBD::restraints::linearDamper::write
(
    Ostream& os
) const
{
    restraint::write(os);

    os.writeKeyword("coeff")
        << coeff_ << token::END_STATEMENT << nl;
}


// ************************************************************************* //
