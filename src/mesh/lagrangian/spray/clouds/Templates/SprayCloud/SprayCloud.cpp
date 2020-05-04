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

#include "lagrangian/spray/clouds/Templates/SprayCloud/SprayCloud.hpp"
#include "lagrangian/spray/submodels/AtomizationModel/AtomizationModel/AtomizationModel.hpp"
#include "lagrangian/spray/submodels/BreakupModel/BreakupModel/BreakupModel.hpp"

// * * * * * * * * * * * * * Protected Member Functions  * * * * * * * * * * //

template<class CloudType>
void Foam::SprayCloud<CloudType>::setModels()
{
    atomizationModel_.reset
    (
        AtomizationModel<SprayCloud<CloudType>>::New
        (
            this->subModelProperties(),
            *this
        ).ptr()
    );

    breakupModel_.reset
    (
        BreakupModel<SprayCloud<CloudType>>::New
        (
            this->subModelProperties(),
            *this
        ).ptr()
    );
}


template<class CloudType>
void Foam::SprayCloud<CloudType>::cloudReset
(
    SprayCloud<CloudType>& c
)
{
    CloudType::cloudReset(c);

    atomizationModel_.reset(c.atomizationModel_.ptr());
    breakupModel_.reset(c.breakupModel_.ptr());
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class CloudType>
Foam::SprayCloud<CloudType>::SprayCloud
(
    const word& cloudName,
    const volScalarField& rho,
    const volVectorField& U,
    const dimensionedVector& g,
    const SLGThermo& thermo,
    bool readFields
)
:
    CloudType(cloudName, rho, U, g, thermo, false),
    sprayCloud(),
    cloudCopyPtr_(nullptr),
    averageParcelMass_(0.0),
    atomizationModel_(nullptr),
    breakupModel_(nullptr)
{
    if (this->solution().active())
    {
        setModels();

        averageParcelMass_ = this->injectors().averageParcelMass();

        if (readFields)
        {
            parcelType::readFields(*this, this->composition());
            this->deleteLostParticles();
        }

        Info << "Average parcel mass: " << averageParcelMass_ << endl;
    }

    if (this->solution().resetSourcesOnStartup())
    {
        CloudType::resetSourceTerms();
    }
}


template<class CloudType>
Foam::SprayCloud<CloudType>::SprayCloud
(
    SprayCloud<CloudType>& c,
    const word& name
)
:
    CloudType(c, name),
    sprayCloud(),
    cloudCopyPtr_(nullptr),
    averageParcelMass_(c.averageParcelMass_),
    atomizationModel_(c.atomizationModel_->clone()),
    breakupModel_(c.breakupModel_->clone())
{}


template<class CloudType>
Foam::SprayCloud<CloudType>::SprayCloud
(
    const fvMesh& mesh,
    const word& name,
    const SprayCloud<CloudType>& c
)
:
    CloudType(mesh, name, c),
    sprayCloud(),
    cloudCopyPtr_(nullptr),
    averageParcelMass_(0.0),
    atomizationModel_(nullptr),
    breakupModel_(nullptr)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

template<class CloudType>
Foam::SprayCloud<CloudType>::~SprayCloud()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class CloudType>
void Foam::SprayCloud<CloudType>::setParcelThermoProperties
(
    parcelType& parcel,
    const scalar lagrangianDt
)
{
    CloudType::setParcelThermoProperties(parcel, lagrangianDt);

    const liquidMixtureProperties& liqMix = this->composition().liquids();

    const scalarField& Y(parcel.Y());
    scalarField X(liqMix.X(Y));
    const scalar pc = this->p()[parcel.cell()];

    // override rho and Cp from constantProperties
    parcel.Cp() = liqMix.Cp(pc, parcel.T(), X);
    parcel.rho() = liqMix.rho(pc, parcel.T(), X);
    parcel.sigma() = liqMix.sigma(pc, parcel.T(), X);
    parcel.mu() = liqMix.mu(pc, parcel.T(), X);
}


template<class CloudType>
void Foam::SprayCloud<CloudType>::checkParcelProperties
(
    parcelType& parcel,
    const scalar lagrangianDt,
    const bool fullyDescribed
)
{
    CloudType::checkParcelProperties(parcel, lagrangianDt, fullyDescribed);

    // store the injection position and initial drop size
    parcel.position0() = parcel.position();
    parcel.d0() = parcel.d();

    parcel.y() = breakup().y0();
    parcel.yDot() = breakup().yDot0();

    parcel.liquidCore() = atomization().initLiquidCore();
}


template<class CloudType>
void Foam::SprayCloud<CloudType>::storeState()
{
    cloudCopyPtr_.reset
    (
        static_cast<SprayCloud<CloudType>*>
        (
            clone(this->name() + "Copy").ptr()
        )
    );
}


template<class CloudType>
void Foam::SprayCloud<CloudType>::restoreState()
{
    cloudReset(cloudCopyPtr_());
    cloudCopyPtr_.clear();
}


template<class CloudType>
void Foam::SprayCloud<CloudType>::evolve()
{
    if (this->solution().canEvolve())
    {
        typename parcelType::trackingData td(*this);

        this->solve(*this, td);
    }
}


template<class CloudType>
void Foam::SprayCloud<CloudType>::info()
{
    CloudType::info();
    scalar d32 = 1.0e+6*this->Dij(3, 2);
    scalar d10 = 1.0e+6*this->Dij(1, 0);
    scalar dMax = 1.0e+6*this->Dmax();
    scalar pen = this->penetration(0.95);

    Info << "    D10, D32, Dmax (mu)             = " << d10 << ", " << d32
         << ", " << dMax << nl
         << "    Liquid penetration 95% mass (m) = " << pen << endl;
}


// ************************************************************************* //
