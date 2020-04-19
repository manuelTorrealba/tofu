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

Namespace
    Foam::fvc

Description
    Namespace of functions to calculate explicit derivatives.

\*---------------------------------------------------------------------------*/

#ifndef fvc_H
#define fvc_H

#include "finiteVolume/finiteVolume/fv/fv.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "finiteVolume/interpolation/surfaceInterpolation/surfaceInterpolation/surfaceInterpolate.hpp"
#include "finiteVolume/finiteVolume/fvc/fvcVolumeIntegrate.hpp"
#include "finiteVolume/finiteVolume/fvc/fvcSurfaceIntegrate.hpp"
#include "finiteVolume/finiteVolume/fvc/fvcAverage.hpp"
#include "finiteVolume/finiteVolume/fvc/fvcReconstruct.hpp"
#include "finiteVolume/finiteVolume/fvc/fvcDdt.hpp"
#include "finiteVolume/finiteVolume/fvc/fvcDDtL.hpp"
#include "finiteVolume/finiteVolume/fvc/fvcD2dt2.hpp"
#include "finiteVolume/finiteVolume/fvc/fvcDiv.hpp"
#include "finiteVolume/finiteVolume/fvc/fvcFlux.hpp"
#include "finiteVolume/finiteVolume/fvc/fvcGrad.hpp"
#include "finiteVolume/finiteVolume/fvc/fvcMagSqrGradGrad.hpp"
#include "finiteVolume/finiteVolume/fvc/fvcSnGrad.hpp"
#include "finiteVolume/finiteVolume/fvc/fvcCurl.hpp"
#include "finiteVolume/finiteVolume/fvc/fvcLaplacian.hpp"
#include "finiteVolume/finiteVolume/fvc/fvcSup.hpp"
#include "finiteVolume/finiteVolume/fvc/fvcMeshPhi.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
