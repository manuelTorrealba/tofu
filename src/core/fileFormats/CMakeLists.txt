
include_directories(../../core)
include_directories(../../cfd)
include_directories(../../mesh)

set (setWriters sampledSetWriters)

set(SOURCE_FILES_FILEFORMATS
vtk/vtkUnstructuredReader.cpp
nas/NASCore.cpp
starcd/STARCDCore.cpp
coordSet/coordSet.cpp
${setWriters}/writers.cpp
${setWriters}/ensight/ensightSetWriterRunTime.cpp
${setWriters}/gnuplot/gnuplotSetWriterRunTime.cpp
${setWriters}/jplot/jplotSetWriterRunTime.cpp
${setWriters}/raw/rawSetWriterRunTime.cpp
${setWriters}/vtk/vtkSetWriterRunTime.cpp
${setWriters}/xmgrace/xmgraceSetWriterRunTime.cpp
${setWriters}/csv/csvSetWriterRunTime.cpp
)

add_library(fileFormats SHARED ${SOURCE_FILES_FILEFORMATS})
target_link_libraries(fileFormats OpenFOAM)

add_custom_command(TARGET fileFormats
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E
                   copy $<TARGET_FILE:fileFormats> ${CMAKE_SOURCE_DIR}/../bin/$<TARGET_FILE_NAME:fileFormats>)
