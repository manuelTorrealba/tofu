
include_directories(../../core)
include_directories(../../cfd)
include_directories(../../mesh)

set(SOURCE_FILES_OSSPECIFIC
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

add_library(OSSpecific STATIC ${SOURCE_FILES_OSSPECIFIC})

add_custom_command(TARGET OSSpecific
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E
                   copy $<TARGET_FILE:OSSpecific> ${CMAKE_SOURCE_DIR}/../lib/$<TARGET_FILE_NAME:OSSpecific>)