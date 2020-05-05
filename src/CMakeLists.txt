cmake_minimum_required (VERSION 3.0)

project (tofu)
add_definitions(-DWM_LABEL_SIZE=64 -DWM_DP -DNoRepository)

add_subdirectory(core/Pstream/dummy)
add_subdirectory(core/OSspecific)
add_subdirectory(core/OpenFOAM)
add_subdirectory(core/fileFormats)
add_subdirectory(mesh/surfMesh)
add_subdirectory(mesh/triSurface)
add_subdirectory(mesh/meshTools)
add_subdirectory(mesh/mesh/extrudeModel)
add_subdirectory(mesh/mesh/blockMesh)
add_subdirectory(mesh/dynamicMesh)
add_subdirectory(mesh/lagrangian)

add_subdirectory(cfd/finiteVolume)
add_subdirectory(cfd/genericPatchFields)

add_subdirectory(mesh/conversion)
add_subdirectory(mesh/sampling)

add_subdirectory(core/foamToVTK)
add_subdirectory(core/parallel)
add_subdirectory(mesh/mesh/snappyHexMesh)


add_subdirectory(apps/icoFoam)
add_subdirectory(apps/blockMesh)
add_subdirectory(apps/writeFoamToVTK)
add_subdirectory(apps/snappyHexMesher)
add_subdirectory(apps/surfaceFeatures)