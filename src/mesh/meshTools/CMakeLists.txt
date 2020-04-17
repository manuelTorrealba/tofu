
include_directories(../../core)
include_directories(../../cfd)
include_directories(../../mesh)

set(em edgeMesh)
set(edgeMeshFormats ${em}/edgeMeshFormats)
set(eem ${em}/extendedEdgeMesh)
set(efm ${eem}/extendedFeatureEdgeMesh)
set(csys coordinateSystems)
set(algorithms algorithms)
set(pWave ${algorithms}/PointEdgeWave)
set(patchWave ${algorithms}/PatchEdgeFaceWave)
set(meshWave ${algorithms}/MeshWave)
set(topoSets sets/topoSets)
set(cellSources  sets/cellSources)
set(pointSources sets/pointSources)
set(faceSources sets/faceSources)
set(faceZoneSources sets/faceZoneSources)
set(cellZoneSources sets/cellZoneSources)
set(pointZoneSources sets/pointZoneSources)
set(booleanOps triSurface/booleanOps)
set(booleanSurface ${booleanOps}/booleanSurface)
set(surfaceIntersection ${booleanOps}/surfaceIntersection)
set(intersectedSurface ${booleanOps}/intersectedSurface)
set(AMI AMIInterpolation)
set(AMIOverlapPatches ${AMI}/patches/cyclicRepeatAMI)
set(AMICycPatches ${AMI}/patches/cyclicAMI)
set(ACMICycPatches ${AMI}/patches/cyclicACMI)


