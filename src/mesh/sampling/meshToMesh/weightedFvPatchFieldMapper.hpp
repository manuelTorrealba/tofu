/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2015-2018 OpenFOAM Foundation
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
    Foam::weightedFvPatchFieldMapper

Description
    FieldMapper with weighted mapping.

\*---------------------------------------------------------------------------*/

#ifndef weightedFvPatchFieldMapper_H
#define weightedFvPatchFieldMapper_H

#include "finiteVolume/fields/fvPatchFields/fvPatchField/fvPatchFieldMapper.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                 Class weightedFvPatchFieldMapper Declaration
\*---------------------------------------------------------------------------*/

class weightedFvPatchFieldMapper
:
    public fvPatchFieldMapper
{
    const labelListList& addressing_;

    const scalarListList& weights_;

    bool hasUnmapped_;

public:

    // Constructors

        //- Construct given addressing
        weightedFvPatchFieldMapper
        (
            const labelListList& addressing,
            const scalarListList& weights
        )
        :
            addressing_(addressing),
            weights_(weights),
            hasUnmapped_(false)
        {
            forAll(addressing_, i)
            {
                if (addressing_[i].size() == 0)
                {
                    hasUnmapped_ = true;
                }
            }
        }

    //- Destructor
    virtual ~weightedFvPatchFieldMapper()
    {}


    // Member Functions

        virtual label size() const
        {
            return addressing().size();
        }

        virtual bool direct() const
        {
            return false;
        }

        virtual bool hasUnmapped() const
        {
            return hasUnmapped_;
        }

        virtual const labelListList& addressing() const
        {
            return addressing_;
        }

        virtual const scalarListList& weights() const
        {
            return weights_;
        }

};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
