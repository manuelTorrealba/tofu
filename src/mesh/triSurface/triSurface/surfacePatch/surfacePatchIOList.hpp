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
    Foam::surfacePatchIOList

Description
    IOobject for a surfacePatchList

SourceFiles
    surfacePatchIOList.C

\*---------------------------------------------------------------------------*/

#ifndef surfacePatchIOList_H
#define surfacePatchIOList_H

#include "triSurface/triSurface/surfacePatch/surfacePatchList.hpp"
#include "OpenFOAM/db/regIOobject/regIOobject.hpp"
#include "OpenFOAM/meshes/meshShapes/face/faceList.hpp"
#include "OpenFOAM/db/typeInfo/className.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward declaration of friend functions and operators

class surfacePatchIOList;

Ostream& operator<<(Ostream&, const surfacePatchIOList&);


/*---------------------------------------------------------------------------*\
                           Class surfacePatchIOList Declaration
\*---------------------------------------------------------------------------*/

class surfacePatchIOList
:
    public surfacePatchList,
    public regIOobject
{
    // Private data


    // Private Member Functions

        //- Disallow default bitwise copy construct
        surfacePatchIOList(const surfacePatchIOList&);

        //- Disallow default bitwise assignment
        void operator=(const surfacePatchIOList&);


public:

    //- Runtime type information
    TypeName("surfacePatchIOList");


    // Static data members

        //- Static data someStaticData

    // Constructors

        //- Construct from IOobject
        explicit surfacePatchIOList(const IOobject& io);

        //- Construct from IOobject
        surfacePatchIOList(const IOobject& io, const surfacePatchList&);

    //- Destructor
    ~surfacePatchIOList();


    // Member Functions

        //- writeData member function required by regIOobject
        bool writeData(Ostream&) const;


    // IOstream Operators

        friend Ostream& operator<<(Ostream&, const surfacePatchIOList&);
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
