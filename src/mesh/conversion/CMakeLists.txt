
include_directories(../../core)
include_directories(../../cfd)
include_directories(../../mesh)


set(SOURCE_FILES_CONVERSION
ensight/file/ensightFile.cpp
ensight/file/ensightGeoFile.cpp
ensight/part/ensightPart.cpp
ensight/part/ensightPartIO.cpp
ensight/part/ensightPartCells.cpp
ensight/part/ensightPartFaces.cpp
ensight/part/ensightParts.cpp
meshTables/boundaryRegion.cpp
meshTables/cellTable.cpp
meshReader/meshReader.cpp
meshReader/meshReaderAux.cpp
meshReader/calcPointCells.cpp
meshReader/createPolyCells.cpp
meshReader/createPolyBoundary.cpp
meshReader/starcd/STARCDMeshReader.cpp
meshWriter/meshWriter.cpp
meshWriter/starcd/STARCDMeshWriter.cpp
polyDualMesh/polyDualMesh.cpp
)

add_library(conversion SHARED ${SOURCE_FILES_CONVERSION})
target_link_libraries(conversion finiteVolume meshTools fileFormats)

    
add_custom_command(TARGET conversion
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E
                   copy $<TARGET_FILE:conversion> ${CMAKE_SOURCE_DIR}/../bin/$<TARGET_FILE_NAME:conversion>)
