
include_directories(../src)
link_directories (../lib /lib/perl5/5.30/x86_64-cygwin-threads/auto/Compress/Raw/Zlib)

add_definitions(-DWM_LABEL_SIZE=64 -DWM_DP -DNoRepository)

set(SOURCE_FILES main.cpp)

add_executable(tests ${SOURCE_FILES})

target_link_libraries(tests OpenFOAM OSSpecific Pstream Zlib)
