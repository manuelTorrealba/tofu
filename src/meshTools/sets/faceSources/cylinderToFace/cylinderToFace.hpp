/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2017-2018 OpenFOAM Foundation
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
    Foam::cylinderToFace

Description
    A topoSetSource to select faces based on face centres inside a cylinder.

SourceFiles
    cylinderToFace.C

\*---------------------------------------------------------------------------*/

#ifndef cylinderToFace_H
#define cylinderToFace_H

#include "meshTools/sets/topoSetSource/topoSetSource.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                       Class cylinderToFace Declaration
\*---------------------------------------------------------------------------*/

class cylinderToFace
:
    public topoSetSource
{

    // Private data

        //- Add usage string
        static addToUsageTable usage_;

        //- First point on cylinder axis
        vector p1_;

        //- Second point on cylinder axis
        vector p2_;

        //- Radius
        scalar radius_;


    // Private Member Functions

        void combine(topoSet& set, const bool add) const;


public:

    //- Runtime type information
    TypeName("cylinderToFace");


    // Constructors

        //- Construct from components
        cylinderToFace
        (
            const polyMesh& mesh,
            const vector& p1,
            const vector& p2,
            const scalar radius
        );

        //- Construct from dictionary
        cylinderToFace
        (
            const polyMesh& mesh,
            const dictionary& dict
        );

        //- Construct from Istream
        cylinderToFace
        (
            const polyMesh& mesh,
            Istream&
        );


    //- Destructor
    virtual ~cylinderToFace();


    // Member Functions

        virtual sourceType setType() const
        {
            return CELLSETSOURCE;
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
