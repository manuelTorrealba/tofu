
include_directories(../../core)
include_directories(../../cfd)
include_directories(../../mesh)

link_directories (../../../lib)


set(SOURCE_FILES_ICOFOAM
src/icoFoam.cpp
)
add_executable(icoFoam ${SOURCE_FILES_ICOFOAM})
#target_link_libraries(icoFoam OpenFOAM fileFormats meshTools OSSpecific Pstream surfMesh triSurface z finiteVolume)
#target_link_libraries(OpenFOAM OSSpecific Pstream z)
#target_link_libraries(surfMesh fileFormats)
#target_link_libraries(triSurface fileFormats surfMesh)
#target_link_libraries(meshTools fileFormats surfMesh)
#target_link_libraries(finiteVolume OpenFOAM triSurface meshTools)

target_link_libraries(icoFoam finiteVolume OpenFOAM OSSpecific Pstream z triSurface meshTools surfMesh fileFormats)


add_custom_command(TARGET icoFoam
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E
                   copy $<TARGET_FILE:icoFoam> ${CMAKE_SOURCE_DIR}/../bin/$<TARGET_FILE_NAME:icoFoam>)

#command to run => ./icoFoam.exe -fileHandler masterUncollated -case ./icoFoam/cavity/cavity
