
include_directories(../../core)
include_directories(../../cfd)
include_directories(../../mesh)

set (decompositionConstraints decompose/decompositionMethods/decompositionConstraints)

set(SOURCE_FILES_PARALLEL
decompose/decompose/decompositionModel.cpp
decompose/decompose/fvFieldDecomposer.cpp
decompose/decompositionMethods/decompositionMethod/decompositionMethod.cpp
decompose/decompositionMethods/geomDecomp/geomDecomp.cpp
decompose/decompositionMethods/simpleGeomDecomp/simpleGeomDecomp.cpp
decompose/decompositionMethods/hierarchGeomDecomp/hierarchGeomDecomp.cpp
decompose/decompositionMethods/manualDecomp/manualDecomp.cpp
decompose/decompositionMethods/multiLevelDecomp/multiLevelDecomp.cpp
decompose/decompositionMethods/structuredDecomp/structuredDecomp.cpp
decompose/decompositionMethods/noDecomp/noDecomp.cpp
${decompositionConstraints}/decompositionConstraint/decompositionConstraint.cpp
${decompositionConstraints}/preserveBaffles/preserveBafflesConstraint.cpp
${decompositionConstraints}/preserveFaceZones/preserveFaceZonesConstraint.cpp
${decompositionConstraints}/preservePatches/preservePatchesConstraint.cpp
${decompositionConstraints}/singleProcessorFaceSets/singleProcessorFaceSetsConstraint.cpp
${decompositionConstraints}/refinementHistory/refinementHistoryConstraint.cpp
#decompose/metisDecomp/metisDecomp.cpp
#decompose/ptscotchDecomp/ptscotchDecomp.cpp
#decompose/scotchDecomp/scotchDecomp.cpp
distributed/distributedTriSurfaceMesh/distributedTriSurfaceMesh.cpp
reconstruct/reconstruct/processorMeshes.cpp
reconstruct/reconstruct/fvFieldReconstructor.cpp
reconstruct/reconstruct/pointFieldReconstructor.cpp
reconstruct/reconstruct/reconstructLagrangianPositions.cpp
#dummyThirdParty/metisDecomp/dummyMetisDecomp.cpp
#dummyThirdParty/ptscotchDecomp/dummyPtscotchDecomp.cpp
#dummyThirdParty/scotchDecomp/dummyScotchDecomp.cpp
#dummyThirdParty/MGridGen/dummyMGridGen.cpp
)

add_library(parallel SHARED ${SOURCE_FILES_PARALLEL})
target_link_libraries(parallel lagrangian dynamicMesh OpenFOAM finiteVolume)

add_custom_command(TARGET parallel
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E
                   copy $<TARGET_FILE:parallel> ${CMAKE_SOURCE_DIR}/../bin/$<TARGET_FILE_NAME:parallel>)
