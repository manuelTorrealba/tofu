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
    Foam::ensightParts

Description
    A collection of several ensightPart elements

SourceFiles
    ensightParts.C
    ensightPartsTemplates.C

\*---------------------------------------------------------------------------*/

#ifndef ensightParts_H
#define ensightParts_H

#include "conversion/ensight/part/ensightPart.hpp"
#include "conversion/ensight/part/ensightPartFaces.hpp"
#include "conversion/ensight/part/ensightPartCells.hpp"
#include "finiteVolume/fields/volFields/volFields.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward declaration of friend functions and operators

class ensightParts;

ensightGeoFile& operator<<(ensightGeoFile&, const ensightParts&);


/*---------------------------------------------------------------------------*\
                       Class ensightParts Declaration
\*---------------------------------------------------------------------------*/

class ensightParts
{
    // Private Data

        //- List of parts
        PtrList<ensightPart> partsList_;

    // Private Member Functions

        //- Disallow default bitwise copy construct
        ensightParts(const ensightParts&);

        //- Disallow default bitwise assignment
        void operator=(const ensightParts&);


public:

    // Constructors

        //- Construct from polyMesh
        ensightParts(const polyMesh&);

        //- Construct from IOobject
        ensightParts(const IOobject&);


    //- Destructor
    ~ensightParts();


    // Member functions

        //- Clear old information and construct anew from polyMesh
        void recalculate(const polyMesh&);

        //- Renumber elements
        void renumber
        (
            const labelUList& origCellId,
            const labelUList& origFaceId
        );

        //- Number of parts
        label size() const
        {
            return partsList_.size();
        }

        //- Write the geometry
        void writeGeometry(ensightGeoFile&) const;

        //- Write summary information about the objects
        bool writeSummary(Ostream&) const;

        //- Write the lists
        void writeData(Ostream&) const;

        //- Write (volume) scalar field
        //  optionally write data for face parts
        //  optionally write data per node
        void writeScalarField
        (
            ensightFile&,
            const List<scalar>& field,
            const bool useFaceData = false,
            const bool perNode = false
        ) const;

        //- Write (volume) vector field components
        //  optionally write data for face parts
        //  optionally write data per node
        void writeVectorField
        (
            ensightFile&,
            const List<scalar>& field0,
            const List<scalar>& field1,
            const List<scalar>& field2,
            const bool useFaceData = false,
            const bool perNode = false
        ) const;


        //- Write generalized volume field components
        template<class Type>
        void writeField
        (
            ensightFile&,
            const GeometricField<Type, fvPatchField, volMesh>&
        ) const;


    // Friend Operators

        //- Write geometry
        friend ensightGeoFile& operator<<(ensightGeoFile&, const ensightParts&);
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#include "conversion/ensight/part/ensightPartsTemplates.cpp"
#endif

#endif

// ************************************************************************* //
