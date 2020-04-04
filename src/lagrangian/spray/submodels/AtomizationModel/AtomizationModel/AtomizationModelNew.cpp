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

#include "AtomizationModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

template<class CloudType>
Foam::autoPtr<Foam::AtomizationModel<CloudType>>
Foam::AtomizationModel<CloudType>::New
(
    const dictionary& dict,
    CloudType& owner
)
{
    word AtomizationModelType(dict.lookup("atomizationModel"));

    Info<< "Selecting AtomizationModel " << AtomizationModelType << endl;

    typename dictionaryConstructorTable::iterator cstrIter =
        dictionaryConstructorTablePtr_->find(AtomizationModelType);

    if (cstrIter == dictionaryConstructorTablePtr_->end())
    {
        FatalErrorInFunction
            << "Unknown AtomizationModelType type "
            << AtomizationModelType
            << ", constructor not in hash table" << nl << nl
            << "    Valid AtomizationModel types are:" << nl
            << dictionaryConstructorTablePtr_->sortedToc() << exit(FatalError);
    }

    return autoPtr<AtomizationModel<CloudType>>(cstrIter()(dict, owner));
}


// ************************************************************************* //
