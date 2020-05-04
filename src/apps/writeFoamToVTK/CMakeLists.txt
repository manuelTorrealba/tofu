
include_directories(../../core)
include_directories(../../cfd)
include_directories(../../mesh)

link_directories (../../../lib)


add_executable(writeFoamToVTK foamToVTK.cpp)
#target_link_libraries(icoFoam OpenFOAM fileFormats meshTools OSSpecific Pstream surfMesh triSurface z finiteVolume)
#target_link_libraries(OpenFOAM OSSpecific Pstream z)
#target_link_libraries(surfMesh fileFormats)
#target_link_libraries(triSurface fileFormats surfMesh)
#target_link_libraries(meshTools fileFormats surfMesh)
#target_link_libraries(finiteVolume OpenFOAM triSurface meshTools)

target_link_libraries(writeFoamToVTK foamToVTK dynamicMesh lagrangian genericPatchFields)


add_custom_command(TARGET writeFoamToVTK
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E
                   copy $<TARGET_FILE:writeFoamToVTK> ${CMAKE_SOURCE_DIR}/../bin/$<TARGET_FILE_NAME:writeFoamToVTK>)

#command to run => ./icoFoam.exe -fileHandler masterUncollated -case ./icoFoam/cavity/cavity
