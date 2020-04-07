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

#include "functionObjects/field/yPlus/yPlus.hpp"
#include "TurbulenceModels/turbulenceModels/turbulenceModel.hpp"
#include "TurbulenceModels/turbulenceModels/derivedFvPatchFields/wallFunctions/nutWallFunctions/nutWallFunction/nutWallFunctionFvPatchScalarField.hpp"
#include "finiteVolume/fvMesh/fvPatches/derived/wall/wallFvPatch.hpp"
#include "OpenFOAM/db/runTimeSelection/construction/addToRunTimeSelectionTable.hpp"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace functionObjects
{
    defineTypeNameAndDebug(yPlus, 0);

    addToRunTimeSelectionTable
    (
        functionObject,
        yPlus,
        dictionary
    );
}
}


// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //

void Foam::functionObjects::yPlus::writeFileHeader(const label i)
{
    writeHeader(file(), "y+ ()");

    writeCommented(file(), "Time");
    writeTabbed(file(), "patch");
    writeTabbed(file(), "min");
    writeTabbed(file(), "max");
    writeTabbed(file(), "average");
    file() << endl;
}


Foam::tmp<Foam::volScalarField> Foam::functionObjects::yPlus::calcYPlus
(
    const turbulenceModel& turbModel
)
{
    tmp<volScalarField> tyPlus
    (
        new volScalarField
        (
            IOobject
            (
                type(),
                mesh_.time().timeName(),
                mesh_
            ),
            mesh_,
            dimensionedScalar("0", dimless, 0.0)
        )
    );

    volScalarField::Boundary& yPlusBf = tyPlus.ref().boundaryFieldRef();

    volScalarField::Boundary d = nearWallDist(mesh_).y();

    const volScalarField::Boundary nutBf =
        turbModel.nut()().boundaryField();

    const volScalarField::Boundary nuEffBf =
        turbModel.nuEff()().boundaryField();

    const volScalarField::Boundary nuBf =
        turbModel.nu()().boundaryField();

    const fvPatchList& patches = mesh_.boundary();

    forAll(patches, patchi)
    {
        const fvPatch& patch = patches[patchi];

        if (isA<nutWallFunctionFvPatchScalarField>(nutBf[patchi]))
        {
            const nutWallFunctionFvPatchScalarField& nutPf =
                dynamic_cast<const nutWallFunctionFvPatchScalarField&>
                (
                    nutBf[patchi]
                );

            yPlusBf[patchi] = nutPf.yPlus();
        }
        else if (isA<wallFvPatch>(patch))
        {
            yPlusBf[patchi] =
                d[patchi]
               *sqrt
                (
                    nuEffBf[patchi]
                   *mag(turbModel.U().boundaryField()[patchi].snGrad())
                )/nuBf[patchi];
        }
    }

    return tyPlus;
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::functionObjects::yPlus::yPlus
(
    const word& name,
    const Time& runTime,
    const dictionary& dict
)
:
    fvMeshFunctionObject(name, runTime, dict),
    logFiles(obr_, name),
    writeLocalObjects(obr_, log)
{
    read(dict);
    resetName(typeName);
    resetLocalObjectName(typeName);
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::functionObjects::yPlus::~yPlus()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

bool Foam::functionObjects::yPlus::read(const dictionary& dict)
{
    fvMeshFunctionObject::read(dict);
    writeLocalObjects::read(dict);

    return true;
}


bool Foam::functionObjects::yPlus::execute()
{
    if (mesh_.foundObject<turbulenceModel>(turbulenceModel::propertiesName))
    {
        const turbulenceModel& model = mesh_.lookupObject<turbulenceModel>
        (
            turbulenceModel::propertiesName
        );

        word name(type());

        return store(name, calcYPlus(model));
    }
    else
    {
        FatalErrorInFunction
            << "Unable to find turbulence model in the "
            << "database" << exit(FatalError);
    }

    return true;
}


bool Foam::functionObjects::yPlus::write()
{
    Log << type() << " " << name() << " write:" << nl;

    writeLocalObjects::write();

    logFiles::write();

    const volScalarField& yPlus =
        mesh_.lookupObject<volScalarField>(type());

    const volScalarField::Boundary& yPlusBf = yPlus.boundaryField();
    const fvPatchList& patches = mesh_.boundary();

    forAll(patches, patchi)
    {
        const fvPatch& patch = patches[patchi];

        if (isA<wallFvPatch>(patch))
        {
            const scalarField& yPlusp = yPlusBf[patchi];

            const scalar minYplus = gMin(yPlusp);
            const scalar maxYplus = gMax(yPlusp);
            const scalar avgYplus = gAverage(yPlusp);

            if (Pstream::master())
            {
                Log << "    patch " << patch.name()
                    << " y+ : min = " << minYplus << ", max = " << maxYplus
                    << ", average = " << avgYplus << nl;

                writeTime(file());
                file()
                    << tab << patch.name()
                    << tab << minYplus
                    << tab << maxYplus
                    << tab << avgYplus
                    << endl;
            }
        }
    }

    Log << endl;

    return true;
}


// ************************************************************************* //
