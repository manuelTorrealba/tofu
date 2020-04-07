
include_directories(../src)
link_directories (../lib)

add_definitions(-DWM_LABEL_SIZE=64 -DWM_DP)

set(SOURCE_FILES main.cpp)

add_executable(tests ${SOURCE_FILES})

target_link_libraries(tests OpenFOAM OSSpecific Pstream)
