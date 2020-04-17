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

#include "OpenFOAM/primitives/functions/Function1/Constant/Constant.hpp"
#include "OpenFOAM/primitives/functions/Function1/Uniform/Uniform.hpp"
#include "OpenFOAM/primitives/functions/Function1/Zero/ZeroConstant.hpp"
#include "OpenFOAM/primitives/functions/Function1/One/OneConstant.hpp"
#include "OpenFOAM/primitives/functions/Function1/PolynomialEntry/PolynomialEntry.hpp"
#include "OpenFOAM/primitives/functions/Function1/Sine/Sine.hpp"
#include "OpenFOAM/primitives/functions/Function1/Square/Square.hpp"
#include "OpenFOAM/primitives/functions/Function1/CSV/CSV.hpp"
#include "OpenFOAM/primitives/functions/Function1/Table/Table.hpp"
#include "OpenFOAM/primitives/functions/Function1/TableFile/TableFile.hpp"
#include "OpenFOAM/primitives/functions/Function1/Scale/Scale.hpp"

#include "OpenFOAM/fields/Fields/fieldTypes.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define makeFunction1s(Type)                                                   \
    makeFunction1(Type);                                                       \
    makeFunction1Type(Constant, Type);                                         \
    makeFunction1Type(Uniform, Type);                                          \
    makeFunction1Type(ZeroConstant, Type);                                     \
    makeFunction1Type(OneConstant, Type);                                      \
    makeFunction1Type(Polynomial, Type);                                       \
    makeFunction1Type(Sine, Type);                                             \
    makeFunction1Type(Square, Type);                                           \
    makeFunction1Type(CSV, Type);                                              \
    makeFunction1Type(Table, Type);                                            \
    makeFunction1Type(TableFile, Type);                                        \
    makeFunction1Type(Scale, Type);

namespace Foam
{
    makeFunction1(label);
    makeFunction1Type(Constant, label);

    makeFunction1s(scalar);
    makeFunction1s(vector);
    makeFunction1s(sphericalTensor);
    makeFunction1s(symmTensor);
    makeFunction1s(tensor);
}


template<>
Foam::tmp<Foam::Field<Foam::label>>
Foam::Function1Types::Constant<Foam::label>::integrate
(
    const scalarField& x1,
    const scalarField& x2
) const
{
    NotImplemented;
    return tmp<Field<label>>(new Field<label>(x1.size()));
}


// ************************************************************************* //
