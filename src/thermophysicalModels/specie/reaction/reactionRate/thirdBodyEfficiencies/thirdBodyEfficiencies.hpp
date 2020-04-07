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
    Foam::thirdBodyEfficiencies

Description
    Third body efficiencies

SourceFiles
    thirdBodyEfficienciesI.H

\*---------------------------------------------------------------------------*/

#ifndef thirdBodyEfficiencies_H
#define thirdBodyEfficiencies_H

#include "OpenFOAM/primitives/Scalar/lists/scalarList.hpp"
#include "thermophysicalModels/specie/speciesTable/speciesTable.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward declaration of friend functions and operators

class thirdBodyEfficiencies;
Ostream& operator<<(Ostream&, const thirdBodyEfficiencies&);


/*---------------------------------------------------------------------------*\
                  Class thirdBodyEfficiencies Declaration
\*---------------------------------------------------------------------------*/

class thirdBodyEfficiencies
:
    public scalarList
{
    // Private data

        const speciesTable& species_;


public:

    // Constructors

        //- Construct from components
        inline thirdBodyEfficiencies
        (
            const speciesTable& species,
            const scalarList& efficiencies
        );

        //- Construct from dictionary
        inline thirdBodyEfficiencies
        (
            const speciesTable& species,
            const dictionary& dict
        );


    // Member functions

        //- Calculate and return M, the concentration of the third-bodies
        inline scalar M(const scalarList& c) const;

        //- Write to stream
        inline void write(Ostream& os) const;



    // Ostream Operator

        friend Ostream& operator<<(Ostream&, const thirdBodyEfficiencies&);
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "thermophysicalModels/specie/reaction/reactionRate/thirdBodyEfficiencies/thirdBodyEfficienciesI.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
