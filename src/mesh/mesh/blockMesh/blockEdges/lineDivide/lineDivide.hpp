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
    Foam::lineDivide

Description
    Divides a line into segments

SourceFiles
    lineDivide.C

\*---------------------------------------------------------------------------*/

#ifndef lineDivide_H
#define lineDivide_H

#include "OpenFOAM/meshes/primitiveShapes/point/pointField.hpp"
#include "OpenFOAM/primitives/Scalar/lists/scalarList.hpp"
#include "mesh/blockMesh/gradingDescriptor/gradingDescriptors.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

class blockEdge;

/*---------------------------------------------------------------------------*\
                         Class lineDivide Declaration
\*---------------------------------------------------------------------------*/

class lineDivide
{
    // Private data

        pointField points_;

        scalarList divisions_;

public:

    // Constructors

        //- Construct from components
        lineDivide
        (
            const blockEdge&,
            const label ndiv,
            const gradingDescriptors& gd = gradingDescriptors()
        );


    // Member Functions

        //- Return the points
        const pointField& points() const;

        //- Return the list of lambda values
        const scalarList& lambdaDivisions() const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
