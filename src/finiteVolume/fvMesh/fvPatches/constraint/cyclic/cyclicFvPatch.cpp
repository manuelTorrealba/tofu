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

#include "finiteVolume/fvMesh/fvPatches/constraint/cyclic/cyclicFvPatch.hpp"
#include "OpenFOAM/db/runTimeSelection/construction/addToRunTimeSelectionTable.hpp"
#include "finiteVolume/fvMesh/fvMesh.hpp"
#include "OpenFOAM/primitives/transform/transform.hpp"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(cyclicFvPatch, 0);
    addToRunTimeSelectionTable(fvPatch, cyclicFvPatch, polyPatch);
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void Foam::cyclicFvPatch::makeWeights(scalarField& w) const
{
    const cyclicFvPatch& nbrPatch = neighbFvPatch();

    const scalarField deltas(nf()&coupledFvPatch::delta());
    const scalarField nbrDeltas(nbrPatch.nf()&nbrPatch.coupledFvPatch::delta());

    forAll(deltas, facei)
    {
        scalar di = deltas[facei];
        scalar dni = nbrDeltas[facei];

        w[facei] = dni/(di + dni);
    }
}


Foam::tmp<Foam::vectorField> Foam::cyclicFvPatch::delta() const
{
    const vectorField patchD(coupledFvPatch::delta());
    const vectorField nbrPatchD(neighbFvPatch().coupledFvPatch::delta());

    tmp<vectorField> tpdv(new vectorField(patchD.size()));
    vectorField& pdv = tpdv.ref();

    // To the transformation if necessary
    if (parallel())
    {
        forAll(patchD, facei)
        {
            vector ddi = patchD[facei];
            vector dni = nbrPatchD[facei];

            pdv[facei] = ddi - dni;
        }
    }
    else
    {
        forAll(patchD, facei)
        {
            vector ddi = patchD[facei];
            vector dni = nbrPatchD[facei];

            pdv[facei] = ddi - transform(forwardT()[0], dni);
        }
    }

    return tpdv;
}


Foam::tmp<Foam::labelField> Foam::cyclicFvPatch::interfaceInternalField
(
    const labelUList& internalData
) const
{
    return patchInternalField(internalData);
}


Foam::tmp<Foam::labelField> Foam::cyclicFvPatch::internalFieldTransfer
(
    const Pstream::commsTypes commsType,
    const labelUList& iF
) const
{
    return neighbFvPatch().patchInternalField(iF);
}


// ************************************************************************* //
