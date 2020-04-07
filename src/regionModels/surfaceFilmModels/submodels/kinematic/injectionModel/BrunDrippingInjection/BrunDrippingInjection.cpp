/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2016-2018 OpenFOAM Foundation
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

#include "regionModels/surfaceFilmModels/submodels/kinematic/injectionModel/BrunDrippingInjection/BrunDrippingInjection.hpp"
#include "OpenFOAM/db/runTimeSelection/construction/addToRunTimeSelectionTable.hpp"
#include "regionModels/surfaceFilmModels/kinematicSingleLayer/kinematicSingleLayer.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace regionModels
{
namespace surfaceFilmModels
{

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

defineTypeNameAndDebug(BrunDrippingInjection, 0);
addToRunTimeSelectionTable(injectionModel, BrunDrippingInjection, dictionary);

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

BrunDrippingInjection::BrunDrippingInjection
(
    surfaceFilmRegionModel& film,
    const dictionary& dict
)
:
    injectionModel(type(), film, dict),
    ubarStar_(coeffDict_.lookupOrDefault("ubarStar", 1.62208)),
    dCoeff_(coeffDict_.lookupOrDefault("dCoeff", 3.3)),
    deltaStable_(coeffDict_.lookupOrDefault("deltaStable", scalar(0))),
    diameter_(film.regionMesh().nCells(), -1.0)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

BrunDrippingInjection::~BrunDrippingInjection()
{}


// * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * * //

void BrunDrippingInjection::correct
(
    scalarField& availableMass,
    scalarField& massToInject,
    scalarField& diameterToInject
)
{
    const kinematicSingleLayer& film =
        refCast<const kinematicSingleLayer>(this->film());

    // Calculate available dripping mass
    tmp<volScalarField> tsinAlpha(film.gNorm()/mag(film.g()));
    const scalarField& sinAlpha = tsinAlpha();
    const scalarField& magSf = film.magSf();

    const scalarField& delta = film.delta();
    const scalarField& rho = film.rho();
    const scalarField& sigma = film.sigma();
    const scalar magg = mag(film.g().value());

    forAll(delta, celli)
    {
        bool dripping = false;

        if (sinAlpha[celli] > small && delta[celli] > deltaStable_)
        {
            const scalar rhoc = rho[celli];
            const scalar lc = sqrt(sigma[celli]/(rhoc*magg));
            const scalar deltaStable = max
            (
                3*lc*sqrt(1 - sqr(sinAlpha[celli]))
               /(ubarStar_*sqrt(sinAlpha[celli])*sinAlpha[celli]),
                deltaStable_
            );

            if (delta[celli] > deltaStable)
            {
                const scalar ddelta = max(delta[celli] - deltaStable, 0);

                const scalar massDrip =
                    min(availableMass[celli], max(ddelta*rhoc*magSf[celli], 0));

                if (massDrip > 0)
                {
                    const scalar diam = dCoeff_*lc;
                    diameter_[celli] = diam;

                    massToInject[celli] += massDrip;
                    availableMass[celli] -= massDrip;

                    diameterToInject[celli] = diam;
                    addToInjectedMass(massDrip);

                    dripping = true;
                }
            }
        }

        if (!dripping)
        {
            diameterToInject[celli] = 0;
            massToInject[celli] = 0;
        }
    }

    injectionModel::correct();
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace surfaceFilmModels
} // End namespace regionModels
} // End namespace Foam

// ************************************************************************* //
