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

#include "OpenFOAM/matrices/LduMatrixN/Solvers/PCICG/PCICG.hpp"
#include "OpenFOAM/matrices/LduMatrixN/Solvers/PBiCCCG/PBiCCCG.hpp"
#include "OpenFOAM/matrices/LduMatrixN/Solvers/PBiCICG/PBiCICG.hpp"
#include "OpenFOAM/matrices/LduMatrixN/Solvers/SmoothSolver/SmoothSolver.hpp"
#include "OpenFOAM/fields/Fields/fieldTypes.hpp"
#include "OpenFOAM/matrices/LduMatrixN/Solvers/DiagonalSolver/DiagonalSolver.hpp"

#define makeLduSolvers(Type, DType, LUType)                                    \
                                                                               \
    makeLduSolver(DiagonalSolver, Type, DType, LUType);                        \
    makeLduSymSolver(DiagonalSolver, Type, DType, LUType);                     \
    makeLduAsymSolver(DiagonalSolver, Type, DType, LUType);                    \
                                                                               \
    makeLduSolver(PCICG, Type, DType, LUType);                                 \
    makeLduSymSolver(PCICG, Type, DType, LUType);                              \
                                                                               \
    makeLduSolver(PBiCCCG, Type, DType, LUType);                               \
    makeLduAsymSolver(PBiCCCG, Type, DType, LUType);                           \
                                                                               \
    makeLduSolver(PBiCICG, Type, DType, LUType);                               \
    makeLduAsymSolver(PBiCICG, Type, DType, LUType);                           \
                                                                               \
    makeLduSolver(SmoothSolver, Type, DType, LUType);                          \
    makeLduSymSolver(SmoothSolver, Type, DType, LUType);                       \
    makeLduAsymSolver(SmoothSolver, Type, DType, LUType);

namespace Foam
{
    makeLduSolvers(scalar, scalar, scalar);
    makeLduSolvers(vector, scalar, scalar);
    makeLduSolvers(sphericalTensor, scalar, scalar);
    makeLduSolvers(symmTensor, scalar, scalar);
    makeLduSolvers(tensor, scalar, scalar);
};


// ************************************************************************* //
