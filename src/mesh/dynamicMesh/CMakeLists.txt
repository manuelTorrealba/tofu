
include_directories(../../core)
include_directories(../../cfd)
include_directories(../../mesh)

set(enrichedPatch slidingInterface/enrichedPatch)
set(polyMeshModifier polyTopoChange/polyMeshModifier)
set(hexRef8 polyTopoChange/polyTopoChange/hexRef8)
set(meshModifiers meshCut/meshModifiers)
set(solidBodyMotionFunctions motionSolvers/displacement/solidBody/solidBodyMotionFunctions)


set(SOURCE_FILES_DYNAMICMESH
attachDetach/attachDetach.cpp
attachDetach/attachInterface.cpp
attachDetach/detachInterface.cpp
attachDetach/attachDetachPointMatchMap.cpp
layerAdditionRemoval/layerAdditionRemoval.cpp
layerAdditionRemoval/setLayerPairing.cpp
layerAdditionRemoval/addCellLayer.cpp
layerAdditionRemoval/removeCellLayer.cpp
${enrichedPatch}/enrichedPatch.cpp
${enrichedPatch}/enrichedPatchPointMap.cpp
${enrichedPatch}/enrichedPatchFaces.cpp
${enrichedPatch}/enrichedPatchPointPoints.cpp
${enrichedPatch}/enrichedPatchCutFaces.cpp
${enrichedPatch}/enrichedPatchMasterPoints.cpp
${polyMeshModifier}/polyMeshModifier.cpp
${polyMeshModifier}/polyMeshModifierNew.cpp
polyTopoChange/polyTopoChange/topoAction/topoActions.cpp
polyTopoChange/polyTopoChanger/polyTopoChanger.cpp
polyTopoChange/polyTopoChange/polyTopoChange.cpp
polyTopoChange/polyTopoChange/addPatchCellLayer.cpp
polyTopoChange/polyTopoChange/pointEdgeCollapse/pointEdgeCollapse.cpp
polyTopoChange/polyTopoChange/edgeCollapser.cpp
polyTopoChange/polyTopoChange/faceCollapser.cpp
polyTopoChange/polyTopoChange/removeCells.cpp
polyTopoChange/polyTopoChange/removeFaces.cpp
polyTopoChange/polyTopoChange/refinementData.cpp
polyTopoChange/polyTopoChange/refinementDistanceData.cpp
polyTopoChange/polyTopoChange/removePoints.cpp
polyTopoChange/polyTopoChange/combineFaces.cpp
polyTopoChange/polyTopoChange/duplicatePoints.cpp
polyTopoChange/polyTopoChange/tetDecomposer.cpp
${hexRef8}/hexRef8.cpp
${hexRef8}/hexRef8Data.cpp
${hexRef8}/refinementHistory.cpp
slidingInterface/slidingInterface.cpp
slidingInterface/slidingInterfaceProjectPoints.cpp
slidingInterface/coupleSlidingInterface.cpp
slidingInterface/slidingInterfaceAttachedAddressing.cpp
slidingInterface/slidingInterfaceClearCouple.cpp
slidingInterface/decoupleSlidingInterface.cpp
perfectInterface/perfectInterface.cpp
boundaryMesh/boundaryMesh.cpp
boundaryPatch/boundaryPatch.cpp
setUpdater/setUpdater.cpp
${meshModifiers}/boundaryCutter/boundaryCutter.cpp
${meshModifiers}/meshCutter/meshCutter.cpp
${meshModifiers}/meshCutAndRemove/meshCutAndRemove.cpp
${meshModifiers}/undoableMeshCutter/undoableMeshCutter.cpp
${meshModifiers}/refinementIterator/refinementIterator.cpp
${meshModifiers}/multiDirRefinement/multiDirRefinement.cpp
meshCut/cellLooper/cellLooper.cpp
meshCut/cellLooper/topoCellLooper.cpp
meshCut/cellLooper/geomCellLooper.cpp
meshCut/cellLooper/hexCellLooper.cpp
meshCut/directions/directions.cpp
meshCut/directions/directionInfo/directionInfo.cpp
meshCut/edgeVertex/edgeVertex.cpp
meshCut/cellCuts/cellCuts.cpp
meshCut/splitCell/splitCell.cpp
meshCut/refineCell/refineCell.cpp
meshCut/wallLayerCells/wallLayerCells.cpp
meshCut/wallLayerCells/wallNormalInfo/wallNormalInfo.cpp
polyTopoChange/attachPolyTopoChanger/attachPolyTopoChanger.cpp
polyTopoChange/repatchPolyTopoChanger/repatchPolyTopoChanger.cpp
fvMeshAdder/fvMeshAdder.cpp
fvMeshDistribute/fvMeshDistribute.cpp
polyMeshAdder/faceCoupleInfo.cpp
polyMeshAdder/polyMeshAdder.cpp
fvMeshTools/fvMeshTools.cpp
fvMeshSubset/fvMeshSubset.cpp
motionSmoother/motionSmoother.cpp
motionSmoother/motionSmootherAlgo.cpp
motionSmoother/motionSmootherAlgoCheck.cpp
motionSmoother/motionSmootherData.cpp
motionSmoother/polyMeshGeometry/polyMeshGeometry.cpp
motionSmoother/badQualityToCell/badQualityToCell.cpp
motionSmoother/badQualityToFace/badQualityToFace.cpp
motionSolvers/motionSolver/motionSolver.cpp
motionSolvers/displacement/points0/points0MotionSolver.cpp
motionSolvers/displacement/displacement/displacementMotionSolver.cpp
motionSolvers/displacement/interpolation/displacementInterpolationMotionSolver.cpp
motionSolvers/displacement/layeredSolver/displacementLayeredMotionMotionSolver.cpp
motionSolvers/displacement/layeredSolver/pointEdgeStructuredWalk.cpp
motionSolvers/displacement/linearSolver/displacementLinearMotionMotionSolver.cpp
motionSolvers/componentDisplacement/componentDisplacementMotionSolver.cpp
motionSolvers/velocity/velocityMotionSolver.cpp
motionSolvers/componentVelocity/componentVelocityMotionSolver.cpp
motionSolvers/displacement/solidBody/solidBodyMotionSolver.cpp
motionSolvers/displacement/solidBody/multiSolidBodyMotionSolver.cpp
${solidBodyMotionFunctions}/solidBodyMotionFunction/solidBodyMotionFunction.cpp
${solidBodyMotionFunctions}/solidBodyMotionFunction/solidBodyMotionFunctionNew.cpp
${solidBodyMotionFunctions}/SDA/SDA.cpp
${solidBodyMotionFunctions}/tabulated6DoFMotion/tabulated6DoFMotion.cpp
${solidBodyMotionFunctions}/linearMotion/linearMotion.cpp
${solidBodyMotionFunctions}/rotatingMotion/rotatingMotion.cpp
${solidBodyMotionFunctions}/axisRotationMotion/axisRotationMotion.cpp
${solidBodyMotionFunctions}/multiMotion/multiMotion.cpp
${solidBodyMotionFunctions}/oscillatingLinearMotion/oscillatingLinearMotion.cpp
${solidBodyMotionFunctions}/oscillatingRotatingMotion/oscillatingRotatingMotion.cpp
motionSolvers/displacement/solidBody/pointPatchFields/derived/solidBodyMotionDisplacement/solidBodyMotionDisplacementPointPatchVectorField.cpp
createShellMesh/createShellMesh.cpp
extrudePatchMesh/extrudePatchMesh.cpp
polyMeshFilter/polyMeshFilterSettings.cpp
polyMeshFilter/polyMeshFilter.cpp
pointPatchDist/externalPointEdgePoint.cpp
pointPatchDist/pointPatchDist.cpp
)

add_library(dynamicMesh STATIC ${SOURCE_FILES_DYNAMICMESH})
#LIB_LIBS = -lfiniteVolume -ltriSurface -lextrudeModel

    
add_custom_command(TARGET dynamicMesh
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E
                   copy $<TARGET_FILE:dynamicMesh> ${CMAKE_SOURCE_DIR}/../lib/$<TARGET_FILE_NAME:dynamicMesh>)
