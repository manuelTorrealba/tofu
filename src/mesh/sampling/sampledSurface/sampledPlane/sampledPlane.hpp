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
    Foam::sampledPlane

Description
    A sampledSurface defined by a plane which 'cuts' the mesh using the
    cuttingPlane alorithm.  The plane is triangulated by default.

Note
    Does not actually cut until update() called.

SourceFiles
    sampledPlane.C

\*---------------------------------------------------------------------------*/

#ifndef sampledPlane_H
#define sampledPlane_H

#include "sampling/sampledSurface/sampledSurface/sampledSurface.hpp"
#include "sampling/cuttingPlane/cuttingPlane.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                        Class sampledPlane Declaration
\*---------------------------------------------------------------------------*/

class sampledPlane
:
    public sampledSurface,
    public cuttingPlane
{
    // Private data

        //- If restricted to zones, name of this zone or a regular expression
        keyType zoneKey_;

        //- Triangulated faces or keep faces as is
        const bool triangulate_;

        //- Track if the surface needs an update
        mutable bool needsUpdate_;

    // Private Member Functions

        //- Sample field on faces
        template<class Type>
        tmp<Field<Type>> sampleField
        (
            const GeometricField<Type, fvPatchField, volMesh>& vField
        ) const;


        template<class Type>
        tmp<Field<Type>>
        interpolateField(const interpolation<Type>&) const;


public:

    //- Runtime type information
    TypeName("sampledPlane");


    // Constructors

        //- Construct from components
        sampledPlane
        (
            const word& name,
            const polyMesh& mesh,
            const plane& planeDesc,
            const keyType& zoneKey = word::null,
            const bool triangulate = true
        );

        //- Construct from dictionary
        sampledPlane
        (
            const word& name,
            const polyMesh& mesh,
            const dictionary& dict
        );


    //- Destructor
    virtual ~sampledPlane();


    // Member Functions

        //- Does the surface need an update?
        virtual bool needsUpdate() const;

        //- Mark the surface as needing an update.
        //  May also free up unneeded data.
        //  Return false if surface was already marked as expired.
        virtual bool expire();

        //- Update the surface as required.
        //  Do nothing (and return false) if no update was needed
        virtual bool update();


        //- Points of surface
        virtual const pointField& points() const
        {
            return cuttingPlane::points();
        }

        //- Faces of surface
        virtual const faceList& faces() const
        {
            return cuttingPlane::faces();
        }

        //- For every face original cell in mesh
        const labelList& meshCells() const
        {
            return cuttingPlane::cutCells();
        }

        //- Sample field on surface
        virtual tmp<scalarField> sample
        (
            const volScalarField&
        ) const;


        //- Sample field on surface
        virtual tmp<vectorField> sample
        (
            const volVectorField&
        ) const;

        //- Sample field on surface
        virtual tmp<sphericalTensorField> sample
        (
            const volSphericalTensorField&
        ) const;

        //- Sample field on surface
        virtual tmp<symmTensorField> sample
        (
            const volSymmTensorField&
        ) const;

        //- Sample field on surface
        virtual tmp<tensorField> sample
        (
            const volTensorField&
        ) const;


        //- Interpolate field on surface
        virtual tmp<scalarField> interpolate
        (
            const interpolation<scalar>&
        ) const;


        //- Interpolate field on surface
        virtual tmp<vectorField> interpolate
        (
            const interpolation<vector>&
        ) const;

        //- Interpolate field on surface
        virtual tmp<sphericalTensorField> interpolate
        (
            const interpolation<sphericalTensor>&
        ) const;

        //- Interpolate field on surface
        virtual tmp<symmTensorField> interpolate
        (
            const interpolation<symmTensor>&
        ) const;

        //- Interpolate field on surface
        virtual tmp<tensorField> interpolate
        (
            const interpolation<tensor>&
        ) const;

        //- Write
        virtual void print(Ostream&) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#include "sampling/sampledSurface/sampledPlane/sampledPlaneTemplates.cpp"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
