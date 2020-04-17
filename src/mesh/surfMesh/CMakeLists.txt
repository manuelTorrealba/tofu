
include_directories(../../core)
include_directories(../../cfd)
include_directories(../../mesh)

set(surfaceFormats surfaceFormats)

set(SOURCE_FILES_SURFMESH
surfZone/surfZone/surfZone.cpp
surfZone/surfZone/surfZoneIOList.cpp
surfZone/surfZoneIdentifier/surfZoneIdentifier.cpp
MeshedSurfaceAllocator/MeshedSurfaceIOAllocator.cpp
MeshedSurface/MeshedSurfaceCore.cpp
MeshedSurface/MeshedSurfaces.cpp
UnsortedMeshedSurface/UnsortedMeshedSurfaces.cpp
MeshedSurfaceProxy/MeshedSurfaceProxyCore.cpp
surfaceRegistry/surfaceRegistry.cpp
surfMesh/surfMesh.cpp
surfMesh/surfMeshClear.cpp
surfMesh/surfMeshIO.cpp
surfFields/surfFields/surfFields.cpp
surfFields/surfPointFields/surfPointFields.cpp
${surfaceFormats}/surfaceFormatsCore.cpp
${surfaceFormats}/ac3d/AC3DsurfaceFormatCore.cpp
${surfaceFormats}/ac3d/AC3DsurfaceFormatRunTime.cpp
${surfaceFormats}/gts/GTSsurfaceFormatRunTime.cpp
${surfaceFormats}/nas/NASsurfaceFormatRunTime.cpp
${surfaceFormats}/obj/OBJsurfaceFormatRunTime.cpp
${surfaceFormats}/obj/OBJstream.cpp
${surfaceFormats}/off/OFFsurfaceFormatRunTime.cpp
${surfaceFormats}/ofs/OFSsurfaceFormatCore.cpp
${surfaceFormats}/ofs/OFSsurfaceFormatRunTime.cpp
${surfaceFormats}/smesh/SMESHsurfaceFormatRunTime.cpp
${surfaceFormats}/starcd/STARCDsurfaceFormatCore.cpp
${surfaceFormats}/starcd/STARCDsurfaceFormatRunTime.cpp
${surfaceFormats}/stl/STLsurfaceFormatCore.cpp
${surfaceFormats}/stl/STLsurfaceFormatRunTime.cpp
${surfaceFormats}/stl/STLsurfaceFormatASCII.L
${surfaceFormats}/tri/TRIsurfaceFormatCore.cpp
${surfaceFormats}/tri/TRIsurfaceFormatRunTime.cpp
${surfaceFormats}/vtk/VTKsurfaceFormatCore.cpp
${surfaceFormats}/vtk/VTKsurfaceFormatRunTime.cpp
${surfaceFormats}/wrl/WRLsurfaceFormatCore.cpp
${surfaceFormats}/wrl/WRLsurfaceFormatRunTime.cpp
${surfaceFormats}/x3d/X3DsurfaceFormatCore.cpp
${surfaceFormats}/x3d/X3DsurfaceFormatRunTime.cpp
)

add_library(surfMesh STATIC ${SOURCE_FILES_SURFMESH})
#target_link_libraries(surfMesh fileFormats)

add_custom_command(TARGET surfMesh
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E
                   copy $<TARGET_FILE:surfMesh> ${CMAKE_SOURCE_DIR}/../lib/$<TARGET_FILE_NAME:surfMesh>)
