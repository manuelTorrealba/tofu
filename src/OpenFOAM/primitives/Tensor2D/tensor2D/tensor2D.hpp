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

Typedef
    Foam::tensor2D

Description
    Tensor2D or scalars.

SourceFiles
    tensor2D.C

\*---------------------------------------------------------------------------*/

#ifndef tensor2D_H
#define tensor2D_H

#include "OpenFOAM/primitives/Tensor2D/Tensor2D.hpp"
#include "OpenFOAM/primitives/Vector2D/vector2D/vector2D.hpp"
#include "OpenFOAM/primitives/contiguous/contiguous.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

typedef Tensor2D<scalar> tensor2D;

vector2D eigenValues(const tensor2D& t);
vector2D eigenVector
(
    const tensor2D& t,
    const scalar lambda,
    const vector2D& direction1
);
tensor2D eigenVectors(const tensor2D& t, const vector2D& lambdas);
tensor2D eigenVectors(const tensor2D& t);

//- Data associated with tensor2D type are contiguous
template<>
inline bool contiguous<tensor2D>() {return true;}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "OpenFOAM/primitives/SphericalTensor2D/sphericalTensor2D/sphericalTensor2D.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
