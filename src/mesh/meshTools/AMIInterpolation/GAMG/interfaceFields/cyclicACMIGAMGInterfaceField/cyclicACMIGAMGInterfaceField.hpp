/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2013-2018 OpenFOAM Foundation
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
    Foam::cyclicACMIGAMGInterfaceField

Description
    GAMG agglomerated cyclic interface for Arbitrarily Coupled Mesh Interface
    (ACMI) fields.

SourceFiles
    cyclicACMIGAMGInterfaceField.C

\*---------------------------------------------------------------------------*/

#ifndef cyclicACMIGAMGInterfaceField_H
#define cyclicACMIGAMGInterfaceField_H

#include "meshTools/AMIInterpolation/GAMG/interfaceFields/cyclicAMIGAMGInterfaceField/cyclicAMIGAMGInterfaceField.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                 Class cyclicACMIGAMGInterfaceField Declaration
\*---------------------------------------------------------------------------*/

class cyclicACMIGAMGInterfaceField
:
    public cyclicAMIGAMGInterfaceField
{
public:

    //- Runtime type information
    TypeName("cyclicACMI");


    // Constructors

        //- Construct from GAMG interface and fine level interface field
        cyclicACMIGAMGInterfaceField
        (
            const GAMGInterface& GAMGCp,
            const lduInterfaceField& fineInterfaceField
        );

        //- Construct from GAMG interface and fine level interface field
        cyclicACMIGAMGInterfaceField
        (
            const GAMGInterface& GAMGCp,
            const bool doTransform,
            const int rank
        );


    //- Destructor
    virtual ~cyclicACMIGAMGInterfaceField();
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
