/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2015-2018 OpenFOAM Foundation
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
    Foam::patchDistMethod

Description
    Specialisation of patchDist for wall distance calculation

SourceFiles
    patchDistMethod.C

\*---------------------------------------------------------------------------*/

#ifndef patchDistMethod_H
#define patchDistMethod_H

#include "OpenFOAM/db/dictionary/dictionary.hpp"
#include "OpenFOAM/containers/HashTables/HashSet/HashSet.hpp"
#include "finiteVolume/fields/volFields/volFieldsFwd.hpp"
#include "OpenFOAM/meshes/polyMesh/mapPolyMesh/mapPolyMesh.hpp"
#include "finiteVolume/fields/fvPatchFields/basic/fixedValue/fixedValueFvPatchFields.hpp"
#include "finiteVolume/fields/fvPatchFields/basic/zeroGradient/zeroGradientFvPatchFields.hpp"
#include "OpenFOAM/db/runTimeSelection/construction/runTimeSelectionTables.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

class fvMesh;

/*---------------------------------------------------------------------------*\
                          Class patchDistMethod Declaration
\*---------------------------------------------------------------------------*/

class patchDistMethod
{

protected:

    // Protected Member Data

        //- Reference to the mesh
        const fvMesh& mesh_;

        //- Set of patch IDs
        const labelHashSet patchIDs_;

private:

    // Private Member Functions

        //- Disallow default bitwise copy construct
        patchDistMethod(const patchDistMethod&);

        //- Disallow default bitwise assignment
        void operator=(const patchDistMethod&);

public:

    //- Runtime type information
    TypeName("patchDistMethod");


    // Declare runtime construction

        declareRunTimeSelectionTable
        (
            autoPtr,
            patchDistMethod,
            dictionary,
            (
                const dictionary& dict,
                const fvMesh& mesh,
                const labelHashSet& patchIDs
            ),
            (dict, mesh, patchIDs)
        );


    // Constructors

        //- Construct from mesh and patch ID set
        patchDistMethod
        (
            const fvMesh& mesh,
            const labelHashSet& patchIDs
        );


    // Selectors

        static autoPtr<patchDistMethod> New
        (
            const dictionary& dict,
            const fvMesh& mesh,
            const labelHashSet& patchIDs
        );


    //- Destructor
    virtual ~patchDistMethod();


    // Static Functions

        //- Return the patch types for y and n
        //  These are fixedValue for the set provided otherwise zero-gradient
        template<class Type>
        static wordList patchTypes
        (
            const fvMesh& mesh,
            const labelHashSet& patchIDs
        );


    // Member Functions

        //- Return the patchIDs
        const labelHashSet& patchIDs() const
        {
            return patchIDs_;
        }

        //- Update cached geometry when the mesh moves
        virtual bool movePoints()
        {
            return true;
        }

        //- Update cached topology and geometry when the mesh changes
        virtual void updateMesh(const mapPolyMesh&)
        {}

        //- Correct the given distance-to-patch field
        virtual bool correct(volScalarField& y) = 0;

        //- Correct the given distance-to-patch and normal-to-patch fields
        virtual bool correct(volScalarField& y, volVectorField& n) = 0;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#include "finiteVolume/fvMesh/wallDist/patchDistMethods/patchDistMethod/patchDistMethodTemplates.cpp"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
