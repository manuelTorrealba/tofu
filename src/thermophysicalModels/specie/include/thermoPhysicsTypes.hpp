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

Typedefs
    Foam::thermoPhysicsTypes

Description
    Type definitions for thermo-physics models

\*---------------------------------------------------------------------------*/

#ifndef thermoPhysicsTypes_H
#define thermoPhysicsTypes_H

#include "thermophysicalModels/specie/specie/specie.hpp"
#include "thermophysicalModels/specie/equationOfState/perfectGas/perfectGas.hpp"
#include "thermophysicalModels/specie/equationOfState/incompressiblePerfectGas/incompressiblePerfectGas.hpp"
#include "thermophysicalModels/specie/equationOfState/perfectFluid/perfectFluid.hpp"
#include "thermophysicalModels/specie/equationOfState/adiabaticPerfectFluid/adiabaticPerfectFluid.hpp"
#include "thermophysicalModels/specie/equationOfState/rhoConst/rhoConst.hpp"
#include "thermophysicalModels/specie/thermo/hConst/hConstThermo.hpp"
#include "thermophysicalModels/specie/thermo/janaf/janafThermo.hpp"

#include "thermophysicalModels/specie/thermo/sensibleEnthalpy/sensibleEnthalpy.hpp"
#include "thermophysicalModels/specie/thermo/sensibleInternalEnergy/sensibleInternalEnergy.hpp"
#include "thermophysicalModels/specie/thermo/thermo/thermo.hpp"
#include "thermophysicalModels/specie/transport/sutherland/sutherlandTransport.hpp"
#include "thermophysicalModels/specie/transport/const/constTransport.hpp"

#include "thermophysicalModels/specie/equationOfState/icoPolynomial/icoPolynomial.hpp"
#include "thermophysicalModels/specie/thermo/hPolynomial/hPolynomialThermo.hpp"
#include "thermophysicalModels/specie/transport/polynomial/polynomialTransport.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
    // thermo physics types based on sensibleEnthalpy
    typedef
    constTransport
    <
        species::thermo
        <
            hConstThermo
            <
                perfectGas<specie>
            >,
            sensibleEnthalpy
        >
    > constGasHThermoPhysics;

    typedef
    sutherlandTransport
    <
        species::thermo
        <
            janafThermo
            <
                perfectGas<specie>
            >,
            sensibleEnthalpy
        >
    > gasHThermoPhysics;

    typedef
    constTransport
    <
        species::thermo
        <
            hConstThermo
            <
                incompressiblePerfectGas<specie>
            >,
            sensibleEnthalpy
        >
    > constIncompressibleGasHThermoPhysics;

    typedef
    sutherlandTransport
    <
        species::thermo
        <
            janafThermo
            <
                incompressiblePerfectGas<specie>
            >,
            sensibleEnthalpy
        >
    > incompressibleGasHThermoPhysics;

    typedef
    polynomialTransport
    <
        species::thermo
        <
            hPolynomialThermo
            <
                icoPolynomial<specie, 8>,
                8
            >,
            sensibleEnthalpy
        >,
        8
    > icoPoly8HThermoPhysics;

    typedef
    constTransport
    <
        species::thermo
        <
            hConstThermo
            <
                perfectFluid<specie>
            >,
            sensibleEnthalpy
        >
    >
    constFluidHThermoPhysics;

    typedef
    constTransport
    <
        species::thermo
        <
            hConstThermo
            <
                adiabaticPerfectFluid<specie>
            >,
            sensibleEnthalpy
        >
    >
    constAdiabaticFluidHThermoPhysics;

    typedef
    constTransport
    <
        species::thermo
        <
            hConstThermo
            <
                rhoConst<specie>
            >,
            sensibleEnthalpy
        >
    >
    constHThermoPhysics;


    // thermo physics types based on sensibleInternalEnergy
    typedef
    constTransport
    <
        species::thermo
        <
            hConstThermo
            <
                perfectGas<specie>
            >,
            sensibleInternalEnergy
        >
    > constGasEThermoPhysics;

    typedef
    sutherlandTransport
    <
        species::thermo
        <
            janafThermo
            <
                perfectGas<specie>
            >,
            sensibleInternalEnergy
        >
    > gasEThermoPhysics;

    typedef
    constTransport
    <
        species::thermo
        <
            hConstThermo
            <
                incompressiblePerfectGas<specie>
            >,
            sensibleInternalEnergy
        >
    > constIncompressibleGasEThermoPhysics;

    typedef
    sutherlandTransport
    <
        species::thermo
        <
            janafThermo
            <
                incompressiblePerfectGas<specie>
            >,
            sensibleInternalEnergy
        >
    > incompressibleGasEThermoPhysics;

    typedef
    polynomialTransport
    <
        species::thermo
        <
            hPolynomialThermo
            <
                icoPolynomial<specie, 8>,
                8
            >,
            sensibleInternalEnergy
        >,
        8
    > icoPoly8EThermoPhysics;

    typedef
    constTransport
    <
        species::thermo
        <
            hConstThermo
            <
                perfectFluid<specie>
            >,
            sensibleInternalEnergy
        >
    >
    constFluidEThermoPhysics;

    typedef
    constTransport
    <
        species::thermo
        <
            hConstThermo
            <
                adiabaticPerfectFluid<specie>
            >,
            sensibleInternalEnergy
        >
    >
    constAdiabaticFluidEThermoPhysics;

    typedef
    constTransport
    <
        species::thermo
        <
            hConstThermo
            <
                rhoConst<specie>
            >,
            sensibleInternalEnergy
        >
    >
    constEThermoPhysics;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
