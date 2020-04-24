
include_directories(../../../core)
include_directories(../../../cfd)
include_directories(../../../mesh)

set(SOURCE_FILES_PSTREAM
UPstream.cpp
UIPread.cpp
UOPwrite.cpp
)

add_library(Pstream STATIC ${SOURCE_FILES_PSTREAM})

add_custom_command(TARGET Pstream
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E
                   copy $<TARGET_FILE:Pstream> ${CMAKE_SOURCE_DIR}/../bin/$<TARGET_FILE_NAME:Pstream>)
                   