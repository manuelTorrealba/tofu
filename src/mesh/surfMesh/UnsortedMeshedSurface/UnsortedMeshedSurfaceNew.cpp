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

#include "surfMesh/UnsortedMeshedSurface/UnsortedMeshedSurface.hpp"

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class Face>
Foam::autoPtr<Foam::UnsortedMeshedSurface<Face>>
Foam::UnsortedMeshedSurface<Face>::New(const fileName& name, const word& ext)
{
    if (debug)
    {
        InfoInFunction << "Constructing UnsortedMeshedSurface" << endl;
    }

    typename fileExtensionConstructorTable::iterator cstrIter =
        fileExtensionConstructorTablePtr_->find(ext);

    if (cstrIter == fileExtensionConstructorTablePtr_->end())
    {
        // no direct reader, use the parent if possible
        wordHashSet supported = ParentType::readTypes();
        if (supported.found(ext))
        {
            // create indirectly
            autoPtr<UnsortedMeshedSurface<Face>> surf
            (
                new UnsortedMeshedSurface<Face>
            );
            surf().transfer(ParentType::New(name, ext)());

            return surf;
        }

        // nothing left but to issue an error
        supported += readTypes();

        FatalErrorInFunction
            << "Unknown file extension " << ext << nl << nl
            << "Valid types are:" << nl
            << supported
            << exit(FatalError);
    }

    return autoPtr<UnsortedMeshedSurface<Face>>(cstrIter()(name));
}


template<class Face>
Foam::autoPtr<Foam::UnsortedMeshedSurface<Face>>
Foam::UnsortedMeshedSurface<Face>::New(const fileName& name)
{
    word ext = name.ext();
    if (ext == "gz")
    {
        ext = name.lessExt().ext();
    }

    return New(name, ext);
}


// ************************************************************************* //
