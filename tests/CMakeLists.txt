cmake_minimum_required (VERSION 3.0)

include_directories(../src)
link_directories (../lib)

add_definitions(-DWM_LABEL_SIZE=64 -DWM_DP -DNoRepository)

enable_testing()

set(SOURCE_FILES_TEST_FOAMVERSION
./foamVersion/Test-foamVersionString.cpp
)
add_executable(foamVersion ${SOURCE_FILES_TEST_FOAMVERSION})
target_link_libraries(foamVersion OpenFOAM OSSpecific Pstream z)
add_test(NAME foamVersion
         COMMAND foamVersion.exe --exe $<TARGET_FILE:foamVersion>)

set(SOUCE_FILES_ALLOC1
./alloc/Test.cpp
#./alloc/Test-alloc.cpp
#./alloc/Test-malloc.cpp
#./alloc/Test-new.cpp
)
add_executable(alloc1 ${SOUCE_FILES_ALLOC1})
target_link_libraries(alloc1 OpenFOAM OSSpecific Pstream z)
add_test(NAME alloc1
         COMMAND alloc1.exe --exe $<TARGET_FILE:foamVersion>)

set(SOUCE_FILES_BINSUM
./BinSum/Test-BinSum.cpp
)
add_executable(binSum ${SOUCE_FILES_BINSUM})
target_link_libraries(binSum OpenFOAM OSSpecific Pstream z)
add_test(NAME binSum
         COMMAND binSum.exe --exe $<TARGET_FILE:foamVersion>)

set(SOUCE_FILES_TESTCALLBACK
./callback/Test-callback.cpp
)
add_executable(callback ${SOUCE_FILES_TESTCALLBACK})
target_link_libraries(callback OpenFOAM OSSpecific Pstream z)
add_test(NAME callback
         COMMAND callback.exe --exe $<TARGET_FILE:foamVersion>)