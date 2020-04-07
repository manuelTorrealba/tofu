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

Class
    Foam::inversePointDistanceDiffusivity

Description
    Inverse distance to the given patches motion diffusivity.

SourceFiles
    inversePointDistanceDiffusivity.C

\*---------------------------------------------------------------------------*/

#ifndef inversePointDistanceDiffusivity_H
#define inversePointDistanceDiffusivity_H

#include "fvMotionSolver/motionDiffusivity/uniform/uniformDiffusivity.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                           Class inversePointDistanceDiffusivity Declaration
\*---------------------------------------------------------------------------*/

class inversePointDistanceDiffusivity
:
    public uniformDiffusivity
{
    // Private data

        //- Patches selected to base the distance on
        wordReList patchNames_;


    // Private Member Functions

        //- Disallow default bitwise copy construct
        inversePointDistanceDiffusivity(const inversePointDistanceDiffusivity&);

        //- Disallow default bitwise assignment
        void operator=(const inversePointDistanceDiffusivity&);


public:

    //- Runtime type information
    TypeName("inversePointDistance");


    // Constructors

        //- Construct for the given fvMesh and data Istream
        inversePointDistanceDiffusivity(const fvMesh& mesh, Istream& mdData);


    //- Destructor
    virtual ~inversePointDistanceDiffusivity();


    // Member Functions

        //- Correct the motion diffusivity
        virtual void correct();
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
