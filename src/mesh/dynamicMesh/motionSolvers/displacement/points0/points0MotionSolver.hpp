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

Class
    Foam::points0MotionSolver

Description
    Virtual base class for displacement motion solvers.

SourceFiles
    points0MotionSolver.C

\*---------------------------------------------------------------------------*/

#ifndef points0MotionSolver_H
#define points0MotionSolver_H

#include "dynamicMesh/motionSolvers/motionSolver/motionSolver.hpp"
#include "OpenFOAM/fields/GeometricFields/pointFields/pointFields.hpp"
#include "OpenFOAM/meshes/primitiveShapes/point/pointIOField.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

class mapPolyMesh;

/*---------------------------------------------------------------------------*\
                   Class points0MotionSolver Declaration
\*---------------------------------------------------------------------------*/

class points0MotionSolver
:
    public motionSolver
{
protected:

    // Protected data

        //- Starting points
        pointIOField points0_;

    // Protected Member Functions

        //- Return IO object for points0
        IOobject points0IO(const polyMesh& mesh) const;

private:

    // Private Member Functions

        //- Disallow default bitwise copy construct
        points0MotionSolver(const points0MotionSolver&);

        //- Disallow default bitwise assignment
        void operator=(const points0MotionSolver&);

public:

    //- Runtime type information
    TypeName("points0MotionSolver");


    // Constructors

        //- Construct from mesh and dictionary
        points0MotionSolver
        (
            const polyMesh&,
            const IOdictionary&,
            const word& type
        );


    //- Destructor
    virtual ~points0MotionSolver();


    // Member Functions

        //- Return reference to the reference field
        pointField& points0()
        {
            return points0_;
        }

        //- Return reference to the reference field
        const pointField& points0() const
        {
            return points0_;
        }

        //- Update local data for geometry changes
        virtual void movePoints(const pointField&);

        //-  Update local data for topology changes
        virtual void updateMesh(const mapPolyMesh&);
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
