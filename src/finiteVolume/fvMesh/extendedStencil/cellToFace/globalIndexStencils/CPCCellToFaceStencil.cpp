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

#include "finiteVolume/fvMesh/extendedStencil/cellToFace/globalIndexStencils/CPCCellToFaceStencil.hpp"
#include "finiteVolume/fvMesh/extendedStencil/cellToCell/globalIndexStencils/CPCCellToCellStencil.hpp"

// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::CPCCellToFaceStencil::CPCCellToFaceStencil(const polyMesh& mesh)
:
    cellToFaceStencil(mesh)
{
    // Calculate per cell the (face) connected cells (in global numbering)
    CPCCellToCellStencil globalCellCells(mesh);

    // Add stencils of neighbouring cells to create faceStencil
    labelListList faceStencil;
    calcFaceStencil(globalCellCells, faceStencil);

    // Transfer to *this
    transfer(faceStencil);
}


// ************************************************************************* //
