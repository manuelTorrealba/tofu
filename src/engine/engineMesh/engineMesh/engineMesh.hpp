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
    Foam::engineMesh

Description
    Foam::engineMesh

SourceFiles
    engineMesh.C

\*---------------------------------------------------------------------------*/

#ifndef engineMesh_H
#define engineMesh_H

#include "engineTime.H"
#include "fvMesh.H"
#include "autoPtr.H"
#include "runTimeSelectionTables.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                           Class engineMesh Declaration
\*---------------------------------------------------------------------------*/

class engineMesh
:
    public fvMesh
{
    // Private Member Functions

        //- Disallow default bitwise copy construct
        engineMesh(const engineMesh&);

        //- Disallow default bitwise assignment
        void operator=(const engineMesh&);


protected:

    // Protected data

        const engineTime& engineDB_;

        label pistonIndex_;
        label linerIndex_;
        label cylinderHeadIndex_;

        dimensionedScalar deckHeight_;
        dimensionedScalar pistonPosition_;


public:

    //- Runtime type information
    TypeName("engineMesh");


    // Declare run-time constructor selection table

        declareRunTimeSelectionTable
        (
            autoPtr,
            engineMesh,
            IOobject,
            (const IOobject& io),
            (io)
        );


    // Constructors

        //- Construct from objectRegistry, and read/write options
        explicit engineMesh(const IOobject& io);


    // Selectors

        //- Select null constructed
        static autoPtr<engineMesh> New(const IOobject& io);


    //- Destructor
    virtual ~engineMesh();


    // Member Functions

        // Edit

            virtual void move() = 0;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
