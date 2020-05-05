
include_directories(../../core)
include_directories(../../cfd)
include_directories(../../mesh)

set(SOURCE_FILES_LAGRANGIAN
basic/particle/particle.cpp
basic/particle/particleIO.cpp
basic/passiveParticle/passiveParticleCloud.cpp
basic/indexedParticle/indexedParticleCloud.cpp
basic/InteractionLists/referredWallFace/referredWallFace.cpp
)

add_library(lagrangian SHARED ${SOURCE_FILES_LAGRANGIAN})
target_link_libraries(lagrangian meshTools)

    
add_custom_command(TARGET lagrangian
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E
                   copy $<TARGET_FILE:lagrangian> ${CMAKE_SOURCE_DIR}/../bin/$<TARGET_FILE_NAME:lagrangian>)
