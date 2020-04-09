cmake_minimum_required (VERSION 2.8)

project (OSSpecific)

add_definitions(-DWM_LABEL_SIZE=64 -DWM_DP -DNoRepository)

include_directories(../)

set(SOURCE_FILES
./POSIX/signals/sigFpe.cpp
./POSIX/signals/sigSegv.cpp
./POSIX/signals/sigInt.cpp
./POSIX/signals/sigQuit.cpp
./POSIX/signals/sigStopAtWriteNow.cpp
./POSIX/signals/sigWriteNow.cpp
./POSIX/regExp.cpp
./POSIX/timer.cpp
./POSIX/fileStat.cpp
./POSIX/POSIX.cpp
./POSIX/cpuTime/cpuTime.cpp
./POSIX/clockTime/clockTime.cpp
./POSIX/memInfo/memInfo.cpp
./POSIX/printStack.cpp
./POSIX/fileMonitor.cpp
)

add_library(OSSpecific STATIC ${SOURCE_FILES} ${HEADER_FILES})

add_custom_command(TARGET OSSpecific
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E
                   copy $<TARGET_FILE:OSSpecific> ${CMAKE_SOURCE_DIR}/../../lib/$<TARGET_FILE_NAME:OSSpecific>)