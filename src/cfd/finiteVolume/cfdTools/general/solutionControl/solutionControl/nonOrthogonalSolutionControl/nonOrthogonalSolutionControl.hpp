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
    Foam::nonOrthogonalSolutionControl

Description
    Non-orthogonal solution control class. Provides non-orthogonal-loop control
    methods.

SourceFiles
    nonOrthogonalControlI.H
    nonOrthogonalSolutionControl.C

\*---------------------------------------------------------------------------*/

#ifndef nonOrthogonalSolutionControl_H
#define nonOrthogonalSolutionControl_H

#include "finiteVolume/cfdTools/general/solutionControl/solutionControl/singleRegionSolutionControl/singleRegionSolutionControl.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                         Class nonOrthogonalSolutionControl Declaration
\*---------------------------------------------------------------------------*/

class nonOrthogonalSolutionControl
:
    public singleRegionSolutionControl
{
protected:

    // Protected data

        //- Maximum number of non-orthogonal correctors
        label nNonOrthCorr_;

        //- Current non-orthogonal corrector index
        label nonOrthCorr_;


public:

    // Static Data Members

        //- Run-time type information
        TypeName("nonOrthogonalSolutionControl");


    // Constructors

        //- Construct from a mesh and the name of the algorithm
        nonOrthogonalSolutionControl(fvMesh& mesh, const word& algorithmName);


    //- Destructor
    virtual ~nonOrthogonalSolutionControl();


    // Member Functions

        // IO

            //- Read controls
            virtual bool read();

        // Access

            //- Maximum number of non-orthogonal correctors
            inline label nNonOrthCorr() const;

            //- Flag to indicate the first non-orthogonal iteration
            inline bool firstNonOrthogonalIter() const;

            //- Flag to indicate the last non-orthogonal iteration
            inline bool finalNonOrthogonalIter() const;

        // Evolution

            //- Non-orthogonal corrector loop
            bool correctNonOrthogonal();
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "finiteVolume/cfdTools/general/solutionControl/solutionControl/nonOrthogonalSolutionControl/nonOrthogonalSolutionControlI.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
