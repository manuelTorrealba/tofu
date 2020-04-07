cmake_minimum_required (VERSION 2.8)

project (Pstream)

add_definitions(-DWM_LABEL_SIZE=64 -DWM_DP)

include_directories(../../)

set(SOURCE_FILES
UPstream.cpp
UIPread.cpp
UOPwrite.cpp
)

add_library(Pstream STATIC ${SOURCE_FILES})

add_custom_command(TARGET Pstream
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E
                   copy $<TARGET_FILE:Pstream> ${CMAKE_SOURCE_DIR}/../../../lib/$<TARGET_FILE_NAME:Pstream>)
                   