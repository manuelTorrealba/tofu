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
    Foam::cyclicLduInterface

Description
    An abstract base class for cyclic coupled interfaces.

SourceFiles
    cyclicLduInterface.C

\*---------------------------------------------------------------------------*/

#ifndef cyclicLduInterface_H
#define cyclicLduInterface_H

#include "lduInterface.H"
#include "primitiveFieldsFwd.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                  Class cyclicLduInterface Declaration
\*---------------------------------------------------------------------------*/

class cyclicLduInterface
{

public:

    //- Runtime type information
    TypeName("cyclicLduInterface");

    // Constructors

    //- Destructor
    virtual ~cyclicLduInterface();


    // Member Functions

        // Access

            //- Return neighbour
            virtual label neighbPatchID() const = 0;

            virtual bool owner() const = 0;

            //- Return processor number
            virtual const cyclicLduInterface& neighbPatch() const = 0;

            //- Return face transformation tensor
            virtual const tensorField& forwardT() const = 0;

            //- Return face reverse transformation tensor
            virtual const tensorField& reverseT() const = 0;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
