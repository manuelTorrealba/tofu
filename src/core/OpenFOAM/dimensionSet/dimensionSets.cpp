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

#include "OpenFOAM/dimensionSet/dimensionSet.hpp"
#include "OpenFOAM/dimensionedTypes/dimensionedScalar/dimensionedScalar.hpp"
#include "OpenFOAM/global/debug/simpleRegIOobject.hpp"
#include "OpenFOAM/include/demandDrivenData.hpp"
#include "OpenFOAM/db/dictionary/dictionary.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/* * * * * * * * * * * * * * * Static Member Data  * * * * * * * * * * * * * */

// Since dimensionSystems() can be reread we actually store a copy of
// the controlDict subDict (v.s. a reference to the subDict for e.g.
// dimensionedConstants)
dictionary* dimensionSystemsPtr_(nullptr);
HashTable<dimensionedScalar>* unitSetPtr_(nullptr);
dimensionSets* writeUnitSetPtr_(nullptr);

// Helper class to
//   register re-reader
//   deallocate demand-driven data
class addDimensionSetsToDebug
:
    public ::Foam::simpleRegIOobject
{
public:
    addDimensionSetsToDebug(const char* name)
    :
        ::Foam::simpleRegIOobject(Foam::debug::addDimensionSetObject, name)
    {}
    virtual ~addDimensionSetsToDebug()
    {
        deleteDemandDrivenData(dimensionSystemsPtr_);
        deleteDemandDrivenData(unitSetPtr_);
        deleteDemandDrivenData(writeUnitSetPtr_);

    }
    virtual void readData(Foam::Istream& is)
    {
        deleteDemandDrivenData(dimensionSystemsPtr_);
        deleteDemandDrivenData(unitSetPtr_);
        deleteDemandDrivenData(writeUnitSetPtr_);
        dimensionSystemsPtr_ = new dictionary(is);
    }
    virtual void writeData(Foam::Ostream& os) const
    {
        os << dimensionSystems();
    }
};
addDimensionSetsToDebug addDimensionSetsToDebug_("DimensionSets");


dictionary& dimensionSystems()
{
    if (!dimensionSystemsPtr_)
    {
        dictionary* cachedPtr = nullptr;
        dimensionSystemsPtr_ = new dictionary
        (
            debug::switchSet
            (
                "DimensionSets",
                cachedPtr
            )
        );
    }
    return *dimensionSystemsPtr_;
}


const HashTable<dimensionedScalar>& unitSet()
{
    if (!unitSetPtr_)
    {
        const dictionary& dict = dimensionSystems();

        if (!dict.found("unitSet"))
        {
            FatalIOErrorInFunction(dict)
                << "Cannot find unitSet in dictionary " << dict.name()
                << exit(FatalIOError);
        }

        const word unitSetCoeffs(word(dict.lookup("unitSet")) + "Coeffs");

        if (!dict.found(unitSetCoeffs))
        {
            FatalIOErrorInFunction(dict)
                << "Cannot find " << unitSetCoeffs << " in dictionary "
                << dict.name() << exit(FatalIOError);
        }

        const dictionary& unitDict = dict.subDict(unitSetCoeffs);

        unitSetPtr_ = new HashTable<dimensionedScalar>(unitDict.size());

        forAllConstIter(dictionary, unitDict, iter)
        {
            if (iter().keyword() != "writeUnits")
            {
                dimensionedScalar dt;
                dt.read(iter().stream(), unitDict);
                bool ok = unitSetPtr_->insert(iter().keyword(), dt);
                if (!ok)
                {
                    FatalIOErrorInFunction(dict)
                        << "Duplicate unit " << iter().keyword()
                        << " in DimensionSets dictionary"
                        << exit(FatalIOError);
                }
            }
        }

        wordList writeUnitNames
        (
            unitDict.lookupOrDefault<wordList>
            (
                "writeUnits",
                wordList(0)
            )
        );

        writeUnitSetPtr_ = new dimensionSets(*unitSetPtr_, writeUnitNames);

        if (writeUnitNames.size() != 0 && writeUnitNames.size() != 7)
        {
            FatalIOErrorInFunction(dict)
                << "Cannot find entry \"writeUnits\" in " << unitDict.name()
                << " or it is not a wordList of size 7"
                << exit(FatalIOError);
        }
    }
    return *unitSetPtr_;
}


const dimensionSets& writeUnitSet()
{
    if (!writeUnitSetPtr_)
    {
        (void)unitSet();
    }
    return *writeUnitSetPtr_;
}


const dimensionSet dimless(0, 0, 0, 0, 0, 0, 0);

const dimensionSet dimMass(1, 0, 0, 0, 0, 0, 0);
const dimensionSet dimLength(0, 1, 0, 0, 0, 0, 0);
const dimensionSet dimTime(0, 0, 1, 0, 0, 0, 0);
const dimensionSet dimTemperature(0, 0, 0, 1, 0, 0, 0);
const dimensionSet dimMoles(0, 0, 0, 0, 1, 0, 0);
const dimensionSet dimCurrent(0, 0, 0, 0, 0, 1, 0);
const dimensionSet dimLuminousIntensity(0, 0, 0, 0, 0, 0, 1);

const dimensionSet dimArea(sqr(dimLength));
const dimensionSet dimVolume(pow3(dimLength));
const dimensionSet dimVol(dimVolume);

const dimensionSet dimVelocity(dimLength/dimTime);
const dimensionSet dimAcceleration(dimVelocity/dimTime);

const dimensionSet dimDensity(dimMass/dimVolume);
const dimensionSet dimForce(dimMass*dimAcceleration);
const dimensionSet dimEnergy(dimForce*dimLength);
const dimensionSet dimPower(dimEnergy/dimTime);

const dimensionSet dimPressure(dimForce/dimArea);
const dimensionSet dimCompressibility(dimDensity/dimPressure);
const dimensionSet dimGasConstant(dimEnergy/dimMass/dimTemperature);
const dimensionSet dimSpecificHeatCapacity(dimGasConstant);
const dimensionSet dimViscosity(dimArea/dimTime);
const dimensionSet dimDynamicViscosity(dimDensity*dimViscosity);


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::dimensionSets::dimensionSets
(
    const HashTable<dimensionedScalar>& units,
    const wordList& unitNames
)
:
    units_(unitNames.size()),
    conversion_(unitNames.size()),
    conversionPivots_(unitNames.size()),
    valid_(false)
{
    forAll(unitNames, i)
    {
        units_.set
        (
            i,
            new dimensionedScalar
            (
                units[unitNames[i]]
            )
        );
    }

    if (unitNames.size() == 7)
    {
        valid_ = true;

        // Determine conversion from basic units to write units
        for (label rowI = 0; rowI < conversion_.m(); rowI++)
        {
            scalar* row = conversion_[rowI];

            for (label columnI = 0; columnI < conversion_.n(); columnI++)
            {
                const dimensionedScalar& dSet = units_[columnI];
                row[columnI] = dSet.dimensions()[rowI];
            }
        }
        conversionPivots_.setSize(conversion_.m());
        LUDecompose(conversion_, conversionPivots_);
    }
}


void Foam::dimensionSets::coefficients(scalarField& exponents) const
{
    LUBacksubstitute(conversion_, conversionPivots_, exponents);
}


// ************************************************************************* //
