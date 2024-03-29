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

#include "OpenFOAM/fields/pointPatchFields/pointPatchField/pointPatchField.hpp"
#include "OpenFOAM/meshes/pointMesh/pointMesh.hpp"
#include "OpenFOAM/db/dictionary/dictionary.hpp"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class Type>
Foam::pointPatchField<Type>::pointPatchField
(
    const pointPatch& p,
    const DimensionedField<Type, pointMesh>& iF
)
:
    patch_(p),
    internalField_(iF),
    updated_(false),
    patchType_(word::null)
{}


template<class Type>
Foam::pointPatchField<Type>::pointPatchField
(
    const pointPatch& p,
    const DimensionedField<Type, pointMesh>& iF,
    const dictionary& dict
)
:
    patch_(p),
    internalField_(iF),
    updated_(false),
    patchType_(dict.lookupOrDefault<word>("patchType", word::null))
{}


template<class Type>
Foam::pointPatchField<Type>::pointPatchField
(
    const pointPatchField<Type>& ptf,
    const pointPatch& p,
    const DimensionedField<Type, pointMesh>& iF,
    const pointPatchFieldMapper&
)
:
    patch_(p),
    internalField_(iF),
    updated_(false),
    patchType_(ptf.patchType_)
{}


template<class Type>
Foam::pointPatchField<Type>::pointPatchField
(
    const pointPatchField<Type>& ptf
)
:
    patch_(ptf.patch_),
    internalField_(ptf.internalField_),
    updated_(false),
    patchType_(ptf.patchType_)
{}


template<class Type>
Foam::pointPatchField<Type>::pointPatchField
(
    const pointPatchField<Type>& ptf,
    const DimensionedField<Type, pointMesh>& iF
)
:
    patch_(ptf.patch_),
    internalField_(iF),
    updated_(false),
    patchType_(ptf.patchType_)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class Type>
const Foam::objectRegistry& Foam::pointPatchField<Type>::db() const
{
    return patch_.boundaryMesh().mesh()();
}


template<class Type>
void Foam::pointPatchField<Type>::write(Ostream& os) const
{
    os.writeKeyword("type") << type() << token::END_STATEMENT << nl;

    if (patchType_.size())
    {
        os.writeKeyword("patchType") << patchType_
            << token::END_STATEMENT << nl;
    }
}


template<class Type>
template<class EntryType>
void Foam::pointPatchField<Type>::writeEntryIfDifferent
(
    Ostream& os,
    const word& entryName,
    const EntryType& value1,
    const EntryType& value2
) const
{
    if (value1 != value2)
    {
        os.writeKeyword(entryName) << value2 << token::END_STATEMENT << nl;
    }
}


template<class Type>
Foam::tmp<Foam::Field<Type>>
Foam::pointPatchField<Type>::patchInternalField() const
{
    return patchInternalField(primitiveField());
}


template<class Type>
template<class Type1>
Foam::tmp<Foam::Field<Type1>>
Foam::pointPatchField<Type>::patchInternalField
(
    const Field<Type1>& iF,
    const labelList& meshPoints
) const
{
    // Check size
    if (iF.size() != primitiveField().size())
    {
        FatalErrorInFunction
            << "given internal field does not correspond to the mesh. "
            << "Field size: " << iF.size()
            << " mesh size: " << primitiveField().size()
            << abort(FatalError);
    }

    return tmp<Field<Type1>>(new Field<Type1>(iF, meshPoints));
}


template<class Type>
template<class Type1>
Foam::tmp<Foam::Field<Type1>>
Foam::pointPatchField<Type>::patchInternalField
(
    const Field<Type1>& iF
) const
{
    return patchInternalField(iF, patch().meshPoints());
}


template<class Type>
template<class Type1>
void Foam::pointPatchField<Type>::addToInternalField
(
    Field<Type1>& iF,
    const Field<Type1>& pF
) const
{
    // Check size
    if (iF.size() != primitiveField().size())
    {
        FatalErrorInFunction
            << "given internal field does not correspond to the mesh. "
            << "Field size: " << iF.size()
            << " mesh size: " << primitiveField().size()
            << abort(FatalError);
    }

    if (pF.size() != size())
    {
        FatalErrorInFunction
            << "given patch field does not correspond to the mesh. "
            << "Field size: " << pF.size()
            << " mesh size: " << size()
            << abort(FatalError);
    }

    // Get the addressing
    const labelList& mp = patch().meshPoints();

    forAll(mp, pointi)
    {
        iF[mp[pointi]] += pF[pointi];
    }
}


template<class Type>
template<class Type1>
void Foam::pointPatchField<Type>::addToInternalField
(
    Field<Type1>& iF,
    const Field<Type1>& pF,
    const labelList& points
) const
{
    // Check size
    if (iF.size() != primitiveField().size())
    {
        FatalErrorInFunction
            << "given internal field does not correspond to the mesh. "
            << "Field size: " << iF.size()
            << " mesh size: " << primitiveField().size()
            << abort(FatalError);
    }

    if (pF.size() != size())
    {
        FatalErrorInFunction
            << "given patch field does not correspond to the mesh. "
            << "Field size: " << pF.size()
            << " mesh size: " << size()
            << abort(FatalError);
    }

    // Get the addressing
    const labelList& mp = patch().meshPoints();

    forAll(points, i)
    {
        label pointi = points[i];
        iF[mp[pointi]] += pF[pointi];
    }
}


template<class Type>
template<class Type1>
void Foam::pointPatchField<Type>::setInInternalField
(
    Field<Type1>& iF,
    const Field<Type1>& pF,
    const labelList& meshPoints
) const
{
    // Check size
    if (iF.size() != primitiveField().size())
    {
        FatalErrorInFunction
            << "given internal field does not correspond to the mesh. "
            << "Field size: " << iF.size()
            << " mesh size: " << primitiveField().size()
            << abort(FatalError);
    }

    if (pF.size() != meshPoints.size())
    {
        FatalErrorInFunction
            << "given patch field does not correspond to the meshPoints. "
            << "Field size: " << pF.size()
            << " meshPoints size: " << size()
            << abort(FatalError);
    }

    forAll(meshPoints, pointi)
    {
        iF[meshPoints[pointi]] = pF[pointi];
    }
}


template<class Type>
template<class Type1>
void Foam::pointPatchField<Type>::setInInternalField
(
    Field<Type1>& iF,
    const Field<Type1>& pF
) const
{
    setInInternalField(iF, pF, patch().meshPoints());
}


template<class Type>
void Foam::pointPatchField<Type>::evaluate(const Pstream::commsTypes)
{
    if (!updated_)
    {
        updateCoeffs();
    }

    updated_ = false;
}


// * * * * * * * * * * * * * * * IOstream Operators  * * * * * * * * * * * * //

template<class Type>
Foam::Ostream& Foam::operator<<
(
    Ostream& os,
    const pointPatchField<Type>& ptf
)
{
    ptf.write(os);

    os.check("Ostream& operator<<(Ostream&, const pointPatchField<Type>&)");

    return os;
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "OpenFOAM/fields/pointPatchFields/pointPatchField/pointPatchFieldNew.cpp"

// ************************************************************************* //
