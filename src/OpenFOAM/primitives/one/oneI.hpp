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

#include "OpenFOAM/primitives/one/one.hpp"
#include "OpenFOAM/primitives/Scalar/scalar/scalar.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

template<class arg2>
class innerProduct<one, arg2>
{
public:

    typedef arg2 type;
};

inline const one& operator*(const one& o, const one&)
{
    return o;
}

template<class Type>
inline const Type& operator*(const Type& t, const one&)
{
    return t;
}

template<class Type>
inline const Type& operator*(const one&, const Type& t)
{
    return t;
}

template<class Type>
inline const Type& operator&(const one&, const Type& t)
{
    return t;
}

inline const one& operator/(const one& o, const one&)
{
    return o;
}

template<class Type>
inline Type operator/(const one&, const Type& t)
{
    return scalar(1)/t;
}

template<class Type>
inline const Type& operator/(const Type& t, const one&)
{
    return t;
}

inline const one& min(const one& o, const one&)
{
    return o;
}

template<class Type>
inline Type min(const one&, const Type& t)
{
    return min(scalar(1), t);
}

template<class Type>
inline Type min(const Type& t, const one&)
{
    return min(t, scalar(1));
}

inline const one& max(const one& o, const one&)
{
    return o;
}

template<class Type>
inline Type max(const one&, const Type& t)
{
    return max(scalar(1), t);
}

template<class Type>
inline Type max(const Type& t, const one&)
{
    return max(t, scalar(1));
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //
