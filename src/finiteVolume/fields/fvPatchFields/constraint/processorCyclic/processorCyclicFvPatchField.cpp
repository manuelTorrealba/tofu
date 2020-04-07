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

\*---------------------------------------------------------------------------*/

#include "finiteVolume/fields/fvPatchFields/constraint/processorCyclic/processorCyclicFvPatchField.hpp"
#include "finiteVolume/fvMesh/fvPatches/constraint/processorCyclic/processorCyclicFvPatch.hpp"
#include "OpenFOAM/include/demandDrivenData.hpp"
#include "OpenFOAM/fields/Fields/transformField/transformField.hpp"

// * * * * * * * * * * * * * * * * Constructors * * * * * * * * * * * * * * //

template<class Type>
Foam::processorCyclicFvPatchField<Type>::processorCyclicFvPatchField
(
    const fvPatch& p,
    const DimensionedField<Type, volMesh>& iF
)
:
    processorFvPatchField<Type>(p, iF),
    procPatch_(refCast<const processorCyclicFvPatch>(p))
{}


template<class Type>
Foam::processorCyclicFvPatchField<Type>::processorCyclicFvPatchField
(
    const fvPatch& p,
    const DimensionedField<Type, volMesh>& iF,
    const dictionary& dict
)
:
    processorFvPatchField<Type>(p, iF, dict),
    procPatch_(refCast<const processorCyclicFvPatch>(p))
{
    if (!isType<processorCyclicFvPatch>(p))
    {
        FatalIOErrorInFunction
        (
            dict
        )   << "\n    patch type '" << p.type()
            << "' not constraint type '" << typeName << "'"
            << "\n    for patch " << p.name()
            << " of field " << this->internalField().name()
            << " in file " << this->internalField().objectPath()
            << exit(FatalIOError);
    }

    if (Pstream::defaultCommsType == Pstream::commsTypes::scheduled)
    {
        WarningInFunction
            << "Scheduled communication with split cyclics not supported."
            << endl;
    }
}


template<class Type>
Foam::processorCyclicFvPatchField<Type>::processorCyclicFvPatchField
(
    const fvPatch& p,
    const DimensionedField<Type, volMesh>& iF,
    const Field<Type>& f
)
:
    processorFvPatchField<Type>(p, iF, f),
    procPatch_(refCast<const processorCyclicFvPatch>(p))
{}


template<class Type>
Foam::processorCyclicFvPatchField<Type>::processorCyclicFvPatchField
(
    const processorCyclicFvPatchField<Type>& ptf,
    const fvPatch& p,
    const DimensionedField<Type, volMesh>& iF,
    const fvPatchFieldMapper& mapper
)
:
    processorFvPatchField<Type>(ptf, p, iF, mapper),
    procPatch_(refCast<const processorCyclicFvPatch>(p))
{
    if (!isType<processorCyclicFvPatch>(this->patch()))
    {
        FatalErrorInFunction
            << "' not constraint type '" << typeName << "'"
            << "\n    for patch " << p.name()
            << " of field " << this->internalField().name()
            << " in file " << this->internalField().objectPath()
            << exit(FatalIOError);
    }
}


template<class Type>
Foam::processorCyclicFvPatchField<Type>::processorCyclicFvPatchField
(
    const processorCyclicFvPatchField<Type>& ptf
)
:
    processorFvPatchField<Type>(ptf),
    procPatch_(refCast<const processorCyclicFvPatch>(ptf.patch()))
{}


template<class Type>
Foam::processorCyclicFvPatchField<Type>::processorCyclicFvPatchField
(
    const processorCyclicFvPatchField<Type>& ptf,
    const DimensionedField<Type, volMesh>& iF
)
:
    processorFvPatchField<Type>(ptf, iF),
    procPatch_(refCast<const processorCyclicFvPatch>(ptf.patch()))
{}


// * * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * //

template<class Type>
Foam::processorCyclicFvPatchField<Type>::~processorCyclicFvPatchField()
{}


// ************************************************************************* //
