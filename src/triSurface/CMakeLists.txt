cmake_minimum_required (VERSION 3.0)

project (OpenFOAM)

add_definitions(-DWM_LABEL_SIZE=64 -DWM_DP -DNoRepository)

include_directories(../)

set(triSurfaceTools triSurface/triSurfaceTools)
set(geometricSurfacePatch triSurface/geometricSurfacePatch)
set(interfaces triSurface/interfaces)

set(SOURCE_FILES
faceTriangulation/faceTriangulation.cpp
meshTriangulation/meshTriangulation.cpp
triSurface/triSurface.cpp
triSurface/triSurfaceAddressing.cpp
triSurface/stitchTriangles.cpp
${interfaces}/STL/writeSTL.cpp
${interfaces}/STL/readSTL.cpp
${interfaces}/STL/readSTLASCII.L
${interfaces}/STL/readSTLBINARY.cpp
${interfaces}/GTS/writeGTS.cpp
${interfaces}/GTS/readGTS.cpp
${interfaces}/OBJ/readOBJ.cpp
${interfaces}/OBJ/writeOBJ.cpp
${interfaces}/SMESH/writeSMESH.cpp
${interfaces}/OFF/readOFF.cpp
${interfaces}/OFF/writeOFF.cpp
${interfaces}/TRI/writeTRI.cpp
${interfaces}/TRI/readTRI.cpp
${interfaces}/AC3D/readAC.cpp
${interfaces}/AC3D/writeAC.cpp
${interfaces}/VTK/readVTK.cpp
${interfaces}/VTK/writeVTK.cpp
${interfaces}/NAS/readNAS.cpp
triSurface/geometricSurfacePatch/geometricSurfacePatch.cpp
triSurface/surfacePatch/surfacePatch.cpp
triSurface/surfacePatch/surfacePatchIOList.cpp
tools/labelledTri/sortLabelledTri.cpp
triSurfaceFields/triSurfaceFields.cpp
)

add_library(triSurface STATIC ${SOURCE_FILES})

add_custom_command(TARGET triSurface
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E
                   copy $<TARGET_FILE:triSurface> ${CMAKE_SOURCE_DIR}/../../lib/$<TARGET_FILE_NAME:triSurface>)
