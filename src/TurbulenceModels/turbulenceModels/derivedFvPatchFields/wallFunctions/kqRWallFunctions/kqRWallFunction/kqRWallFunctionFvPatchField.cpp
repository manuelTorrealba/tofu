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

#include "TurbulenceModels/turbulenceModels/derivedFvPatchFields/wallFunctions/kqRWallFunctions/kqRWallFunction/kqRWallFunctionFvPatchField.hpp"
#include "finiteVolume/fields/fvPatchFields/fvPatchField/fvPatchFieldMapper.hpp"
#include "OpenFOAM/db/runTimeSelection/construction/addToRunTimeSelectionTable.hpp"
#include "finiteVolume/fvMesh/fvPatches/derived/wall/wallFvPatch.hpp"

// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //

template<class Type>
void Foam::kqRWallFunctionFvPatchField<Type>::checkType()
{
    if (!isA<wallFvPatch>(this->patch()))
    {
        FatalErrorInFunction
            << "Invalid wall function specification" << nl
            << "    Patch type for patch " << this->patch().name()
            << " must be wall" << nl
            << "    Current patch type is " << this->patch().type()
            << nl << endl
            << abort(FatalError);
    }
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class Type>
Foam::kqRWallFunctionFvPatchField<Type>::kqRWallFunctionFvPatchField
(
    const fvPatch& p,
    const DimensionedField<Type, volMesh>& iF
)
:
    zeroGradientFvPatchField<Type>(p, iF)
{
    checkType();
}


template<class Type>
Foam::kqRWallFunctionFvPatchField<Type>::kqRWallFunctionFvPatchField
(
    const fvPatch& p,
    const DimensionedField<Type, volMesh>& iF,
    const dictionary& dict
)
:
    zeroGradientFvPatchField<Type>(p, iF, dict)
{
    checkType();
}


template<class Type>
Foam::kqRWallFunctionFvPatchField<Type>::kqRWallFunctionFvPatchField
(
    const kqRWallFunctionFvPatchField& ptf,
    const fvPatch& p,
    const DimensionedField<Type, volMesh>& iF,
    const fvPatchFieldMapper& mapper
)
:
    zeroGradientFvPatchField<Type>(ptf, p, iF, mapper)
{
    checkType();
}


template<class Type>
Foam::kqRWallFunctionFvPatchField<Type>::kqRWallFunctionFvPatchField
(
    const kqRWallFunctionFvPatchField& tkqrwfpf
)
:
    zeroGradientFvPatchField<Type>(tkqrwfpf)
{
    checkType();
}


template<class Type>
Foam::kqRWallFunctionFvPatchField<Type>::kqRWallFunctionFvPatchField
(
    const kqRWallFunctionFvPatchField& tkqrwfpf,
    const DimensionedField<Type, volMesh>& iF
)
:
    zeroGradientFvPatchField<Type>(tkqrwfpf, iF)
{
    checkType();
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class Type>
void Foam::kqRWallFunctionFvPatchField<Type>::evaluate
(
    const Pstream::commsTypes commsType
)
{
    zeroGradientFvPatchField<Type>::evaluate(commsType);
}


template<class Type>
void Foam::kqRWallFunctionFvPatchField<Type>::write(Ostream& os) const
{
    zeroGradientFvPatchField<Type>::write(os);
    this->writeEntry("value", os);
}


// ************************************************************************* //
