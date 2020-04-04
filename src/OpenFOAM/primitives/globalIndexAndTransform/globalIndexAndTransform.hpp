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
    Foam::globalIndexAndTransform

Description
    Determination and storage of the possible independent transforms
    introduced by coupledPolyPatches, as well as all of the possible
    permutations of these transforms generated by the presence of
    multiple coupledPolyPatches, i.e. more than one cyclic boundary. Note that
    any given point can be on maximum 3 transforms only (and these transforms
    have to be perpendicular)

    Also provides global index encoding and decoding for entity
    (i.e. cell) index, processor index and transform index (0 or
    positive integer) to a labelPair.

SourceFiles
    globalIndexAndTransform.C

\*---------------------------------------------------------------------------*/

#ifndef globalIndexAndTransform_H
#define globalIndexAndTransform_H

#include "OpenFOAM/primitives/Pair/labelPair.hpp"
#include "OpenFOAM/primitives/globalIndexAndTransform/vectorTensorTransform/vectorTensorTransform.hpp"
#include "OpenFOAM/containers/HashTables/HashSet/HashSet.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

class polyMesh;


/*---------------------------------------------------------------------------*\
                   Class globalIndexAndTransform Declaration
\*---------------------------------------------------------------------------*/

class globalIndexAndTransform
{
public:

    // Public classes

        //- Less function class used in sorting encoded transforms and indices
        //  Minimum of:
        //  - processor
        //  - local index
        //  - transform
        class less
        {
            const globalIndexAndTransform& gi_;

        public:

            less(const globalIndexAndTransform& gi)
            :
                gi_(gi)
            {}

            inline bool operator()(const labelPair&, const labelPair&) const;
        };


private:

    // Private data

        //- Reference to mesh
        const polyMesh& mesh_;

        //- The possible independent (non-permuted) transforms of the
        //  geometry, i.e. for a geometry with two cyclics, this
        //  stores the two transforms, not the eight permutations.
        //  Any point can not be on more than three transforms but overall
        //  the mesh can have more than three.
        List<vectorTensorTransform> transforms_;

        //- The permutations of the transforms, stored for lookup
        //  efficiency.  If there are n transforms, then there are
        //  (3^n) permutations, including the no-transformation
        //  transform.
        List<vectorTensorTransform> transformPermutations_;

        //- Index of identity transform.
        label nullTransformIndex_;

        //- Mapping from patch index to which transform it matches (or
        //  -1 for none) (.first()) and what sign to use for it,
        //  i.e. +/- 1 (.second()).
        List<labelPair> patchTransformSign_;


    // Private Member Functions

        //- Determine all of the independent basic transforms of the
        //  geometry by analysing the coupledPolyPatches
        void determineTransforms();

        //- Generate all of the transformation permutations
        void determineTransformPermutations();

        //- Determine which patch uses which transform (if any) and which
        //  sign to use
        void determinePatchTransformSign();

        //- Test a list of reference transforms to see if the test
        //  transform matches one.  Return +1 or -1 depending on the
        //  sign of the match, or 0 if none matches.
        label matchTransform
        (
            const List<vectorTensorTransform>& refTransforms,
            label& matchedRefTransformI,
            const vectorTensorTransform& testTransform,
            scalar tolerance,
            bool checkBothSigns
        ) const;

        //- Return true if transform is not yet present in trafos. Issues
        //  warning if too many transforms
        bool uniqueTransform
        (
            const point& pt,
            labelPairList& trafos,
            const label patchi,
            const labelPair& patchTrafo
        ) const;

        //- Disallow default bitwise copy construct
        globalIndexAndTransform(const globalIndexAndTransform&);

        //- Disallow default bitwise assignment
        void operator=(const globalIndexAndTransform&);


public:

    // Declare name of the class and its debug switch
    ClassName("globalIndexAndTransform");


    // Constructors

        //- Construct from components
        globalIndexAndTransform(const polyMesh& mesh);


    // Member Functions

        //- Generate a transform index from the permutation indices of
        //  the independent transforms.  Permutations indices must
        //  only be -1, 0 or +1.
        inline label encodeTransformIndex
        (
            const labelList& permutationIndices
        ) const;

        //- Decode transform index
        inline labelList decodeTransformIndex(const label transformIndex) const;

        //- Add patch transformation to transformIndex. Return new
        //  transformIndex. (by default the patch is the sending, not the
        //  receiving, patch)
        inline label addToTransformIndex
        (
            const label transformIndex,
            const label patchi,
            const bool isSendingSide = true,
            const scalar tol = small
        ) const;

        //- Combine two transformIndices
        inline label mergeTransformIndex
        (
            const label transformIndex0,
            const label transformIndex1
        ) const;

        //- Combine two transformIndices
        inline label minimumTransformIndex
        (
            const label transformIndex0,
            const label transformIndex1
        ) const;

        //- Subtract two transformIndices
        inline label subtractTransformIndex
        (
            const label transformIndex0,
            const label transformIndex1
        ) const;

        //- Encode index and bare index as components on own processor
        inline labelPair encode
        (
            const label index,
            const label transformIndex
        ) const;

        //- Encode index and bare index as components on given processor
        inline labelPair encode
        (
            const label proci,
            const label index,
            const label transformIndex
        ) const;

        //- Index carried by the object
        inline label index(const labelPair& globalIAndTransform) const;

        //- Which processor does this come from?
        inline label processor(const labelPair& globalIAndTransform) const;

        //- Transform carried by the object
        inline label transformIndex(const labelPair& globalIAndTransform) const;

        //- Return the number of independent transforms
        inline label nIndependentTransforms() const;

        //- Return access to the stored independent transforms
        inline const List<vectorTensorTransform>& transforms() const;

        //- Return access to the permuted transforms
        inline const List<vectorTensorTransform>&
        transformPermutations() const;

        //- Return the transformIndex (index in transformPermutations)
        //  of the identity transform
        inline label nullTransformIndex() const;

        //- Return access to the per-patch transform-sign pairs
        inline const List<labelPair>& patchTransformSign() const;

        //- Access the overall (permuted) transform corresponding
        //  to the transformIndex
        inline const vectorTensorTransform& transform
        (
            label transformIndex
        ) const;

        //- Access the all of the indices of the transform
        //  permutations corresponding the transforms of the
        //  listed patch indices. This only allows a maximum of three
        //  transformations (since routine is used to transform points and
        //  any given point can only be on 3 or less transforms)
        inline labelList transformIndicesForPatches
        (
            const labelHashSet& patchIs
        ) const;

        //- Apply all of the transform permutations
        //  corresponding the transforms of the listed patch
        //  indices to the supplied point
        inline pointField transformPatches
        (
            const labelHashSet& patchIs,
            const point& pt
        ) const;

};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "OpenFOAM/primitives/globalIndexAndTransform/globalIndexAndTransformI.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
