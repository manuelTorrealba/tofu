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
    Foam::fvSurfaceMapper

Description
    FV surface mapper.

SourceFiles
    fvSurfaceMapper.C

\*---------------------------------------------------------------------------*/

#ifndef fvSurfaceMapper_H
#define fvSurfaceMapper_H

#include "OpenFOAM/meshes/polyMesh/mapPolyMesh/morphFieldMapper.hpp"
#include "finiteVolume/fvMesh/fvMesh.hpp"
#include "OpenFOAM/meshes/polyMesh/mapPolyMesh/faceMapper/faceMapper.hpp"
#include "OpenFOAM/containers/HashTables/HashSet/HashSet.hpp"
#include "OpenFOAM/meshes/polyMesh/mapPolyMesh/mapPolyMesh.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward declaration of classes

/*---------------------------------------------------------------------------*\
                         Class fvSurfaceMapper Declaration
\*---------------------------------------------------------------------------*/

class fvSurfaceMapper
:
    public morphFieldMapper
{
    // Private data

        //- Reference to mesh
        const fvMesh& mesh_;

        //- Reference to face mapper
        const faceMapper& faceMap_;


    // Demand-driven private data

        //- Direct addressing (only one for of addressing is used)
        mutable labelList* directAddrPtr_;

        //- Interpolated addressing (only one for of addressing is used)
        mutable labelListList* interpolationAddrPtr_;

        //- Interpolation weights
        mutable scalarListList* weightsPtr_;

        //- Inserted faces
        mutable labelList* insertedObjectLabelsPtr_;



    // Private Member Functions

        //- Disallow default bitwise copy construct
        fvSurfaceMapper(const fvSurfaceMapper&);

        //- Disallow default bitwise assignment
        void operator=(const fvSurfaceMapper&);


        //- Calculate addressing
        void calcAddressing() const;

        //- Clear out local storage
        void clearOut();


public:

    // Constructors

        //- Construct from components
        fvSurfaceMapper
        (
            const fvMesh& mesh,
            const faceMapper& fMapper
        );


    //- Destructor
    virtual ~fvSurfaceMapper();


    // Member Functions

        //- Return size
        virtual label size() const
        {
            return mesh_.nInternalFaces();
        }

        //- Return size of field before mapping
        virtual label sizeBeforeMapping() const
        {
            return faceMap_.internalSizeBeforeMapping();
        }

        //- Is the mapping direct
        virtual bool direct() const
        {
            return faceMap_.direct();
        }

        //- Has unmapped elements
        virtual bool hasUnmapped() const
        {
            return insertedObjects();
        }

        //- Return direct addressing
        virtual const labelUList& directAddressing() const;

        //- Return interpolated addressing
        virtual const labelListList& addressing() const;

        //- Return interpolaion weights
        virtual const scalarListList& weights() const;

        //- Are there any inserted faces
        virtual bool insertedObjects() const
        {
            return faceMap_.insertedObjects();
        }

        //- Return list of inserted faces
        virtual const labelList& insertedObjectLabels() const;

        //- Return flux flip map
        const labelHashSet& flipFaceFlux() const
        {
            return faceMap_.flipFaceFlux();
        }
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
