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

Description
    Note: bug in vtk displaying wedges? Seems to display ok if we decompose
    them. Should be thoroughly tested!
    (they appear rarely in polyhedral meshes, do appear in some cut meshes)

\*---------------------------------------------------------------------------*/

#include "foamToVTK/vtkTopo.hpp"
#include "OpenFOAM/meshes/polyMesh/polyMesh.hpp"
#include "OpenFOAM/meshes/meshShapes/cellShape/cellShape.hpp"
#include "OpenFOAM/meshes/meshShapes/cellModeller/cellModeller.hpp"
#include "OpenFOAM/primitives/Swap/Swap.hpp"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

bool Foam::vtkTopo::decomposePoly = true;


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::vtkTopo::vtkTopo(const polyMesh& mesh)
:
    mesh_(mesh),
    vertLabels_(),
    cellTypes_(),
    addPointCellLabels_(),
    superCells_()
{
    const cellModel& tet = *(cellModeller::lookup("tet"));
    const cellModel& pyr = *(cellModeller::lookup("pyr"));
    const cellModel& prism = *(cellModeller::lookup("prism"));
    const cellModel& wedge = *(cellModeller::lookup("wedge"));
    const cellModel& tetWedge = *(cellModeller::lookup("tetWedge"));
    const cellModel& hex = *(cellModeller::lookup("hex"));

    const cellShapeList& cellShapes = mesh_.cellShapes();

    // Number of additional points needed by the decomposition of polyhedra
    label nAddPoints = 0;

    // Number of additional cells generated by the decomposition of polyhedra
    label nAddCells = 0;

    // face owner is needed to determine the face orientation
    const labelList& owner = mesh.faceOwner();

    // Scan for cells which need to be decomposed and count additional points
    // and cells
    if (decomposePoly)
    {
        forAll(cellShapes, celli)
        {
            const cellModel& model = cellShapes[celli].model();

            if
            (
                model != hex
             && model != wedge    // See above.
             && model != prism
             && model != pyr
             && model != tet
             && model != tetWedge
            )
            {
                const cell& cFaces = mesh_.cells()[celli];

                forAll(cFaces, cFacei)
                {
                    const face& f = mesh_.faces()[cFaces[cFacei]];

                    label nQuads = 0;
                    label nTris = 0;
                    f.nTrianglesQuads(mesh_.points(), nTris, nQuads);

                    nAddCells += nQuads + nTris;
                }

                nAddCells--;
                nAddPoints++;
            }
        }
    }


    // Set size of additional point addressing array
    // (from added point to original cell)
    addPointCellLabels_.setSize(nAddPoints);

    // Set size of additional cells mapping array
    // (from added cell to original cell)
    superCells_.setSize(nAddCells);

    // List of vertex labels in VTK ordering
    vertLabels_.setSize(cellShapes.size() + nAddCells);

    // Label of vtk type
    cellTypes_.setSize(cellShapes.size() + nAddCells);

    // Set counters for additional points and additional cells
    label addPointi = 0, addCelli = 0;

    forAll(cellShapes, celli)
    {
        const cellShape& cellShape = cellShapes[celli];
        const cellModel& cellModel = cellShape.model();

        labelList& vtkVerts = vertLabels_[celli];

        if (cellModel == tet)
        {
            vtkVerts = cellShape;

            cellTypes_[celli] = VTK_TETRA;
        }
        else if (cellModel == pyr)
        {
            vtkVerts = cellShape;

            cellTypes_[celli] = VTK_PYRAMID;
        }
        else if (cellModel == prism)
        {
            // VTK has a different node order for VTK_WEDGE
            // their triangles point outwards!
            vtkVerts = cellShape;

            Foam::Swap(vtkVerts[1], vtkVerts[2]);
            Foam::Swap(vtkVerts[4], vtkVerts[5]);

            cellTypes_[celli] = VTK_WEDGE;
        }
        else if (cellModel == tetWedge && decomposePoly)
        {
            // Treat as squeezed prism (VTK_WEDGE)
            vtkVerts.setSize(6);
            vtkVerts[0] = cellShape[0];
            vtkVerts[1] = cellShape[2];
            vtkVerts[2] = cellShape[1];
            vtkVerts[3] = cellShape[3];
            vtkVerts[4] = cellShape[4];
            vtkVerts[5] = cellShape[3];

            cellTypes_[celli] = VTK_WEDGE;
        }
        else if (cellModel == wedge)
        {
            // Treat as squeezed hex
            vtkVerts.setSize(8);
            vtkVerts[0] = cellShape[0];
            vtkVerts[1] = cellShape[1];
            vtkVerts[2] = cellShape[2];
            vtkVerts[3] = cellShape[2];
            vtkVerts[4] = cellShape[3];
            vtkVerts[5] = cellShape[4];
            vtkVerts[6] = cellShape[5];
            vtkVerts[7] = cellShape[6];

            cellTypes_[celli] = VTK_HEXAHEDRON;
        }
        else if (cellModel == hex)
        {
            vtkVerts = cellShape;

            cellTypes_[celli] = VTK_HEXAHEDRON;
        }
        else if (decomposePoly)
        {
            // Polyhedral cell. Decompose into tets + pyramids.

            // Mapping from additional point to cell
            addPointCellLabels_[addPointi] = celli;

            // The new vertex from the cell-centre
            const label newVertexLabel = mesh_.nPoints() + addPointi;

            // Whether to insert cell in place of original or not.
            bool substituteCell = true;

            const labelList& cFaces = mesh_.cells()[celli];
            forAll(cFaces, cFacei)
            {
                const face& f = mesh_.faces()[cFaces[cFacei]];
                const bool isOwner = (owner[cFaces[cFacei]] == celli);

                // Number of triangles and quads in decomposition
                label nTris = 0;
                label nQuads = 0;
                f.nTrianglesQuads(mesh_.points(), nTris, nQuads);

                // Do actual decomposition into triFcs and quadFcs.
                faceList triFcs(nTris);
                faceList quadFcs(nQuads);
                label trii = 0;
                label quadi = 0;
                f.trianglesQuads(mesh_.points(), trii, quadi, triFcs, quadFcs);

                forAll(quadFcs, quadI)
                {
                    label thisCelli;

                    if (substituteCell)
                    {
                        thisCelli = celli;
                        substituteCell = false;
                    }
                    else
                    {
                        thisCelli = mesh_.nCells() + addCelli;
                        superCells_[addCelli++] = celli;
                    }

                    labelList& addVtkVerts = vertLabels_[thisCelli];

                    addVtkVerts.setSize(5);

                    const face& quad = quadFcs[quadI];

                    // Ensure we have the correct orientation for the
                    // base of the primitive cell shape.
                    // If the cell is face owner, the orientation needs to be
                    // flipped.
                    // At the moment, VTK doesn't actually seem to care if
                    // negative cells are defined, but we'll do it anyhow
                    // (for safety).
                    if (isOwner)
                    {
                        addVtkVerts[0] = quad[3];
                        addVtkVerts[1] = quad[2];
                        addVtkVerts[2] = quad[1];
                        addVtkVerts[3] = quad[0];
                    }
                    else
                    {
                        addVtkVerts[0] = quad[0];
                        addVtkVerts[1] = quad[1];
                        addVtkVerts[2] = quad[2];
                        addVtkVerts[3] = quad[3];
                    }
                    addVtkVerts[4] = newVertexLabel;

                    cellTypes_[thisCelli] = VTK_PYRAMID;
                }

                forAll(triFcs, triI)
                {
                    label thisCelli;

                    if (substituteCell)
                    {
                        thisCelli = celli;
                        substituteCell = false;
                    }
                    else
                    {
                        thisCelli = mesh_.nCells() + addCelli;
                        superCells_[addCelli++] = celli;
                    }


                    labelList& addVtkVerts = vertLabels_[thisCelli];

                    const face& tri = triFcs[triI];

                    addVtkVerts.setSize(4);

                    // See note above about the orientation.
                    if (isOwner)
                    {
                        addVtkVerts[0] = tri[2];
                        addVtkVerts[1] = tri[1];
                        addVtkVerts[2] = tri[0];
                    }
                    else
                    {
                        addVtkVerts[0] = tri[0];
                        addVtkVerts[1] = tri[1];
                        addVtkVerts[2] = tri[2];
                    }
                    addVtkVerts[3] = newVertexLabel;

                    cellTypes_[thisCelli] = VTK_TETRA;
                }
            }

            addPointi++;
        }
        else
        {
            // Polyhedral cell - not decomposed
            cellTypes_[celli] = VTK_POLYHEDRON;

            const labelList& cFaces = mesh_.cells()[celli];

            // space for the number of faces and size of each face
            label nData = 1 + cFaces.size();

            // count total number of face points
            forAll(cFaces, cFacei)
            {
                const face& f = mesh.faces()[cFaces[cFacei]];
                nData += f.size();   // space for the face labels
            }

            vtkVerts.setSize(nData);

            nData = 0;
            vtkVerts[nData++] = cFaces.size();

            // build face stream
            forAll(cFaces, cFacei)
            {
                const face& f = mesh.faces()[cFaces[cFacei]];
                const bool isOwner = (owner[cFaces[cFacei]] == celli);

                // number of labels for this face
                vtkVerts[nData++] = f.size();

                if (isOwner)
                {
                    forAll(f, fp)
                    {
                        vtkVerts[nData++] = f[fp];
                    }
                }
                else
                {
                    // fairly immaterial if we reverse the list
                    // or use face::reverseFace()
                    forAllReverse(f, fp)
                    {
                        vtkVerts[nData++] = f[fp];
                    }
                }
            }
        }
    }

    if (decomposePoly)
    {
        Pout<< "    Original cells:" << mesh_.nCells()
            << " points:" << mesh_.nPoints()
            << "   Additional cells:" << superCells_.size()
            << "  additional points:" << addPointCellLabels_.size()
            << nl << endl;
    }

}


// ************************************************************************* //
