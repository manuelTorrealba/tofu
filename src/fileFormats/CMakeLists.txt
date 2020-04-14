cmake_minimum_required (VERSION 3.0)

project (OpenFOAM)

add_definitions(-DWM_LABEL_SIZE=64 -DWM_DP -DNoRepository)

include_directories(../)

set (setWriters sampledSetWriters)

set(SOURCE_FILES
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

add_library(fileFormats STATIC ${SOURCE_FILES})

add_custom_command(TARGET fileFormats
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E
                   copy $<TARGET_FILE:fileFormats> ${CMAKE_SOURCE_DIR}/../../lib/$<TARGET_FILE_NAME:fileFormats>)
