/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2015-2018 OpenFOAM Foundation
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
    Foam::fv::buoyancyEnergy

Description
    Calculates and applies the buoyancy energy source rho*(U&g) to the energy
    equation.

Usage
    Example usage:
    \verbatim
    fields          (h);                    // Name of energy field
    \endverbatim

SourceFiles
    buoyancyEnergy.C

\*---------------------------------------------------------------------------*/

#ifndef buoyancyEnergy_H
#define buoyancyEnergy_H

#include "finiteVolume/cfdTools/general/fvOptions/fvOption.hpp"
#include "OpenFOAM/fields/UniformDimensionedFields/uniformDimensionedFields.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace fv
{

/*---------------------------------------------------------------------------*\
               Class buoyancyEnergy Declaration
\*---------------------------------------------------------------------------*/

class buoyancyEnergy
:
    public option
{
    // Private data

        //- Name of velocity field; default = U
        word UName_;


    // Private Member Functions

        //- Disallow default bitwise copy construct
        buoyancyEnergy(const buoyancyEnergy&);

        //- Disallow default bitwise assignment
        void operator=(const buoyancyEnergy&);


public:

    //- Runtime type information
    TypeName("buoyancyEnergy");


    // Constructors

        //- Construct from explicit source name and mesh
        buoyancyEnergy
        (
            const word& sourceName,
            const word& modelType,
            const dictionary& dict,
            const fvMesh& mesh
        );


    // Member Functions

        // Evaluate

            //- Add explicit contribution to compressible momentum equation
            virtual void addSup
            (
                const volScalarField& rho,
                fvMatrix<scalar>& eqn,
                const label fieldi
            );


        // IO

            //- Read source dictionary
            virtual bool read(const dictionary& dict);
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace fv
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
