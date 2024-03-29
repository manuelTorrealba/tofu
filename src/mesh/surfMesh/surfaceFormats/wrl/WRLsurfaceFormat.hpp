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

Class
    Foam::fileFormats::WRLsurfaceFormat

Description
    Provide a means of writing VRML97 (wrl) format.

SourceFiles
    WRLsurfaceFormat.C

\*---------------------------------------------------------------------------*/

#ifndef WRLsurfaceFormat_H
#define WRLsurfaceFormat_H

#include "surfMesh/MeshedSurface/MeshedSurface.hpp"
#include "surfMesh/MeshedSurfaceProxy/MeshedSurfaceProxy.hpp"
#include "surfMesh/UnsortedMeshedSurface/UnsortedMeshedSurface.hpp"
#include "surfMesh/surfaceFormats/wrl/WRLsurfaceFormatCore.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace fileFormats
{

/*---------------------------------------------------------------------------*\
                      Class WRLsurfaceFormat Declaration
\*---------------------------------------------------------------------------*/

template<class Face>
class WRLsurfaceFormat
:
    public MeshedSurface<Face>,
    public WRLsurfaceFormatCore

{
    // Private Member Functions

        //- Disallow default bitwise copy construct
        WRLsurfaceFormat(const WRLsurfaceFormat<Face>&);

        //- Disallow default bitwise assignment
        void operator=(const WRLsurfaceFormat<Face>&);

public:

    // Constructors

        //- Construct null
        WRLsurfaceFormat();


    //- Destructor
    virtual ~WRLsurfaceFormat()
    {}


    // Member Functions

        //- Write surface mesh components by proxy
        static void write(const fileName&, const MeshedSurfaceProxy<Face>&);

        //- Write object file
        virtual void write(const fileName& name) const
        {
            write(name, MeshedSurfaceProxy<Face>(*this));
        }

};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace fileFormats
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#include "surfMesh/surfaceFormats/wrl/WRLsurfaceFormat.cpp"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
