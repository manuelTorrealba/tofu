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
    Foam::ignition

Description
    Foam::ignition

SourceFiles
    ignition.C
    ignitionIO.C

\*---------------------------------------------------------------------------*/

#ifndef ignition_H
#define ignition_H

#include "engine/ignition/ignitionSite.hpp"
#include "OpenFOAM/primitives/bools/Switch/Switch.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

class fvMesh;

/*---------------------------------------------------------------------------*\
                           Class ignition Declaration
\*---------------------------------------------------------------------------*/

class ignition
{
    // Private data

        const fvMesh& mesh_;

        Switch ignite_;

        PtrList<ignitionSite> ignSites_;


    // Private Member Functions

        //- Disallow default bitwise copy construct
        ignition(const ignition&);

        //- Disallow default bitwise assignment
        void operator=(const ignition&);


public:

    // Constructors

        //- Construct from Istream and database
        ignition(const dictionary&, const Time&, const fvMesh&);

        //- Construct from Istream and engineTime
        ignition(const dictionary&, const engineTime&, const fvMesh&);


    // Member Functions

        //- Return the set of ignition sites
        const PtrList<ignitionSite>& sites()
        {
            return ignSites_;
        }


        // Check

            bool ignite() const
            {
                return ignite_;
            }

            //- Are any of the ignition site currently igniting
            bool igniting() const;

            //- Has the mixture been ignited?
            bool ignited() const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