set(SOURCE_FILES_MESHTOOLS
${em}/edgeMesh.cpp
${em}/edgeMeshIO.cpp
${em}/edgeMeshNew.cpp
${edgeMeshFormats}/edgeMeshFormatsCore.cpp
${edgeMeshFormats}/edgeMesh/edgeMeshFormat.cpp
${edgeMeshFormats}/edgeMesh/edgeMeshFormatRunTime.cpp
${edgeMeshFormats}/extendedFeatureEdgeMesh/extendedFeatureEdgeMeshFormat.cpp
${edgeMeshFormats}/extendedFeatureEdgeMesh/extendedFeatureEdgeMeshFormatRunTime.cpp
${edgeMeshFormats}/nas/NASedgeFormat.cpp
${edgeMeshFormats}/nas/NASedgeFormatRunTime.cpp
${edgeMeshFormats}/obj/OBJedgeFormat.cpp
${edgeMeshFormats}/obj/OBJedgeFormatRunTime.cpp
${edgeMeshFormats}/starcd/STARCDedgeFormat.cpp
${edgeMeshFormats}/starcd/STARCDedgeFormatRunTime.cpp
${edgeMeshFormats}/vtk/VTKedgeFormat.cpp
${edgeMeshFormats}/vtk/VTKedgeFormatRunTime.cpp
${em}/featureEdgeMesh/featureEdgeMesh.cpp
${eem}/extendedEdgeMesh.cpp
${eem}/extendedEdgeMeshNew.cpp
${eem}/extendedEdgeMeshFormats/extendedEdgeMeshFormat/extendedEdgeMeshFormat.cpp
${eem}/extendedEdgeMeshFormats/extendedEdgeMeshFormat/extendedEdgeMeshFormatRunTime.cpp
${efm}/extendedFeatureEdgeMesh.cpp
cellClassification/cellClassification.cpp
cellClassification/cellInfo.cpp
cellQuality/cellQuality.cpp
cellDist/cellDistFuncs.cpp
cellDist/patchWave/patchWave.cpp
cellDist/wallPoint/wallPoint.cpp
cellFeatures/cellFeatures.cpp
${csys}/coordinateSystem.cpp
${csys}/coordinateSystemNew.cpp
${csys}/coordinateSystems.cpp
${csys}/cylindricalCS.cpp
${csys}/cartesianCS.cpp
${csys}/coordinateRotation/axesRotation.cpp
${csys}/coordinateRotation/coordinateRotation.cpp
${csys}/coordinateRotation/coordinateRotationNew.cpp
${csys}/coordinateRotation/EulerCoordinateRotation.cpp
${csys}/coordinateRotation/STARCDCoordinateRotation.cpp
${csys}/coordinateRotation/cylindrical.cpp
edgeFaceCirculator/edgeFaceCirculator.cpp
polyMeshZipUpCells/polyMeshZipUpCells.cpp
primitiveMeshGeometry/primitiveMeshGeometry.cpp
meshSearch/meshSearch.cpp
meshSearch/meshSearchFACE_CENTRE_TRISMeshObject.cpp
meshSearch/meshSearchMeshObject.cpp
meshTools/meshTools.cpp
${pWave}/PointEdgeWaveName.cpp
${pWave}/pointEdgePoint.cpp
${patchWave}/PatchEdgeFaceWaveName.cpp
${patchWave}/patchEdgeFaceInfo.cpp
${patchWave}/patchPatchDist.cpp
${patchWave}/patchEdgeFaceRegion.cpp
${patchWave}/patchEdgeFaceRegions.cpp
${meshWave}/MeshWaveName.cpp
${meshWave}/FaceCellWaveName.cpp
regionSplit/regionSplit.cpp
regionSplit/localPointRegion.cpp
indexedOctree/treeDataEdge.cpp
indexedOctree/treeDataFace.cpp
indexedOctree/treeDataPoint.cpp
indexedOctree/treeDataPrimitivePatchName.cpp
indexedOctree/treeDataTriSurface.cpp
searchableSurfaces/searchableSurface/searchableSurface.cpp
searchableSurfaces/searchableBox/searchableBox.cpp
searchableSurfaces/searchableCylinder/searchableCylinder.cpp
searchableSurfaces/searchableDisk/searchableDisk.cpp
searchableSurfaces/searchablePlane/searchablePlane.cpp
searchableSurfaces/searchablePlate/searchablePlate.cpp
searchableSurfaces/searchableSphere/searchableSphere.cpp
searchableSurfaces/searchableSurfaceCollection/searchableSurfaceCollection.cpp
searchableSurfaces/searchableSurfaces/searchableSurfaces.cpp
searchableSurfaces/searchableSurfacesQueries/searchableSurfacesQueries.cpp
searchableSurfaces/searchableSurfaceWithGaps/searchableSurfaceWithGaps.cpp
searchableSurfaces/triSurfaceMesh/triSurfaceMesh.cpp
searchableSurfaces/triSurfaceMesh/extractCloseness.cpp
searchableSurfaces/closedTriSurfaceMesh/closedTriSurfaceMesh.cpp
searchableSurfaces/searchableExtrudedCircle/searchableExtrudedCircle.cpp
${topoSets}/cellSet.cpp
${topoSets}/topoSet.cpp
${topoSets}/faceSet.cpp
${topoSets}/pointSet.cpp
${topoSets}/cellZoneSet.cpp
${topoSets}/faceZoneSet.cpp
${topoSets}/pointZoneSet.cpp
sets/topoSetSource/topoSetSource.cpp
${cellSources}/faceToCell/faceToCell.cpp
${cellSources}/fieldToCell/fieldToCell.cpp
${cellSources}/pointToCell/pointToCell.cpp
${cellSources}/shapeToCell/shapeToCell.cpp
${cellSources}/boxToCell/boxToCell.cpp
${cellSources}/regionToCell/regionToCell.cpp
${cellSources}/rotatedBoxToCell/rotatedBoxToCell.cpp
${cellSources}/labelToCell/labelToCell.cpp
${cellSources}/surfaceToCell/surfaceToCell.cpp
${cellSources}/cellToCell/cellToCell.cpp
${cellSources}/nearestToCell/nearestToCell.cpp
${cellSources}/nbrToCell/nbrToCell.cpp
${cellSources}/zoneToCell/zoneToCell.cpp
${cellSources}/sphereToCell/sphereToCell.cpp
${cellSources}/cylinderToCell/cylinderToCell.cpp
${cellSources}/faceZoneToCell/faceZoneToCell.cpp
${cellSources}/cylinderAnnulusToCell/cylinderAnnulusToCell.cpp
${cellSources}/targetVolumeToCell/targetVolumeToCell.cpp
${faceSources}/faceToFace/faceToFace.cpp
${faceSources}/labelToFace/labelToFace.cpp
${faceSources}/cellToFace/cellToFace.cpp
${faceSources}/normalToFace/normalToFace.cpp
${faceSources}/pointToFace/pointToFace.cpp
${faceSources}/patchToFace/patchToFace.cpp
${faceSources}/boundaryToFace/boundaryToFace.cpp
${faceSources}/zoneToFace/zoneToFace.cpp
${faceSources}/boxToFace/boxToFace.cpp
${faceSources}/regionToFace/regionToFace.cpp
${faceSources}/cylinderToFace/cylinderToFace.cpp
${faceSources}/cylinderAnnulusToFace/cylinderAnnulusToFace.cpp
${pointSources}/labelToPoint/labelToPoint.cpp
${pointSources}/pointToPoint/pointToPoint.cpp
${pointSources}/cellToPoint/cellToPoint.cpp
${pointSources}/faceToPoint/faceToPoint.cpp
${pointSources}/boxToPoint/boxToPoint.cpp
${pointSources}/surfaceToPoint/surfaceToPoint.cpp
${pointSources}/zoneToPoint/zoneToPoint.cpp
${pointSources}/nearestToPoint/nearestToPoint.cpp
${faceZoneSources}/faceZoneToFaceZone/faceZoneToFaceZone.cpp
${faceZoneSources}/setsToFaceZone/setsToFaceZone.cpp
${faceZoneSources}/setToFaceZone/setToFaceZone.cpp
${faceZoneSources}/setAndNormalToFaceZone/setAndNormalToFaceZone.cpp
${faceZoneSources}/searchableSurfaceToFaceZone/searchableSurfaceToFaceZone.cpp
${cellZoneSources}/setToCellZone/setToCellZone.cpp
${pointZoneSources}/setToPointZone/setToPointZone.cpp
momentOfInertia/momentOfInertia.cpp
surfaceSets/surfaceSets.cpp
triSurface/orientedSurface/orientedSurface.cpp
triSurface/surfaceLocation/surfaceLocation.cpp
${surfaceIntersection}/surfaceIntersection.cpp
${surfaceIntersection}/surfaceIntersectionFuncs.cpp
${surfaceIntersection}/edgeIntersections.cpp
${booleanSurface}/booleanSurface.cpp
${intersectedSurface}/intersectedSurface.cpp
${intersectedSurface}/edgeSurface.cpp
triSurface/triSurfaceSearch/triSurfaceSearch.cpp
triSurface/triSurfaceSearch/triSurfaceRegionSearch.cpp
triSurface/triangleFuncs/triangleFuncs.cpp
triSurface/surfaceFeatures/surfaceFeatures.cpp
triSurface/triSurfaceTools/triSurfaceTools.cpp
triSurface/triSurfaceTools/geompack/geompack.cpp
triSurface/triSurfaceTools/pointToPointPlanarInterpolation.cpp
twoDPointCorrector/twoDPointCorrector.cpp
${AMI}/AMIInterpolation/AMIInterpolationName.cpp
${AMI}/AMIInterpolation/AMIPatchToPatchInterpolation.cpp
${AMI}/faceAreaIntersect/faceAreaIntersect.cpp
${AMI}/GAMG/interfaces/cyclicAMIGAMGInterface/cyclicAMIGAMGInterface.cpp
${AMI}/GAMG/interfaceFields/cyclicAMIGAMGInterfaceField/cyclicAMIGAMGInterfaceField.cpp
${AMI}/GAMG/interfaces/cyclicACMIGAMGInterface/cyclicACMIGAMGInterface.cpp
${AMI}/GAMG/interfaceFields/cyclicACMIGAMGInterfaceField/cyclicACMIGAMGInterfaceField.cpp
${AMI}/GAMG/interfaces/cyclicRepeatAMIGAMGInterface/cyclicRepeatAMIGAMGInterface.cpp
${AMI}/GAMG/interfaceFields/cyclicRepeatAMIGAMGInterfaceField/cyclicRepeatAMIGAMGInterfaceField.cpp
${AMICycPatches}/cyclicAMILduInterfaceField/cyclicAMILduInterface.cpp
${AMICycPatches}/cyclicAMILduInterfaceField/cyclicAMILduInterfaceField.cpp
${AMICycPatches}/cyclicAMIPolyPatch/cyclicAMIPolyPatch.cpp
${AMICycPatches}/cyclicAMIPointPatch/cyclicAMIPointPatch.cpp
${AMICycPatches}/cyclicAMIPointPatchField/cyclicAMIPointPatchFields.cpp
${ACMICycPatches}/cyclicACMILduInterfaceField/cyclicACMILduInterface.cpp
${ACMICycPatches}/cyclicACMILduInterfaceField/cyclicACMILduInterfaceField.cpp
${ACMICycPatches}/cyclicACMIPolyPatch/cyclicACMIPolyPatch.cpp
${ACMICycPatches}/cyclicACMIPointPatch/cyclicACMIPointPatch.cpp
${ACMICycPatches}/cyclicACMIPointPatchField/cyclicACMIPointPatchFields.cpp
${AMIOverlapPatches}/cyclicRepeatAMILduInterfaceField/cyclicRepeatAMILduInterface.cpp
${AMIOverlapPatches}/cyclicRepeatAMILduInterfaceField/cyclicRepeatAMILduInterfaceField.cpp
${AMIOverlapPatches}/cyclicRepeatAMIPolyPatch/cyclicRepeatAMIPolyPatch.cpp
${AMIOverlapPatches}/cyclicRepeatAMIPointPatch/cyclicRepeatAMIPointPatch.cpp
${AMIOverlapPatches}/cyclicRepeatAMIPointPatchField/cyclicRepeatAMIPointPatchFields.cpp
mappedPatches/mappedPolyPatch/mappedPatchBase.cpp
mappedPatches/mappedPolyPatch/mappedPolyPatch.cpp
mappedPatches/mappedPolyPatch/mappedWallPolyPatch.cpp
mappedPatches/mappedPolyPatch/mappedVariableThicknessWallPolyPatch.cpp
mappedPatches/mappedPointPatch/mappedPointPatch.cpp
mappedPatches/mappedPointPatch/mappedWallPointPatch.cpp
meshStructure/meshStructure.cpp
meshStructure/topoDistanceData.cpp
meshStructure/pointTopoDistanceData.cpp
regionCoupled/patches/regionCoupledPolyPatch/regionCoupledBase.cpp
regionCoupled/patches/regionCoupledPolyPatch/regionCoupledPolyPatch.cpp
regionCoupled/patches/regionCoupledPolyPatch/regionCoupledWallPolyPatch.cpp
regionCoupled/patches/regionCoupledLduInterface/regionCoupledLduInterface.cpp
regionCoupled/patches/regionCoupledPointPatch/regionCoupledPointPatch.cpp
regionCoupled/patches/regionCoupledPointPatch/regionCoupledWallPointPatch.cpp
regionCoupled/GAMG/interfaces/regionCoupledGAMGInterface/regionCoupledBaseGAMGInterface.cpp
regionCoupled/GAMG/interfaces/regionCoupledGAMGInterface/regionCoupledGAMGInterface.cpp
regionCoupled/GAMG/interfaces/regionCoupledGAMGInterface/regionCoupledWallGAMGInterface.cpp
regionCoupled/GAMG/interfaceFields/regionCoupledGAMGInterfaceField/regionCoupledGAMGInterfaceField.cpp
regionCoupled/GAMG/interfaceFields/regionCoupledGAMGInterfaceField/regionCoupledWallGAMGInterfaceField.cpp
tetOverlapVolume/tetOverlapVolume.cpp
)

add_library(meshTools STATIC ${SOURCE_FILES_MESHTOOLS})

add_custom_command(TARGET meshTools
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E
                   copy $<TARGET_FILE:meshTools> ${CMAKE_SOURCE_DIR}/../lib/$<TARGET_FILE_NAME:meshTools>)
