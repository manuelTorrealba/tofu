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
    Foam::radiation

Description
    Namespace for radiation modelling

Class
    Foam::radiation::radiationModel

Description
    Top level model for radiation modelling

SourceFiles
    radiationModel.C
    radiationModelNew.C

\*---------------------------------------------------------------------------*/

#ifndef radiationModel_H
#define radiationModel_H

#include "OpenFOAM/db/IOobjects/IOdictionary/IOdictionary.hpp"
#include "OpenFOAM/memory/autoPtr/autoPtr.hpp"
#include "OpenFOAM/db/runTimeSelection/construction/runTimeSelectionTables.hpp"
#include "finiteVolume/fields/volFields/volFields.hpp"
#include "finiteVolume/fvMatrices/fvMatricesFwd.hpp"
#include "OpenFOAM/primitives/bools/Switch/Switch.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

class basicThermo;
class fvMesh;

namespace radiation
{

// Forward declaration of classes
class absorptionEmissionModel;
class scatterModel;
class sootModel;

/*---------------------------------------------------------------------------*\
                       Class radiationModel Declaration
\*---------------------------------------------------------------------------*/

class radiationModel
:
    public IOdictionary
{
protected:

    // Protected data

        //- Reference to the mesh database
        const fvMesh& mesh_;

        //- Reference to the time database
        const Time& time_;

        //- Reference to the temperature field
        const volScalarField& T_;

        //- Radiation model dictionary
        dictionary coeffs_;

        //- Radiation solver frequency - number flow solver iterations per
        //  radiation solver iteration
        label solverFreq_;

        //- Flag to enable radiation model to be evaluated on first iteration
        bool firstIter_;


        // References to the radiation sub-models

            //- Absorption/emission model
            autoPtr<absorptionEmissionModel> absorptionEmission_;

            //- Scatter model
            autoPtr<scatterModel> scatter_;

            //- Soot model
            autoPtr<sootModel> soot_;


private:

    // Private Member Functions

        //- Create IO object if dictionary is present
        IOobject createIOobject(const fvMesh& mesh) const;

        //- Initialise
        void initialise();

        //- Disallow default bitwise copy construct
        radiationModel(const radiationModel&);

        //- Disallow default bitwise assignment
        void operator=(const radiationModel&);


public:

    //- Runtime type information
    TypeName("radiationModel");


    // Declare runtime constructor selection table

        declareRunTimeSelectionTable
        (
            autoPtr,
            radiationModel,
            T,
            (
                const volScalarField& T
            ),
            (T)
        );

        declareRunTimeSelectionTable
        (
            autoPtr,
            radiationModel,
            dictionary,
            (
                const dictionary& dict,
                const volScalarField& T
            ),
            (dict, T)
        );


    // Constructors

        //- Null constructor
        radiationModel(const volScalarField& T);

        //- Construct from components
        radiationModel(const word& type, const volScalarField& T);

        //- Construct from components
        radiationModel
        (
            const word& type,
            const dictionary& dict,
            const volScalarField& T
        );


    // Selectors

        //- Return a reference to the selected radiation model
        static autoPtr<radiationModel> New(const volScalarField& T);

        //- Return a reference to the selected radiation model
        static autoPtr<radiationModel> New
        (
            const dictionary& dict,
            const volScalarField& T
        );


    //- Destructor
    virtual ~radiationModel();


    // Member Functions

        // Edit

            //- Main update/correction routine
            virtual void correct();

            //- Solve radiation equation(s)
            virtual void calculate() = 0;

            //- Read radiationProperties dictionary
            virtual bool read() = 0;


        // Access

            //- Source term component (for power of T^4)
            virtual tmp<volScalarField> Rp() const = 0;

            //- Source term component (constant)
            virtual tmp<volScalarField::Internal> Ru() const = 0;

            //- Energy source term
            virtual tmp<fvScalarMatrix> Sh
            (
                const basicThermo& thermo,
                const volScalarField& he
            ) const;

            //- Temperature source term
            virtual tmp<fvScalarMatrix> ST
            (
                const dimensionedScalar& rhoCp,
                volScalarField& T
            ) const;

            //- Access to absorptionEmission model
            const absorptionEmissionModel& absorptionEmission() const;

            //- Access to soot Model
            const sootModel& soot() const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define addToRadiationRunTimeSelectionTables(model)                            \
                                                                               \
    addToRunTimeSelectionTable                                                 \
    (                                                                          \
        radiationModel,                                                        \
        model,                                                                 \
        dictionary                                                             \
    );                                                                         \
                                                                               \
    addToRunTimeSelectionTable                                                 \
    (                                                                          \
        radiationModel,                                                        \
        model,                                                                 \
        T                                                                      \
    );

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace radiation
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
