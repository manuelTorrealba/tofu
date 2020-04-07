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
    Foam::boundaryToFace

Description
    A topoSetSource to select all external (boundary) faces.

SourceFiles
    boundaryToFace.C

\*---------------------------------------------------------------------------*/

#ifndef boundaryToFace_H
#define boundaryToFace_H

#include "meshTools/sets/topoSetSource/topoSetSource.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                      Class boundaryToFace Declaration
\*---------------------------------------------------------------------------*/

class boundaryToFace
:
    public topoSetSource
{
    // Private data

        //- Add usage string
        static addToUsageTable usage_;


    // Private Member Functions

        void combine(topoSet& set, const bool add) const;


public:

    //- Runtime type information
    TypeName("boundaryToFace");

    // Constructors

        //- Construct from components
        boundaryToFace(const polyMesh&);

        //- Construct from dictionary
        boundaryToFace
        (
            const polyMesh& mesh,
            const dictionary& dict
        );

        //- Construct from Istream
        boundaryToFace
        (
            const polyMesh& mesh,
            Istream&
        );


    //- Destructor
    virtual ~boundaryToFace();


    // Member Functions

        virtual sourceType setType() const
        {
            return FACESETSOURCE;
        }

        virtual void applyToSet
        (
            const topoSetSource::setAction action,
            topoSet&
        ) const;

};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
