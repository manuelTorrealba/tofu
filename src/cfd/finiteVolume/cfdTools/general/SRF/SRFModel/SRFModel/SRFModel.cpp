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

#include "finiteVolume/cfdTools/general/SRF/SRFModel/SRFModel/SRFModel.hpp"
#include "finiteVolume/cfdTools/general/SRF/derivedFvPatchFields/SRFVelocityFvPatchVectorField/SRFVelocityFvPatchVectorField.hpp"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    namespace SRF
    {
        defineTypeNameAndDebug(SRFModel, 0);
        defineRunTimeSelectionTable(SRFModel, dictionary);
    }
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::SRF::SRFModel::SRFModel
(
    const word& type,
    const volVectorField& Urel
)
:
    IOdictionary
    (
        IOobject
        (
            "SRFProperties",
            Urel.time().constant(),
            Urel.db(),
            IOobject::MUST_READ_IF_MODIFIED,
            IOobject::NO_WRITE
        )
    ),
    Urel_(Urel),
    mesh_(Urel_.mesh()),
    origin_("origin", dimLength, lookup("origin")),
    axis_(lookup("axis")),
    SRFModelCoeffs_(optionalSubDict(type + "Coeffs")),
    omega_(dimensionedVector("omega", dimless/dimTime, Zero))
{
    // Normalise the axis
    axis_ /= mag(axis_);
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::SRF::SRFModel::~SRFModel()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

bool Foam::SRF::SRFModel::read()
{
    if (regIOobject::read())
    {
        // Re-read origin
        lookup("origin") >> origin_;

        // Re-read axis
        lookup("axis") >> axis_;
        axis_ /= mag(axis_);

        // Re-read sub-model coeffs
        SRFModelCoeffs_ = optionalSubDict(type() + "Coeffs");

        return true;
    }
    else
    {
        return false;
    }
}


const Foam::dimensionedVector& Foam::SRF::SRFModel::origin() const
{
    return origin_;
}


const Foam::vector& Foam::SRF::SRFModel::axis() const
{
    return axis_;
}


const Foam::dimensionedVector& Foam::SRF::SRFModel::omega() const
{
    return omega_;
}


Foam::tmp<Foam::DimensionedField<Foam::vector, Foam::volMesh>>
Foam::SRF::SRFModel::Fcoriolis() const
{
    return tmp<volVectorField::Internal>
    (
        new volVectorField::Internal
        (
            IOobject
            (
                "Fcoriolis",
                mesh_.time().timeName(),
                mesh_,
                IOobject::NO_READ,
                IOobject::NO_WRITE
            ),
            2.0*omega_ ^ Urel_
        )
    );
}


Foam::tmp<Foam::DimensionedField<Foam::vector, Foam::volMesh>>
Foam::SRF::SRFModel::Fcentrifugal() const
{
    return tmp<volVectorField::Internal>
    (
        new volVectorField::Internal
        (
            IOobject
            (
                "Fcentrifugal",
                mesh_.time().timeName(),
                mesh_,
                IOobject::NO_READ,
                IOobject::NO_WRITE
            ),
            omega_ ^ (omega_ ^ (mesh_.C() - origin_))
        )
    );
}


Foam::tmp<Foam::DimensionedField<Foam::vector, Foam::volMesh>>
Foam::SRF::SRFModel::Su() const
{
    return Fcoriolis() + Fcentrifugal();
}


Foam::vectorField Foam::SRF::SRFModel::velocity
(
    const vectorField& positions
) const
{
    tmp<vectorField> tfld =
        omega_.value()
      ^ (
            (positions - origin_.value())
          - axis_*(axis_ & (positions - origin_.value()))
        );

    return tfld();
}


Foam::tmp<Foam::volVectorField> Foam::SRF::SRFModel::U() const
{
    return tmp<volVectorField>
    (
        new volVectorField
        (
            IOobject
            (
                "Usrf",
                mesh_.time().timeName(),
                mesh_,
                IOobject::NO_READ,
                IOobject::NO_WRITE
            ),
            omega_
          ^ ((mesh_.C() - origin_) - axis_*(axis_ & (mesh_.C() - origin_)))
        )
    );
}


Foam::tmp<Foam::volVectorField> Foam::SRF::SRFModel::Uabs() const
{
    tmp<volVectorField> Usrf = U();

    tmp<volVectorField> tUabs
    (
        new volVectorField
        (
            IOobject
            (
                "Uabs",
                mesh_.time().timeName(),
                mesh_,
                IOobject::NO_READ,
                IOobject::NO_WRITE,
                false
            ),
            Usrf
        )
    );

    volVectorField& Uabs = tUabs.ref();

    // Add SRF contribution to internal field
    Uabs.primitiveFieldRef() += Urel_.primitiveField();

    // Add Urel boundary contributions
    volVectorField::Boundary& Uabsbf = Uabs.boundaryFieldRef();
    const volVectorField::Boundary& bvf = Urel_.boundaryField();

    forAll(bvf, i)
    {
        if (isA<SRFVelocityFvPatchVectorField>(bvf[i]))
        {
            // Only include relative contributions from
            // SRFVelocityFvPatchVectorField's
            const SRFVelocityFvPatchVectorField& UrelPatch =
                refCast<const SRFVelocityFvPatchVectorField>(bvf[i]);
            if (UrelPatch.relative())
            {
                Uabsbf[i] += Urel_.boundaryField()[i];
            }
        }
        else
        {
            Uabsbf[i] += Urel_.boundaryField()[i];
        }
    }

    return tUabs;
}


// ************************************************************************* //
