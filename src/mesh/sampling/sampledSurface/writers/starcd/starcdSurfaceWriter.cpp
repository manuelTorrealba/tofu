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

#include "sampling/sampledSurface/writers/starcd/starcdSurfaceWriter.hpp"

#include "surfMesh/MeshedSurfaceProxy/MeshedSurfaceProxy.hpp"
#include "OpenFOAM/db/IOstreams/Fstreams/OFstream.hpp"
#include "OpenFOAM/include/OSspecific.hpp"

#include "sampling/sampledSurface/writers/makeSurfaceWriterMethods.hpp"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    makeSurfaceWriterType(starcdSurfaceWriter);
}


// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //

namespace Foam
{
    template<>
    inline void Foam::starcdSurfaceWriter::writeData
    (
        Ostream& os,
        const scalar& v
    )
    {
        os  << v << nl;
    }


    template<>
    inline void Foam::starcdSurfaceWriter::writeData
    (
        Ostream& os,
        const vector& v
    )
    {
        os  << v[0] << ' ' << v[1] << ' ' << v[2] << nl;
    }


    template<>
    inline void Foam::starcdSurfaceWriter::writeData
    (
        Ostream& os,
        const sphericalTensor& v
    )
    {
        os  << v[0] << nl;
    }

}


template<class Type>
inline void Foam::starcdSurfaceWriter::writeData
(
    Ostream& os,
    const Type& v
)
{}


template<class Type>
void Foam::starcdSurfaceWriter::writeTemplate
(
    const fileName& outputDir,
    const fileName& surfaceName,
    const pointField& points,
    const faceList& faces,
    const word& fieldName,
    const Field<Type>& values,
    const bool isNodeValues,
    const bool verbose
) const
{
    if (!isDir(outputDir))
    {
        mkDir(outputDir);
    }

    OFstream os(outputDir/fieldName + '_' + surfaceName + ".usr");

    if (verbose)
    {
        Info<< "Writing field " << fieldName << " to " << os.name() << endl;
    }

    // no header, just write values
    forAll(values, elemI)
    {
        os  << elemI+1 << ' ';
        writeData(os, values[elemI]);
    }
}



// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::starcdSurfaceWriter::starcdSurfaceWriter()
:
    surfaceWriter()
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::starcdSurfaceWriter::~starcdSurfaceWriter()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void Foam::starcdSurfaceWriter::write
(
    const fileName& outputDir,
    const fileName& surfaceName,
    const pointField& points,
    const faceList& faces,
    const bool verbose
) const
{
    if (!isDir(outputDir))
    {
        mkDir(outputDir);
    }

    fileName outName(outputDir/surfaceName + ".inp");

    if (verbose)
    {
        Info<< "Writing geometry to " << outName << endl;
    }

    MeshedSurfaceProxy<face>(points, faces).write(outName);
}


// create write methods
defineSurfaceWriterWriteField(Foam::starcdSurfaceWriter, scalar);
defineSurfaceWriterWriteField(Foam::starcdSurfaceWriter, vector);
defineSurfaceWriterWriteField(Foam::starcdSurfaceWriter, sphericalTensor);


// ************************************************************************* //
