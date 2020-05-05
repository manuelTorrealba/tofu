
include_directories(../../core)
include_directories(../../cfd)
include_directories(../../mesh)

set(meshToMeshMethods meshToMesh/calcMethod)
set(surfWriters sampledSurface/writers)

set(SOURCE_FILES_SAMPLING
probes/probes.cpp
probes/patchProbes.cpp
probes/probesGrouping.cpp
sampledSet/sampledSet/sampledSet.cpp
sampledSet/sampledSets/sampledSets.cpp
sampledSet/sampledSets/sampledSetsGrouping.cpp
sampledSet/arcUniform/arcUniform.cpp
sampledSet/boxUniform/boxUniform.cpp
sampledSet/circleRandom/circleRandom.cpp
sampledSet/lineCell/lineCell.cpp
sampledSet/lineCellFace/lineCellFace.cpp
sampledSet/lineFace/lineFace.cpp
sampledSet/lineUniform/lineUniform.cpp
sampledSet/boundaryPoints/boundaryPoints.cpp
sampledSet/boundaryRandom/boundaryRandom.cpp
sampledSet/points/points.cpp
sampledSet/sphereRandom/sphereRandom.cpp
sampledSet/triSurfaceMeshSampledSet/triSurfaceMeshSampledSet.cpp
cuttingPlane/cuttingPlane.cpp
sampledSurface/sampledPatch/sampledPatch.cpp
sampledSurface/sampledPatchInternalField/sampledPatchInternalField.cpp
sampledSurface/sampledPlane/sampledPlane.cpp
sampledSurface/isoSurface/isoSurface.cpp
sampledSurface/isoSurface/sampledIsoSurface.cpp
sampledSurface/isoSurface/isoSurfaceCell.cpp
sampledSurface/isoSurface/sampledIsoSurfaceCell.cpp
sampledSurface/distanceSurface/distanceSurface.cpp
sampledSurface/sampledCuttingPlane/sampledCuttingPlane.cpp
sampledSurface/sampledSurface/sampledSurface.cpp
sampledSurface/sampledSurfaces/sampledSurfaces.cpp
sampledSurface/sampledSurfaces/sampledSurfacesGrouping.cpp
sampledSurface/sampledTriSurfaceMesh/sampledTriSurfaceMesh.cpp
sampledSurface/thresholdCellFaces/thresholdCellFaces.cpp
sampledSurface/thresholdCellFaces/sampledThresholdCellFaces.cpp
${surfWriters}/surfaceWriter.cpp
${surfWriters}/ensight/ensightSurfaceWriter.cpp
${surfWriters}/ensight/ensightPTraits.cpp
${surfWriters}/foam/foamSurfaceWriter.cpp
${surfWriters}/nastran/nastranSurfaceWriter.cpp
${surfWriters}/proxy/proxySurfaceWriter.cpp
${surfWriters}/raw/rawSurfaceWriter.cpp
${surfWriters}/starcd/starcdSurfaceWriter.cpp
${surfWriters}/vtk/vtkSurfaceWriter.cpp
graphField/writePatchGraph.cpp
graphField/writeCellGraph.cpp
graphField/makeGraph.cpp
meshToMesh/meshToMesh.cpp
meshToMesh/meshToMeshParallelOps.cpp
${meshToMeshMethods}/meshToMeshMethod/meshToMeshMethod.cpp
${meshToMeshMethods}/meshToMeshMethod/meshToMeshMethodNew.cpp
${meshToMeshMethods}/cellVolumeWeight/cellVolumeWeightMethod.cpp
${meshToMeshMethods}/direct/directMethod.cpp
${meshToMeshMethods}/mapNearest/mapNearestMethod.cpp
meshToMesh0/meshToMesh0.cpp
meshToMesh0/calculateMeshToMesh0Addressing.cpp
meshToMesh0/calculateMeshToMesh0Weights.cpp
)

add_library(sampling SHARED ${SOURCE_FILES_SAMPLING})
target_link_libraries(sampling conversion finiteVolume meshTools surfMesh fileFormats triSurface lagrangian dynamicMesh)

add_custom_command(TARGET sampling
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E
                   copy $<TARGET_FILE:sampling> ${CMAKE_SOURCE_DIR}/../bin/$<TARGET_FILE_NAME:sampling>)
