
include_directories(../../../core)
include_directories(../../../cfd)
include_directories(../../../mesh)

set(SOURCE_FILES_EXTRUDEMODEL
extrudeModel/extrudeModel.cpp
extrudeModel/extrudeModelNew.cpp
linearNormal/linearNormal.cpp
planeExtrusion/planeExtrusion.cpp
linearDirection/linearDirection.cpp
linearRadial/linearRadial.cpp
radial/radial.cpp
sigmaRadial/sigmaRadial.cpp
sector/sector.cpp
cyclicSector/cyclicSector.cpp
wedge/wedge.cpp
)

add_library(extrudeModel SHARED ${SOURCE_FILES_EXTRUDEMODEL})
target_link_libraries(extrudeModel meshTools)
    
add_custom_command(TARGET extrudeModel
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E
                   copy $<TARGET_FILE:extrudeModel> ${CMAKE_SOURCE_DIR}/../bin/$<TARGET_FILE_NAME:extrudeModel>)
