/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2016-2018 OpenFOAM Foundation
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

#include "extrapolatedCalculatedFvPatchField.H"
#include "fvPatchFieldMapper.H"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class Type>
Foam::extrapolatedCalculatedFvPatchField<Type>::
extrapolatedCalculatedFvPatchField
(
    const fvPatch& p,
    const DimensionedField<Type, volMesh>& iF
)
:
    calculatedFvPatchField<Type>(p, iF)
{}


template<class Type>
Foam::extrapolatedCalculatedFvPatchField<Type>::
extrapolatedCalculatedFvPatchField
(
    const fvPatch& p,
    const DimensionedField<Type, volMesh>& iF,
    const dictionary& dict
)
:
    calculatedFvPatchField<Type>(p, iF, dict, false)
{
    evaluate();
}


template<class Type>
Foam::extrapolatedCalculatedFvPatchField<Type>::
extrapolatedCalculatedFvPatchField
(
    const extrapolatedCalculatedFvPatchField<Type>& ptf,
    const fvPatch& p,
    const DimensionedField<Type, volMesh>& iF,
    const fvPatchFieldMapper& mapper
)
:
    calculatedFvPatchField<Type>(ptf, p, iF, mapper)
{}


template<class Type>
Foam::extrapolatedCalculatedFvPatchField<Type>::
extrapolatedCalculatedFvPatchField
(
    const extrapolatedCalculatedFvPatchField<Type>& ptf
)
:
    calculatedFvPatchField<Type>(ptf)
{}


template<class Type>
Foam::extrapolatedCalculatedFvPatchField<Type>::
extrapolatedCalculatedFvPatchField
(
    const extrapolatedCalculatedFvPatchField<Type>& ptf,
    const DimensionedField<Type, volMesh>& iF
)
:
    calculatedFvPatchField<Type>(ptf, iF)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class Type>
void Foam::extrapolatedCalculatedFvPatchField<Type>::evaluate
(
    const Pstream::commsTypes
)
{
    if (!this->updated())
    {
        this->updateCoeffs();
    }

    calculatedFvPatchField<Type>::operator==(this->patchInternalField());
    calculatedFvPatchField<Type>::evaluate();
}


// ************************************************************************* //
