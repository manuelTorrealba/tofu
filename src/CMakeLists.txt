cmake_minimum_required (VERSION 3.0)

project (tofu)
add_definitions(-DWM_LABEL_SIZE=64 -DWM_DP -DNoRepository)

add_subdirectory(core/OpenFOAM)
add_subdirectory(core/Pstream/dummy)
add_subdirectory(core/OSspecific)
add_subdirectory(core/fileFormats)

add_subdirectory(mesh/meshTools)
add_subdirectory(mesh/surfMesh)
add_subdirectory(mesh/triSurface)
add_subdirectory(mesh/mesh/extrudeModel)
add_subdirectory(mesh/mesh/blockMesh)
add_subdirectory(mesh/dynamicMesh)

add_subdirectory(cfd/finiteVolume)

add_subdirectory(apps/icoFoam)
add_subdirectory(apps/blockMesh)

#LIB = ${FOAM_LIBBIN}/libOpenFOAM

#add_library(OpenFOAM STATIC ${SOURCE_FILES})
#target_link_libraries(OpenFOAM OSSpecific Pstream z)

#add_custom_command(TARGET OpenFOAM
#                   POST_BUILD
#                   COMMAND ${CMAKE_COMMAND} -E
#                   copy $<TARGET_FILE:OpenFOAM> ${CMAKE_SOURCE_DIR}/../../lib/$<TARGET_FILE_NAME:OpenFOAM>)
