
include_directories(../../core)
include_directories(../../cfd)
include_directories(../../mesh)

set(SOURCE_FILES_FOAMTOVTK
surfaceMeshWriter.cpp
internalWriter.cpp
lagrangianWriter.cpp
patchWriter.cpp
writeFuns.cpp
writeFaceSet.cpp
writePointSet.cpp
writeSurfFields.cpp
vtkMesh.cpp
vtkTopo.cpp
writeVTK/writeVTK.cpp
)

add_library(foamToVTK SHARED ${SOURCE_FILES_FOAMTOVTK})
target_link_libraries(foamToVTK dynamicMesh lagrangian genericPatchFields)
    
add_custom_command(TARGET foamToVTK
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E
                   copy $<TARGET_FILE:foamToVTK> ${CMAKE_SOURCE_DIR}/../bin/$<TARGET_FILE_NAME:foamToVTK>)
