/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2013-2018 OpenFOAM Foundation
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

#include "TurbulenceModels/compressible/turbulentFluidThermoModels/turbulentFluidThermoModels.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

makeBaseTurbulenceModel
(
    geometricOneField,
    volScalarField,
    compressibleTurbulenceModel,
    CompressibleTurbulenceModel,
    ThermalDiffusivity,
    fluidThermo
);


// -------------------------------------------------------------------------- //
// Laminar models
// -------------------------------------------------------------------------- //

#include "TurbulenceModels/turbulenceModels/laminar/Stokes/Stokes.hpp"
makeLaminarModel(Stokes);

#include "TurbulenceModels/turbulenceModels/laminar/Maxwell/Maxwell.hpp"
makeLaminarModel(Maxwell);


// -------------------------------------------------------------------------- //
// RAS models
// -------------------------------------------------------------------------- //

#include "TurbulenceModels/turbulenceModels/RAS/SpalartAllmaras/SpalartAllmaras.hpp"
makeRASModel(SpalartAllmaras);

#include "TurbulenceModels/turbulenceModels/RAS/kEpsilon/kEpsilon.hpp"
makeRASModel(kEpsilon);

#include "TurbulenceModels/turbulenceModels/RAS/RNGkEpsilon/RNGkEpsilon.hpp"
makeRASModel(RNGkEpsilon);

#include "TurbulenceModels/turbulenceModels/RAS/realizableKE/realizableKE.hpp"
makeRASModel(realizableKE);

#include "TurbulenceModels/compressible/RAS/buoyantKEpsilon/buoyantKEpsilon.hpp"
makeRASModel(buoyantKEpsilon);

#include "TurbulenceModels/turbulenceModels/RAS/LaunderSharmaKE/LaunderSharmaKE.hpp"
makeRASModel(LaunderSharmaKE);

#include "TurbulenceModels/turbulenceModels/RAS/kOmega/kOmega.hpp"
makeRASModel(kOmega);

#include "TurbulenceModels/turbulenceModels/RAS/kOmegaSST/kOmegaSST.hpp"
makeRASModel(kOmegaSST);

#include "TurbulenceModels/turbulenceModels/RAS/kOmegaSSTSAS/kOmegaSSTSAS.hpp"
makeRASModel(kOmegaSSTSAS);

#include "TurbulenceModels/turbulenceModels/RAS/kOmegaSSTLM/kOmegaSSTLM.hpp"
makeRASModel(kOmegaSSTLM);

#include "TurbulenceModels/turbulenceModels/RAS/v2f/v2f.hpp"
makeRASModel(v2f);

#include "TurbulenceModels/turbulenceModels/RAS/LRR/LRR.hpp"
makeRASModel(LRR);

#include "TurbulenceModels/turbulenceModels/RAS/SSG/SSG.hpp"
makeRASModel(SSG);


// -------------------------------------------------------------------------- //
// LES models
// -------------------------------------------------------------------------- //

#include "TurbulenceModels/turbulenceModels/LES/Smagorinsky/Smagorinsky.hpp"
makeLESModel(Smagorinsky);

#include "TurbulenceModels/turbulenceModels/LES/WALE/WALE.hpp"
makeLESModel(WALE);

#include "TurbulenceModels/turbulenceModels/LES/kEqn/kEqn.hpp"
makeLESModel(kEqn);

#include "TurbulenceModels/turbulenceModels/LES/dynamicKEqn/dynamicKEqn.hpp"
makeLESModel(dynamicKEqn);

#include "TurbulenceModels/turbulenceModels/LES/dynamicLagrangian/dynamicLagrangian.hpp"
makeLESModel(dynamicLagrangian);

#include "TurbulenceModels/turbulenceModels/LES/kOmegaSSTDES/kOmegaSSTDES.hpp"
makeLESModel(kOmegaSSTDES);

#include "TurbulenceModels/turbulenceModels/LES/SpalartAllmarasDES/SpalartAllmarasDES.hpp"
makeLESModel(SpalartAllmarasDES);

#include "TurbulenceModels/turbulenceModels/LES/SpalartAllmarasDDES/SpalartAllmarasDDES.hpp"
makeLESModel(SpalartAllmarasDDES);

#include "TurbulenceModels/turbulenceModels/LES/SpalartAllmarasIDDES/SpalartAllmarasIDDES.hpp"
makeLESModel(SpalartAllmarasIDDES);

#include "TurbulenceModels/turbulenceModels/LES/DeardorffDiffStress/DeardorffDiffStress.hpp"
makeLESModel(DeardorffDiffStress);


// ************************************************************************* //
