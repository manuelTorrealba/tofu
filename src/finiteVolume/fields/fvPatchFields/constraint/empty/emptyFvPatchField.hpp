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
    Foam::emptyFvPatchField

Description
    This boundary condition provides an 'empty' condition for reduced
    dimensions cases, i.e. 1- and 2-D geometries.  Apply this condition to
    patches whose normal is aligned to geometric directions that do not
    constitue solution directions.

Usage
    Example of the boundary condition specification:
    \verbatim
    <patchName>
    {
        type            empty;
    }
    \endverbatim

SourceFiles
    emptyFvPatchField.C

\*---------------------------------------------------------------------------*/

#ifndef emptyFvPatchField_H
#define emptyFvPatchField_H

#include "finiteVolume/fields/fvPatchFields/fvPatchField/fvPatchField.hpp"
#include "finiteVolume/fvMesh/fvPatches/constraint/empty/emptyFvPatch.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                      Class emptyFvPatchField Declaration
\*---------------------------------------------------------------------------*/

template<class Type>
class emptyFvPatchField
:
    public fvPatchField<Type>
{

public:

    //- Runtime type information
    TypeName(emptyFvPatch::typeName_());


    // Constructors

        //- Construct from patch and internal field
        emptyFvPatchField
        (
            const fvPatch&,
            const DimensionedField<Type, volMesh>&
        );

        //- Construct from patch, internal field and dictionary
        emptyFvPatchField
        (
            const fvPatch&,
            const DimensionedField<Type, volMesh>&,
            const dictionary&
        );

        //- Construct by mapping given emptyFvPatchField onto a new patch
        emptyFvPatchField
        (
            const emptyFvPatchField<Type>&,
            const fvPatch&,
            const DimensionedField<Type, volMesh>&,
            const fvPatchFieldMapper&
        );

        //- Construct as copy
        emptyFvPatchField
        (
            const emptyFvPatchField<Type>&
        );

        //- Construct and return a clone
        virtual tmp<fvPatchField<Type>> clone() const
        {
            return tmp<fvPatchField<Type>>
            (
                new emptyFvPatchField<Type>(*this)
            );
        }

        //- Construct as copy setting internal field reference
        emptyFvPatchField
        (
            const emptyFvPatchField<Type>&,
            const DimensionedField<Type, volMesh>&
        );

        //- Construct and return a clone setting internal field reference
        virtual tmp<fvPatchField<Type>> clone
        (
            const DimensionedField<Type, volMesh>& iF
        ) const
        {
            return tmp<fvPatchField<Type>>
            (
                new emptyFvPatchField<Type>(*this, iF)
            );
        }


    // Member functions

        // Mapping functions

            //- Map (and resize as needed) from self given a mapping object
            virtual void autoMap
            (
                const fvPatchFieldMapper&
            )
            {}

            //- Reverse map the given fvPatchField onto this fvPatchField
            virtual void rmap
            (
                const fvPatchField<Type>&,
                const labelList&
            )
            {}


        // Evaluation functions

            //- Update the coefficients associated with the patch field
            //  This only checks to see the case is actually 1D or 2D
            //  for which this boundary condition is valid
            void updateCoeffs();


            //- Return the matrix diagonal coefficients corresponding to the
            //  evaluation of the value of this patchField with given weights
            virtual tmp<Field<Type>> valueInternalCoeffs
            (
                const tmp<scalarField>&
            ) const
            {
                return tmp<Field<Type>>(new Field<Type>(0));
            }

            //- Return the matrix source coefficients corresponding to the
            //  evaluation of the value of this patchField with given weights
            virtual tmp<Field<Type>> valueBoundaryCoeffs
            (
                const tmp<scalarField>&
            ) const
            {
                return tmp<Field<Type>>(new Field<Type>(0));
            }

            //- Return the matrix diagonal coefficients corresponding to the
            //  evaluation of the gradient of this patchField
            tmp<Field<Type>> gradientInternalCoeffs() const
            {
                return tmp<Field<Type>>(new Field<Type>(0));
            }

            //- Return the matrix source coefficients corresponding to the
            //  evaluation of the gradient of this patchField
            tmp<Field<Type>> gradientBoundaryCoeffs() const
            {
                return tmp<Field<Type>>(new Field<Type>(0));
            }
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
    #include "emptyFvPatchField.C"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
