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

Class
    Foam::regionModels::surfaceFilmModels::standardRadiation

Description
    Standard radiation model

SourceFiles
    standardRadiation.C

\*---------------------------------------------------------------------------*/

#ifndef standardRadiation_H
#define standardRadiation_H

#include "regionModels/surfaceFilmModels/submodels/thermo/filmRadiationModel/filmRadiationModel/filmRadiationModel.hpp"
#include "finiteVolume/fields/volFields/volFieldsFwd.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace regionModels
{
namespace surfaceFilmModels
{

/*---------------------------------------------------------------------------*\
                     Class standardRadiation Declaration
\*---------------------------------------------------------------------------*/

class standardRadiation
:
    public filmRadiationModel
{
private:

    // Private data

        //- Radiative incident flux mapped from  the primary region / [kg/s3]
        volScalarField qinPrimary_;

        //- Remaining radiative flux after removing local contribution
        volScalarField qrNet_;


        // Model coefficients

            //- Beta coefficient
            scalar beta_;

            //- Bar(kappa) coefficient
            scalar kappaBar_;


    // Private member functions

        //- Disallow default bitwise copy construct
        standardRadiation(const standardRadiation&);

        //- Disallow default bitwise assignment
        void operator=(const standardRadiation&);


public:

    //- Runtime type information
    TypeName("standardRadiation");


    // Constructors

        //- Construct from surface film model and dictionary
        standardRadiation
        (
            surfaceFilmRegionModel& film,
            const dictionary& dict
        );


    //- Destructor
    virtual ~standardRadiation();


    // Member Functions

        // Evolution

            //- Correct
            virtual void correct();

            //- Return the radiation sensible enthalpy source
            //  Also updates qrNet
            virtual tmp<volScalarField> Shs();
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace surfaceFilmModels
} // End namespace regionModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
