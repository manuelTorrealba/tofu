/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2012-2018 OpenFOAM Foundation
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
    Foam::inclinedFilmNusseltHeightFvPatchScalarField

Description
    Film height boundary condition for inclined films that imposes a
    sinusoidal perturbation on top of a mean flow rate, where the height is
    calculated using the Nusselt solution.

SourceFiles
    inclinedFilmNusseltHeightFvPatchScalarField.C

\*---------------------------------------------------------------------------*/

#ifndef inclinedFilmNusseltHeightFvPatchScalarField_H
#define inclinedFilmNusseltHeightFvPatchScalarField_H

#include "finiteVolume/fields/fvPatchFields/fvPatchField/fvPatchFields.hpp"
#include "finiteVolume/fields/fvPatchFields/basic/fixedValue/fixedValueFvPatchFields.hpp"
#include "OpenFOAM/primitives/functions/Function1/Function1/Function1.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
         Class inclinedFilmNusseltHeightFvPatchScalarField Declaration
\*---------------------------------------------------------------------------*/

class inclinedFilmNusseltHeightFvPatchScalarField
:
    public fixedValueFvPatchScalarField
{
    // Private data

        //- Mean mass flow rate per unit length [kg/s/m]
        autoPtr<Function1<scalar>> GammaMean_;

        //- Perturbation amplitude [m]
        autoPtr<Function1<scalar>> a_;

        //- Perturbation frequency [rad/s/m]
        autoPtr<Function1<scalar>> omega_;


public:

    //- Runtime type information
    TypeName("inclinedFilmNusseltHeight");


    // Constructors

        //- Construct from patch and internal field
        inclinedFilmNusseltHeightFvPatchScalarField
        (
            const fvPatch&,
            const DimensionedField<scalar, volMesh>&
        );

        //- Construct from patch, internal field and dictionary
        inclinedFilmNusseltHeightFvPatchScalarField
        (
            const fvPatch&,
            const DimensionedField<scalar, volMesh>&,
            const dictionary&
        );

        //- Construct by mapping given
        // inclinedFilmNusseltHeightFvPatchScalarField onto a new patch
        inclinedFilmNusseltHeightFvPatchScalarField
        (
            const inclinedFilmNusseltHeightFvPatchScalarField&,
            const fvPatch&,
            const DimensionedField<scalar, volMesh>&,
            const fvPatchFieldMapper&
        );

        //- Construct as copy
        inclinedFilmNusseltHeightFvPatchScalarField
        (
            const inclinedFilmNusseltHeightFvPatchScalarField&
        );

        //- Construct and return a clone
        virtual tmp<fvPatchScalarField> clone() const
        {
            return tmp<fvPatchScalarField>
            (
                new inclinedFilmNusseltHeightFvPatchScalarField(*this)
            );
        }

        //- Construct as copy setting internal field reference
        inclinedFilmNusseltHeightFvPatchScalarField
        (
            const inclinedFilmNusseltHeightFvPatchScalarField&,
            const DimensionedField<scalar, volMesh>&
        );

        //- Construct and return a clone setting internal field reference
        virtual tmp<fvPatchScalarField> clone
        (
            const DimensionedField<scalar, volMesh>& iF
        ) const
        {
            return tmp<fvPatchScalarField>
            (
                new inclinedFilmNusseltHeightFvPatchScalarField(*this, iF)
            );
        }


    // Member functions

        //- Update the coefficients associated with the patch field
        virtual void updateCoeffs();

        //- Write
        virtual void write(Ostream&) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
