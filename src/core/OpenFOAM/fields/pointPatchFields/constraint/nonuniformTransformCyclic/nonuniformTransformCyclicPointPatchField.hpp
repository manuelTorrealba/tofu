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
    Foam::nonuniformTransformCyclicPointPatchField

Description
    Cyclic + slip constraints

SourceFiles
    nonuniformTransformCyclicPointPatchField.C

\*---------------------------------------------------------------------------*/

#ifndef nonuniformTransformCyclicPointPatchField_H
#define nonuniformTransformCyclicPointPatchField_H

#include "OpenFOAM/fields/pointPatchFields/constraint/cyclic/cyclicPointPatchField.hpp"
#include "OpenFOAM/meshes/pointMesh/pointPatches/constraint/nonuniformTransformCyclic/nonuniformTransformCyclicPointPatch.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                    Class nonuniformTransformCyclicPointPatchField Declaration
\*---------------------------------------------------------------------------*/

template<class Type>
class nonuniformTransformCyclicPointPatchField
:
    public cyclicPointPatchField<Type>
{

public:

    //- Runtime type information
    TypeName(nonuniformTransformCyclicPointPatch::typeName_());


    // Constructors

        //- Construct from patch and internal field
        nonuniformTransformCyclicPointPatchField
        (
            const pointPatch&,
            const DimensionedField<Type, pointMesh>&
        );

        //- Construct from patch, internal field and dictionary
        nonuniformTransformCyclicPointPatchField
        (
            const pointPatch&,
            const DimensionedField<Type, pointMesh>&,
            const dictionary&
        );

        //- Construct by mapping given patchField<Type> onto a new patch
        nonuniformTransformCyclicPointPatchField
        (
            const nonuniformTransformCyclicPointPatchField<Type>&,
            const pointPatch&,
            const DimensionedField<Type, pointMesh>&,
            const pointPatchFieldMapper&
        );

        //- Construct and return a clone
        virtual autoPtr<pointPatchField<Type>> clone() const
        {
            return autoPtr<pointPatchField<Type>>
            (
                new nonuniformTransformCyclicPointPatchField<Type>
                (
                    *this
                )
            );
        }

        //- Construct as copy setting internal field reference
        nonuniformTransformCyclicPointPatchField
        (
            const nonuniformTransformCyclicPointPatchField<Type>&,
            const DimensionedField<Type, pointMesh>&
        );

        //- Construct and return a clone setting internal field reference
        virtual autoPtr<pointPatchField<Type>> clone
        (
            const DimensionedField<Type, pointMesh>& iF
        ) const
        {
            return autoPtr<pointPatchField<Type>>
            (
                new nonuniformTransformCyclicPointPatchField<Type>
                (
                    *this, iF
                )
            );
        }


    // Member functions

        //- Evaluate the patch field
        virtual void evaluate
        (
            const Pstream::commsTypes commsType=Pstream::commsTypes::blocking
        );
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#include "OpenFOAM/fields/pointPatchFields/constraint/nonuniformTransformCyclic/nonuniformTransformCyclicPointPatchField.cpp"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
