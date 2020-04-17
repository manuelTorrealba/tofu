
include_directories(../../../core)
include_directories(../../../cfd)
include_directories(../../../mesh)

set(SOURCE_FILES_BLOCKMESH
blockVertices/blockVertex/blockVertex.cpp
blockVertices/pointVertex/pointVertex.cpp
blockVertices/projectVertex/projectVertex.cpp
blockVertices/namedVertex/namedVertex.cpp
blockEdges/blockEdge/blockEdge.cpp
blockEdges/lineDivide/lineDivide.cpp
blockEdges/lineEdge/lineEdge.cpp
blockEdges/polyLineEdge/polyLine.cpp
blockEdges/polyLineEdge/polyLineEdge.cpp
blockEdges/arcEdge/arcEdge.cpp
blockEdges/BSplineEdge/BSpline.cpp
blockEdges/BSplineEdge/BSplineEdge.cpp
blockEdges/splineEdge/CatmullRomSpline.cpp
blockEdges/splineEdge/splineEdge.cpp
blockEdges/projectEdge/projectEdge.cpp
blockEdges/projectCurveEdge/projectCurveEdge.cpp
blockFaces/blockFace/blockFace.cpp
blockFaces/projectFace/projectFace.cpp
gradingDescriptor/gradingDescriptor.cpp
gradingDescriptor/gradingDescriptors.cpp
blockDescriptor/blockDescriptor.cpp
blockDescriptor/blockDescriptorEdges.cpp
blocks/block/block.cpp
blocks/block/blockCreate.cpp
blocks/namedBlock/namedBlock.cpp
blockMesh/blockMesh.cpp
blockMesh/blockMeshCreate.cpp
blockMesh/blockMeshTopology.cpp
blockMesh/blockMeshCheck.cpp
blockMesh/blockMeshMerge.cpp
blockMesh/blockMeshMergeFast.cpp
blockMeshTools/blockMeshTools.cpp
)

add_library(blockMesh STATIC ${SOURCE_FILES_BLOCKMESH})
#LIB_LIBS = -lmeshTools -lfileFormats -lsurfMesh
    
add_custom_command(TARGET blockMesh
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E
                   copy $<TARGET_FILE:blockMesh> ${CMAKE_SOURCE_DIR}/../lib/$<TARGET_FILE_NAME:blockMesh>)
