
include_directories(../../core)
include_directories(../../cfd)
include_directories(../../mesh)

set(SOURCE_FILES_GENERICPATCHFIELDS
genericFvPatchField/genericFvPatchFields.cpp
genericPointPatchField/genericPointPatchFields.cpp
)

add_library(genericPatchFields SHARED ${SOURCE_FILES_GENERICPATCHFIELDS})
target_link_libraries(genericPatchFields finiteVolume)

    
add_custom_command(TARGET genericPatchFields
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E
                   copy $<TARGET_FILE:genericPatchFields> ${CMAKE_SOURCE_DIR}/../bin/$<TARGET_FILE_NAME:genericPatchFields>)
