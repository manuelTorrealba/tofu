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

Description
    Include the header files for all the primitive types that Fields are
    instantiated for.

\*---------------------------------------------------------------------------*/

#ifndef fieldTypes_H
#define fieldTypes_H

#include "OpenFOAM/primitives/ints/label/label.hpp"
#include "OpenFOAM/primitives/Scalar/scalar/scalar.hpp"
#include "OpenFOAM/primitives/Vector/vector/vector.hpp"
#include "OpenFOAM/primitives/SphericalTensor/sphericalTensor/sphericalTensor.hpp"
#include "OpenFOAM/primitives/SymmTensor/symmTensor/symmTensor.hpp"
#include "OpenFOAM/primitives/Tensor/tensor/tensor.hpp"
#include "OpenFOAM/primitives/triad/triad.hpp"
#include "OpenFOAM/include/macros.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define CAPITALIZE_scalar Scalar
#define CAPITALIZE_vector Vector
#define CAPITALIZE_sphericalTensor SphericalTensor
#define CAPITALIZE_symmTensor SymmTensor
#define CAPITALIZE_tensor Tensor

#define FOR_ALL_FIELD_TYPES(Macro, ...)                                        \
    Macro(scalar, __VA_ARGS__)                                                 \
    Macro(vector, __VA_ARGS__)                                                 \
    Macro(sphericalTensor, __VA_ARGS__)                                        \
    Macro(symmTensor, __VA_ARGS__)                                             \
    Macro(tensor, __VA_ARGS__)

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
