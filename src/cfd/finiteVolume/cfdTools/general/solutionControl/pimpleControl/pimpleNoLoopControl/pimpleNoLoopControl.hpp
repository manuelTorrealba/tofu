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

Class
    Foam::pimpleNoLoopControl

Description
    Pimple no-loop control class. Implements various option flags, but leaves
    loop controls to the derivation or owner. Can be derived into a "full"
    pimple control or can be owned by a multi-region pimple class.

SourceFiles
    pimpleNoLoopControlI.H
    pimpleNoLoopControl.C

\*---------------------------------------------------------------------------*/

#ifndef pimpleNoLoopControl_H
#define pimpleNoLoopControl_H

#include "finiteVolume/cfdTools/general/solutionControl/pisoControl/pisoControl.hpp"
#include "finiteVolume/cfdTools/general/solutionControl/convergenceControl/singleRegionConvergenceControl/singleRegionConvergenceControl.hpp"
#include "finiteVolume/cfdTools/general/solutionControl/convergenceControl/singleRegionCorrectorConvergenceControl/singleRegionCorrectorConvergenceControl.hpp"

#undef PISO_CONTROL
#define PIMPLE_CONTROL

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                         Class pimpleNoLoopControl Declaration
\*---------------------------------------------------------------------------*/

class pimpleNoLoopControl
:
    public pisoControl,
    public singleRegionConvergenceControl,
    public singleRegionCorrectorConvergenceControl
{
protected:

    // Protected data

        //- Flag to indicate whether to update the density in SIMPLE mode rather
        //  than PISO mode
        bool simpleRho_;

        //- Flag to control whether turblence is solved just on the final pimple
        //  iteration, or on every pimple iteration
        bool turbOnFinalIterOnly_;


public:

    // Static data members

        //- Run-time type information
        TypeName("pimpleNoLoopControl");


    // Constructors

        //- Construct from a mesh and the name of the algorithm
        pimpleNoLoopControl(fvMesh& mesh, const word& algorithmName);


    //- Destructor
    virtual ~pimpleNoLoopControl();


    // Member Functions

        // IO

            //- Read controls
            virtual bool read();

        // Access

            //- Flag to indicate whether to update the density in simple mode
            inline bool simpleRho() const;

            //- Flag to indicate whether to solve the turbulence on the final
            //  pimple iteration only
            inline bool turbOnFinalIterOnly() const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "finiteVolume/cfdTools/general/solutionControl/pimpleControl/pimpleNoLoopControl/pimpleNoLoopControlI.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
