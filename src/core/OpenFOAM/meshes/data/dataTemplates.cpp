/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2015-2019 OpenFOAM Foundation
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

#include "OpenFOAM/meshes/data/data.hpp"
#include "OpenFOAM/db/Time/Time.hpp"
#include "OpenFOAM/matrices/LduMatrixN/LduMatrix/solverPerformance.hpp"

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class Type>
void Foam::data::setSolverPerformance
(
    const word& name,
    const SolverPerformance<Type>& sp
) const
{
    dictionary& dict = const_cast<dictionary&>(solverPerformanceDict());

    List<SolverPerformance<Type>> perfs;

    const label timeIndex =
        this->time().subCycling()
      ? this->time().prevTimeState().timeIndex()
      : this->time().timeIndex();

    if (prevTimeIndex_ != timeIndex)
    {
        // Reset solver performance between iterations
        prevTimeIndex_ = timeIndex;
        dict.clear();
    }
    else
    {
        dict.readIfPresent(name, perfs);
    }

    // Append to list
    perfs.setSize(perfs.size()+1, sp);

    dict.set(name, perfs);
}


template<class Type>
void Foam::data::setSolverPerformance
(
    const SolverPerformance<Type>& sp
) const
{
    setSolverPerformance(sp.fieldName(), sp);
}


// ************************************************************************* //
