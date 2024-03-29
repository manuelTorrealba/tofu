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

Global
    movingMeshContinuityErrs

Description
    Calculates and prints the continuity errors for moving mesh calculation.

\*---------------------------------------------------------------------------*/

if (mesh.moving())
{
    scalar sumLocalContErr = runTime.deltaTValue()*
        mag(fvc::div(phi + fvc::meshPhi(rho, U)))()
       .weightedAverage(mesh.V()).value();

    scalar globalContErr = runTime.deltaTValue()*
        fvc::div(phi + fvc::meshPhi(rho, U))()
       .weightedAverage(mesh.V()).value();

    cumulativeContErr += globalContErr;

    Info<< "time step continuity errors : sum local = " << sumLocalContErr
        << ", global = " << globalContErr
        << ", cumulative = " << cumulativeContErr
        << endl;
}
else
{
#include "finiteVolume/cfdTools/incompressible/continuityErrs.hpp"
}

// ************************************************************************* //
