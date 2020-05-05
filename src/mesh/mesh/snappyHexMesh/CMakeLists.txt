
include_directories(../../../core)
include_directories(../../../cfd)
include_directories(../../../mesh)

set(SOURCE_FILES_SNAPPYHEXMESH
snappyHexMeshDriver/snappyLayerDriver.cpp
#snappyHexMeshDriver/snappyLayerDriverShrink.cpp
snappyHexMeshDriver/snappySnapDriver.cpp
snappyHexMeshDriver/snappySnapDriverFeature.cpp
snappyHexMeshDriver/snappyRefineDriver.cpp
snappyHexMeshDriver/layerParameters/layerParameters.cpp
snappyHexMeshDriver/refinementParameters/refinementParameters.cpp
snappyHexMeshDriver/snapParameters/snapParameters.cpp
snappyHexMeshDriver/pointData/pointData.cpp
meshRefinement/meshRefinementBaffles.cpp
meshRefinement/meshRefinement.cpp
meshRefinement/meshRefinementMerge.cpp
meshRefinement/meshRefinementProblemCells.cpp
meshRefinement/meshRefinementRefine.cpp
meshRefinement/patchFaceOrientation.cpp
refinementFeatures/refinementFeatures.cpp
refinementSurfaces/surfaceZonesInfo.cpp
refinementSurfaces/refinementSurfaces.cpp
shellSurfaces/shellSurfaces.cpp
trackedParticle/trackedParticle.cpp
trackedParticle/trackedParticleCloud.cpp
externalDisplacementMeshMover/displacementMeshMoverMotionSolver.cpp
externalDisplacementMeshMover/externalDisplacementMeshMover.cpp
externalDisplacementMeshMover/medialAxisMeshMover.cpp
externalDisplacementMeshMover/zeroFixedValue/zeroFixedValuePointPatchFields.cpp
)

add_library(snappyHexMesh SHARED ${SOURCE_FILES_SNAPPYHEXMESH})
target_link_libraries(snappyHexMesh dynamicMesh finiteVolume lagrangian meshTools fileFormats surfMesh triSurface parallel)
    
add_custom_command(TARGET snappyHexMesh
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E
                   copy $<TARGET_FILE:snappyHexMesh> ${CMAKE_SOURCE_DIR}/../bin/$<TARGET_FILE_NAME:snappyHexMesh>)
