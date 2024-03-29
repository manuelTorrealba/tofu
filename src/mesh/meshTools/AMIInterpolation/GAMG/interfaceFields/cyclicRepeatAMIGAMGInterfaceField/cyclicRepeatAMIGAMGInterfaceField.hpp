/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2018 OpenFOAM Foundation
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
    Foam::cyclicRepeatAMIGAMGInterfaceField

Description
    GAMG agglomerated repeat AMI interface field.

SourceFiles
    cyclicRepeatAMIGAMGInterfaceField.C

\*---------------------------------------------------------------------------*/

#ifndef cyclicRepeatAMIGAMGInterfaceField_H
#define cyclicRepeatAMIGAMGInterfaceField_H

#include "meshTools/AMIInterpolation/GAMG/interfaceFields/cyclicAMIGAMGInterfaceField/cyclicAMIGAMGInterfaceField.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                 Class cyclicRepeatAMIGAMGInterfaceField Declaration
\*---------------------------------------------------------------------------*/

class cyclicRepeatAMIGAMGInterfaceField
:
    public cyclicAMIGAMGInterfaceField
{
public:

    //- Runtime type information
    TypeName("cyclicRepeatAMI");


    // Constructors

        //- Construct from GAMG interface and fine level interface field
        cyclicRepeatAMIGAMGInterfaceField
        (
            const GAMGInterface& GAMGCp,
            const lduInterfaceField& fineInterfaceField
        );

        //- Construct from GAMG interface and fine level interface field
        cyclicRepeatAMIGAMGInterfaceField
        (
            const GAMGInterface& GAMGCp,
            const bool doTransform,
            const int rank
        );


    //- Destructor
    virtual ~cyclicRepeatAMIGAMGInterfaceField();
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
