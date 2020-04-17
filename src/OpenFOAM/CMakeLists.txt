cmake_minimum_required (VERSION 3.0)

project (OpenFOAM)

add_definitions(-DWM_LABEL_SIZE=64 -DWM_DP -DNoRepository)

include_directories(../)
link_directories (../../lib)

 set(fileops global/fileOperations)
 set(bools primitives/bools)
 set(chars ./primitives/chars)
 set(ints ./primitives/ints)
 set(strings ./primitives/strings)
 set(ops primitives/ops)
 set(sha1 primitives/hashes/SHA1)
 set(ranges primitives/ranges)
 set(spatialVectorAlgebra primitives/spatialVectorAlgebra)
 set(Streams db/IOstreams)
 set(IOstreams ${Streams}/IOstreams)
 set(Sstreams ${Streams}/Sstreams)
 set(gzstream ${Streams}/gzstream)
 set(Fstreams ${Streams}/Fstreams)
 set(Tstreams ${Streams}/Tstreams)
 set(StringStreams ${Streams}/StringStreams)
 set(Pstreams ${Streams}/Pstreams)
 set(dictionary db/dictionary)
 set(entry ${dictionary}/entry)
 set(primitiveEntry ${dictionary}/primitiveEntry)
 set(dictionaryEntry ${dictionary}/dictionaryEntry)
 set(dictionaryListEntry ${dictionary}/dictionaryListEntry)
 set(functionEntries ${dictionary}/functionEntries)
 set(IOdictionary db/IOobjects/IOdictionary)
 set(IOobject db/IOobject)
 set(regIOobject db/regIOobject)
 set(dll db/dynamicLibrary)
 set(Time db/Time)
 set(scalarMatrices matrices/scalarMatrices)
 set(LUscalarMatrix matrices/LUscalarMatrix)
 set(lduMatrix matrices/lduMatrix)
 set(lduAddressing ${lduMatrix}/lduAddressing)
 set(lduInterfaceFields ${lduAddressing}/lduInterfaceFields)
 set(GAMG ${lduMatrix}/solvers/GAMG)
 set(GAMGInterfaces ${GAMG}/interfaces)
 set(GAMGInterfaceFields ${GAMG}/interfaceFields)
 set(GAMGAgglomerations ${GAMG}/GAMGAgglomerations)
 set(GAMGAgglomeration ${GAMGAgglomerations}/GAMGAgglomeration)
 set(pairGAMGAgglomeration ${GAMGAgglomerations}/pairGAMGAgglomeration)
 set(algebraicPairGAMGAgglomeration ${GAMGAgglomerations}/algebraicPairGAMGAgglomeration)
 set(dummyAgglomeration ${GAMGAgglomerations}/dummyAgglomeration)
 set(GAMGProcAgglomerations ${GAMG}/GAMGProcAgglomerations)
 set(GAMGProcAgglomeration ${GAMGProcAgglomerations}/GAMGProcAgglomeration)
 set(masterCoarsestGAMGProcAgglomeration ${GAMGProcAgglomerations}/masterCoarsestGAMGProcAgglomeration)
 set(manualGAMGProcAgglomeration ${GAMGProcAgglomerations}/manualGAMGProcAgglomeration)
 set(eagerGAMGProcAgglomeration ${GAMGProcAgglomerations}/eagerGAMGProcAgglomeration)
 set(noneGAMGProcAgglomeration ${GAMGProcAgglomerations}/noneGAMGProcAgglomeration)
 set(procFacesGAMGProcAgglomeration ${GAMGProcAgglomerations}/procFacesGAMGProcAgglomeration)
 set(LduMatrixN matrices/LduMatrixN)
 set(primitiveShapes meshes/primitiveShapes)
 set(meshShapes meshes/meshShapes)
 set(face ${meshShapes}/face)
 set(cell ${meshShapes}/cell)
 set(tetCell ${meshShapes}/tetCell)
 set(cellModeller ${meshShapes}/cellModeller)
 set(cellModel ${meshShapes}/cellModel)
 set(cellShape ${meshShapes}/cellShape)
 set(polyMesh meshes/polyMesh)
 set(polyPatches ${polyMesh}/polyPatches)
 set(basicPolyPatches ${polyPatches}/basic)
 set(constraintPolyPatches ${polyPatches}/constraint)
 set(derivedPolyPatches ${polyPatches}/derived)
 set(polyBoundaryMesh ${polyMesh}/polyBoundaryMesh)
 set(globalMeshData ${polyMesh}/globalMeshData)
 set(zone ${polyMesh}/zones/zone)
 set(cellZone ${polyMesh}/zones/cellZone)
 set(faceZone ${polyMesh}/zones/faceZone)
 set(pointZone ${polyMesh}/zones/pointZone)
 set(polyMeshCheck ${polyMesh}/polyMeshCheck)
 set(primitiveMesh meshes/primitiveMesh)
 set(primitiveMeshCheck ${primitiveMesh}/primitiveMeshCheck)
 set(primitivePatch ${primitiveMesh}/primitivePatch)
 set(cellMatcher ${meshShapes}/cellMatcher)
 set(mapPolyMesh ${polyMesh}/mapPolyMesh)
 set(PrimitivePatchN ${primitiveMesh}/PrimitivePatchN)
 set(pointMesh meshes/pointMesh)
 set(pointMeshMapper ${pointMesh}/pointMeshMapper)
 set(pointPatches ${pointMesh}/pointPatches)
 set(basicPointPatches ${pointPatches}/basic)
 set(constraintPointPatches ${pointPatches}/constraint)
 set(derivedPointPatches ${pointPatches}/derived)
 set(pointBoundaryMesh ${pointMesh}/pointBoundaryMesh)
 set(meshTools meshes/meshTools)
 set(Fields fields/Fields)
 set(pointPatchFields fields/pointPatchFields)
 set(basicPointPatchFields ${pointPatchFields}/basic)
 set(constraintPointPatchFields ${pointPatchFields}/constraint)
 set(derivedPointPatchFields ${pointPatchFields}/derived)
 set(interpolations interpolations)
 set(interpolation ${interpolations}/interpolation)
 set(interpolationWeights ${interpolations}/interpolationWeights)
 set(writers graph/writers)



set(SOURCE_FILES
global/globalver.cpp
#/* global/constants/constants.cpp in global.cppver */
#/* global/constants/dimensionedConstants.cpp in global.cppver */
global/argList/argList.cpp
global/clock/clock.cpp
global/etcFiles/etcFiles.cpp
${fileops}/fileOperation/fileOperation.cpp
${fileops}/fileOperationInitialise/fileOperationInitialise.cpp
${fileops}/uncollatedFileOperation/uncollatedFileOperation.cpp
${fileops}/masterUncollatedFileOperation/masterUncollatedFileOperation.cpp
${fileops}/collatedFileOperation/collatedFileOperation.cpp
${fileops}/collatedFileOperation/hostCollatedFileOperation.cpp
${fileops}/collatedFileOperation/threadedCollatedOFstream.cpp
${fileops}/collatedFileOperation/OFstreamCollator.cpp
${bools}/bool/bool.cpp
${bools}/bool/boolIO.cpp
${bools}/Switch/Switch.cpp
${bools}/Switch/SwitchIO.cpp
${bools}/lists/boolList.cpp
${chars}/char/charIO.cpp
${chars}/wchar/wcharIO.cpp
primitives/direction/directionIO.cpp
${ints}/uint32/uint32.cpp
${ints}/uint32/uint32IO.cpp
${ints}/uint64/uint64.cpp
${ints}/uint64/uint64IO.cpp
${ints}/uint/uintIO.cpp
${ints}/int32/int32.cpp
${ints}/int32/int32IO.cpp
${ints}/int64/int64.cpp
${ints}/int64/int64IO.cpp
${ints}/int/intIO.cpp
${ints}/label/label.cpp
${ints}/uLabel/uLabel.cpp
${ints}/lists/labelIOList.cpp
${ints}/lists/labelListIOList.cpp
primitives/Scalar/longDoubleScalar/longDoubleScalar.cpp
primitives/Scalar/doubleScalar/doubleScalar.cpp
primitives/Scalar/floatScalar/floatScalar.cpp
primitives/Scalar/scalar/scalar.cpp
primitives/Scalar/scalar/invIncGamma.cpp
primitives/Scalar/lists/scalarList.cpp
primitives/Scalar/lists/scalarIOList.cpp
primitives/Scalar/lists/scalarListIOList.cpp
primitives/DiagTensor/diagTensor/diagTensor.cpp
primitives/SphericalTensor/sphericalTensor/sphericalTensor.cpp
primitives/SphericalTensor/labelSphericalTensor/labelSphericalTensor.cpp
primitives/SymmTensor/labelSymmTensor/labelSymmTensor.cpp
primitives/SymmTensor/symmTensor/symmTensor.cpp
primitives/Tensor/labelTensor/labelTensor.cpp
primitives/Tensor/tensor/tensor.cpp
primitives/Tensor/lists/sphericalTensorList.cpp
primitives/Tensor/lists/symmTensorList.cpp
primitives/Tensor/lists/tensorList.cpp
primitives/Vector/complexVector/complexVector.cpp
# #if !defined(WM_SP)
# #primitives/Vector/floatVector/floatVector.cpp
# #primitives/Tensor/floatTensor/floatTensor.cpp
# #endif
primitives/Vector/labelVector/labelVector.cpp
primitives/Vector/vector/vector.cpp
primitives/Vector/lists/vectorList.cpp
primitives/Vector/lists/vectorIOList.cpp
primitives/Vector/lists/vectorListIOList.cpp
primitives/Tensor2D/tensor2D/tensor2D.cpp
primitives/SphericalTensor2D/sphericalTensor2D/sphericalTensor2D.cpp
primitives/SymmTensor2D/symmTensor2D/symmTensor2D.cpp
primitives/Vector2D/vector2D/vector2D.cpp
primitives/complex/complex.cpp
primitives/globalIndexAndTransform/globalIndexAndTransform.cpp
primitives/globalIndexAndTransform/vectorTensorTransform/vectorTensorTransform.cpp
primitives/quaternion/quaternion.cpp
primitives/septernion/septernion.cpp
primitives/triad/triad.cpp
# #/* Run-time selectable functions */
primitives/functions/Function1/makeFunction1s.cpp
primitives/functions/Function1/ramp/ramp.cpp
primitives/functions/Function1/linearRamp/linearRamp.cpp
primitives/functions/Function1/quadraticRamp/quadraticRamp.cpp
primitives/functions/Function1/quarterSineRamp/quarterSineRamp.cpp
primitives/functions/Function1/quarterCosineRamp/quarterCosineRamp.cpp
primitives/functions/Function1/halfCosineRamp/halfCosineRamp.cpp
primitives/functions/Polynomial/polynomialFunction.cpp
primitives/subModelBase/subModelBase.cpp
${strings}/string/string.cpp
${strings}/string/stringIO.cpp
${strings}/string/stringIOList.cpp
${strings}/word/word.cpp
${strings}/word/wordIO.cpp
${strings}/word/wordIOList.cpp
${strings}/fileName/fileName.cpp
${strings}/fileName/fileNameIO.cpp
${strings}/keyType/keyType.cpp
${strings}/wordRe/wordRe.cpp
${strings}/lists/hashedWordList.cpp
${strings}/stringOps/stringOps.cpp
primitives/hashes/Hasher/Hasher.cpp
${ops}/flipOp.cpp
${sha1}/SHA1.cpp
${sha1}/SHA1Digest.cpp
primitives/Random/Random.cpp
${ranges}/labelRange/labelRange.cpp
${ranges}/labelRange/labelRanges.cpp
${ranges}/scalarRange/scalarRange.cpp
${ranges}/scalarRange/scalarRanges.cpp
${spatialVectorAlgebra}/SpatialVector/spatialVector/spatialVector.cpp
${spatialVectorAlgebra}/SpatialTensor/spatialTensor/spatialTensor.cpp
${spatialVectorAlgebra}/CompactSpatialTensor/compactSpatialTensor/compactSpatialTensor.cpp
primitives/polynomialEqns/cubicEqn/cubicEqn.cpp
primitives/polynomialEqns/quadraticEqn/quadraticEqn.cpp
primitives/Barycentric/barycentric/barycentric.cpp
primitives/Barycentric2D/barycentric2D/barycentric2D.cpp
containers/HashTables/HashTable/HashTableCore.cpp
containers/HashTables/StaticHashTable/StaticHashTableCore.cpp
containers/Lists/SortableList/ParSortableListName.cpp
containers/Lists/PackedList/PackedListCore.cpp
containers/Lists/PackedList/PackedBoolList.cpp
containers/Lists/ListOps/ListOps.cpp
containers/LinkedLists/linkTypes/SLListBase/SLListBase.cpp
containers/LinkedLists/linkTypes/DLListBase/DLListBase.cpp
${Streams}/token/tokenIO.cpp
${IOstreams}/IOstream.cpp
${IOstreams}/Istream.cpp
${IOstreams}/Ostream.cpp
${Sstreams}/ISstream.cpp
${Sstreams}/OSstream.cpp
${Sstreams}/SstreamsPrint.cpp
${Sstreams}/readHexLabel.cpp
${Sstreams}/prefixOSstream.cpp
${gzstream}/gzstream.cpp
${Fstreams}/IFstream.cpp
${Fstreams}/OFstream.cpp
${Fstreams}/masterOFstream.cpp
${Tstreams}/ITstream.cpp
${StringStreams}/StringStreamsPrint.cpp
${Pstreams}/UIPstream.cpp
${Pstreams}/IPstream.cpp
#/* ${Pstreams}/UPstream.cpp in global.cppver */
${Pstreams}/UPstreamCommsStruct.cpp
${Pstreams}/Pstream.cpp
${Pstreams}/UOPstream.cpp
${Pstreams}/OPstream.cpp
${Pstreams}/PstreamBuffers.cpp
${dictionary}/dictionary.cpp
${dictionary}/dictionaryIO.cpp
${entry}/entry.cpp
${entry}/entryIO.cpp
${primitiveEntry}/primitiveEntry.cpp
${primitiveEntry}/primitiveEntryIO.cpp
${dictionaryEntry}/dictionaryEntry.cpp
${dictionaryEntry}/dictionaryEntryIO.cpp
${dictionaryListEntry}/dictionaryListEntry.cpp
${dictionaryListEntry}/dictionaryListEntryIO.cpp
${functionEntries}/calcEntry/calcEntry.cpp
${functionEntries}/codeStream/codeStream.cpp
${functionEntries}/functionEntry/functionEntry.cpp
${functionEntries}/includeEntry/includeEntry.cpp
${functionEntries}/includeEtcEntry/includeEtcEntry.cpp
${functionEntries}/includeFuncEntry/includeFuncEntry.cpp
${functionEntries}/includeIfPresentEntry/includeIfPresentEntry.cpp
${functionEntries}/inputModeEntry/inputModeEntry.cpp
${functionEntries}/removeEntry/removeEntry.cpp
${IOdictionary}/baseIOdictionary.cpp
${IOdictionary}/baseIOdictionaryIO.cpp
${IOdictionary}/IOdictionary.cpp
${IOdictionary}/localIOdictionary.cpp
${IOdictionary}/unwatchedIOdictionary.cpp
db/IOobjects/IOMap/IOMapName.cpp
db/IOobjects/decomposedBlockData/decomposedBlockData.cpp
db/IOobjects/GlobalIOField/GlobalIOFields.cpp
${IOobject}/IOobject.cpp
${IOobject}/IOobjectIO.cpp
${IOobject}/IOobjectReadHeader.cpp
${IOobject}/IOobjectWriteHeader.cpp
#/* ${regIOobject}/regIOobject.cpp in global.cppver */
${regIOobject}/regIOobjectRead.cpp
${regIOobject}/regIOobjectWrite.cpp
db/IOobjectList/IOobjectList.cpp
db/objectRegistry/objectRegistry.cpp
db/CallbackRegistry/CallbackRegistryName.cpp
${dll}/dlLibraryTable/dlLibraryTable.cpp
${dll}/dynamicCode/dynamicCode.cpp
${dll}/dynamicCode/dynamicCodeContext.cpp
${dll}/codedBase/codedBase.cpp
db/functionObjects/functionObject/functionObject.cpp
db/functionObjects/functionObjectList/functionObjectList.cpp
db/functionObjects/writeFile/writeFile.cpp
db/functionObjects/logFiles/logFiles.cpp
db/functionObjects/writeObjectsBase/writeObjectsBase.cpp
db/functionObjects/writeLocalObjects/writeLocalObjects.cpp
db/functionObjects/timeControl/timeControl.cpp
db/functionObjects/timeControl/timeControlFunctionObject.cpp
db/functionObjects/regionFunctionObject/regionFunctionObject.cpp
${Time}/TimePaths.cpp
${Time}/TimeState.cpp
${Time}/Time.cpp
${Time}/TimeIO.cpp
${Time}/findTimes.cpp
${Time}/subCycleTime.cpp
${Time}/timeSelector.cpp
${Time}/instant/instant.cpp
dimensionSet/dimensionSet.cpp
dimensionSet/dimensionSetIO.cpp
dimensionSet/dimensionSets.cpp
dimensionedTypes/dimensionedScalar/dimensionedScalar.cpp
dimensionedTypes/dimensionedSphericalTensor/dimensionedSphericalTensor.cpp
dimensionedTypes/dimensionedSymmTensor/dimensionedSymmTensor.cpp
dimensionedTypes/dimensionedTensor/dimensionedTensor.cpp
matrices/solution/solution.cpp
${scalarMatrices}/scalarMatrices.cpp
${scalarMatrices}/SVD/SVD.cpp
${LUscalarMatrix}/LUscalarMatrix.cpp
${LUscalarMatrix}/procLduMatrix.cpp
${LUscalarMatrix}/procLduInterface.cpp
${lduMatrix}/lduMatrix/lduMatrix.cpp
${lduMatrix}/lduMatrix/lduMatrixOperations.cpp
${lduMatrix}/lduMatrix/lduMatrixATmul.cpp
${lduMatrix}/lduMatrix/lduMatrixUpdateMatrixInterfaces.cpp
${lduMatrix}/lduMatrix/lduMatrixSolver.cpp
${lduMatrix}/lduMatrix/lduMatrixSmoother.cpp
${lduMatrix}/lduMatrix/lduMatrixPreconditioner.cpp
${lduMatrix}/solvers/diagonalSolver/diagonalSolver.cpp
${lduMatrix}/solvers/smoothSolver/smoothSolver.cpp
${lduMatrix}/solvers/PCG/PCG.cpp
${lduMatrix}/solvers/PBiCG/PBiCG.cpp
${lduMatrix}/solvers/PBiCGStab/PBiCGStab.cpp
${lduMatrix}/smoothers/GaussSeidel/GaussSeidelSmoother.cpp
${lduMatrix}/smoothers/symGaussSeidel/symGaussSeidelSmoother.cpp
${lduMatrix}/smoothers/nonBlockingGaussSeidel/nonBlockingGaussSeidelSmoother.cpp
${lduMatrix}/smoothers/DIC/DICSmoother.cpp
${lduMatrix}/smoothers/FDIC/FDICSmoother.cpp
${lduMatrix}/smoothers/DICGaussSeidel/DICGaussSeidelSmoother.cpp
${lduMatrix}/smoothers/DILU/DILUSmoother.cpp
${lduMatrix}/smoothers/DILUGaussSeidel/DILUGaussSeidelSmoother.cpp
${lduMatrix}/preconditioners/noPreconditioner/noPreconditioner.cpp
${lduMatrix}/preconditioners/diagonalPreconditioner/diagonalPreconditioner.cpp
${lduMatrix}/preconditioners/DICPreconditioner/DICPreconditioner.cpp
${lduMatrix}/preconditioners/FDICPreconditioner/FDICPreconditioner.cpp
${lduMatrix}/preconditioners/DILUPreconditioner/DILUPreconditioner.cpp
${lduMatrix}/preconditioners/GAMGPreconditioner/GAMGPreconditioner.cpp
${lduAddressing}/lduAddressing.cpp
${lduAddressing}/lduInterface/lduInterface.cpp
${lduAddressing}/lduInterface/processorLduInterface.cpp
${lduAddressing}/lduInterface/cyclicLduInterface.cpp
${lduInterfaceFields}/lduInterfaceField/lduInterfaceField.cpp
${lduInterfaceFields}/processorLduInterfaceField/processorLduInterfaceField.cpp
${lduInterfaceFields}/cyclicLduInterfaceField/cyclicLduInterfaceField.cpp
${GAMG}/GAMGSolver.cpp
${GAMG}/GAMGSolverAgglomerateMatrix.cpp
${GAMG}/GAMGSolverInterpolate.cpp
${GAMG}/GAMGSolverScale.cpp
${GAMG}/GAMGSolverSolve.cpp
${GAMGInterfaces}/GAMGInterface/GAMGInterface.cpp
${GAMGInterfaces}/GAMGInterface/GAMGInterfaceNew.cpp
${GAMGInterfaces}/processorGAMGInterface/processorGAMGInterface.cpp
${GAMGInterfaces}/processorCyclicGAMGInterface/processorCyclicGAMGInterface.cpp
${GAMGInterfaces}/cyclicGAMGInterface/cyclicGAMGInterface.cpp
${GAMGInterfaceFields}/GAMGInterfaceField/GAMGInterfaceField.cpp
${GAMGInterfaceFields}/GAMGInterfaceField/GAMGInterfaceFieldNew.cpp
${GAMGInterfaceFields}/processorGAMGInterfaceField/processorGAMGInterfaceField.cpp
${GAMGInterfaceFields}/processorCyclicGAMGInterfaceField/processorCyclicGAMGInterfaceField.cpp
${GAMGInterfaceFields}/cyclicGAMGInterfaceField/cyclicGAMGInterfaceField.cpp
${GAMGAgglomeration}/GAMGAgglomeration.cpp
${GAMGAgglomeration}/GAMGAgglomerateLduAddressing.cpp
${pairGAMGAgglomeration}/pairGAMGAgglomeration.cpp
${pairGAMGAgglomeration}/pairGAMGAgglomerate.cpp
${algebraicPairGAMGAgglomeration}/algebraicPairGAMGAgglomeration.cpp
${dummyAgglomeration}/dummyAgglomeration.cpp
${GAMGProcAgglomeration}/GAMGProcAgglomeration.cpp
${masterCoarsestGAMGProcAgglomeration}/masterCoarsestGAMGProcAgglomeration.cpp
${manualGAMGProcAgglomeration}/manualGAMGProcAgglomeration.cpp
${eagerGAMGProcAgglomeration}/eagerGAMGProcAgglomeration.cpp
${noneGAMGProcAgglomeration}/noneGAMGProcAgglomeration.cpp
${procFacesGAMGProcAgglomeration}/procFacesGAMGProcAgglomeration.cpp
meshes/lduMesh/lduMesh.cpp
meshes/lduMesh/lduPrimitiveMesh.cpp
${LduMatrixN}/LduMatrix/lduMatrices.cpp
${LduMatrixN}/LduMatrix/solverPerformance.cpp
${LduMatrixN}/LduMatrix/LduInterfaceField/LduInterfaceFields.cpp
${LduMatrixN}/Smoothers/lduSmoothers.cpp
${LduMatrixN}/Preconditioners/lduPreconditioners.cpp
${LduMatrixN}/Solvers/lduSolvers.cpp
${primitiveShapes}/line/line.cpp
${primitiveShapes}/plane/plane.cpp
${primitiveShapes}/triangle/intersection.cpp
${primitiveShapes}/objectHit/pointIndexHitList.cpp
${primitiveShapes}/objectHit/pointIndexHitIOList.cpp
${meshShapes}/edge/edge.cpp
${meshShapes}/edge/edgeIOList.cpp
${face}/face.cpp
${face}/faceIntersection.cpp
${face}/faceContactSphere.cpp
${face}/faceAreaInContact.cpp
${face}/faceIOList.cpp
${cell}/cell.cpp
${cell}/oppositeCellFace.cpp
${cell}/cellIOList.cpp
${tetCell}/tetCell.cpp
${cellModeller}/cellModeller.cpp
${cellModel}/cellModel.cpp
${cellModel}/cellModelIO.cpp
${cellShape}/cellShape.cpp
${cellShape}/cellShapeEqual.cpp
${cellShape}/cellShapeIO.cpp
${cellShape}/cellShapeIOList.cpp
meshes/Identifiers/patch/patchIdentifier.cpp
meshes/Identifiers/patch/coupleGroupIdentifier.cpp
meshes/MeshObject/meshObject.cpp
${polyPatches}/polyPatch/polyPatch.cpp
${polyPatches}/polyPatch/polyPatchNew.cpp
${basicPolyPatches}/coupled/coupledPolyPatch.cpp
${basicPolyPatches}/generic/genericPolyPatch.cpp
${constraintPolyPatches}/cyclic/cyclicPolyPatch.cpp
${constraintPolyPatches}/cyclicSlip/cyclicSlipPolyPatch.cpp
${constraintPolyPatches}/oldCyclic/oldCyclicPolyPatch.cpp
${constraintPolyPatches}/empty/emptyPolyPatch.cpp
${constraintPolyPatches}/nonuniformTransformCyclic/nonuniformTransformCyclicPolyPatch.cpp
${constraintPolyPatches}/processorCyclic/processorCyclicPolyPatch.cpp
${constraintPolyPatches}/processor/processorPolyPatch.cpp
${constraintPolyPatches}/symmetryPlane/symmetryPlanePolyPatch.cpp
${constraintPolyPatches}/symmetry/symmetryPolyPatch.cpp
${constraintPolyPatches}/wedge/wedgePolyPatch.cpp
${derivedPolyPatches}/wall/wallPolyPatch.cpp
${polyBoundaryMesh}/polyBoundaryMesh.cpp
${polyBoundaryMesh}/polyBoundaryMeshEntries.cpp
meshes/ProcessorTopology/commSchedule.cpp
${globalMeshData}/globalMeshData.cpp
${globalMeshData}/globalPoints.cpp
${globalMeshData}/globalIndex.cpp
${polyMesh}/syncTools/syncTools.cpp
${polyMesh}/polyMeshTetDecomposition/polyMeshTetDecomposition.cpp
${polyMesh}/polyMeshTetDecomposition/tetIndices.cpp
${zone}/zone.cpp
${cellZone}/cellZone.cpp
${cellZone}/cellZoneNew.cpp
${faceZone}/faceZone.cpp
${faceZone}/faceZoneNew.cpp
${pointZone}/pointZone.cpp
${pointZone}/pointZoneNew.cpp
${polyMesh}/polyMesh.cpp
${polyMesh}/polyMeshFromShapeMesh.cpp
${polyMesh}/polyMeshIO.cpp
${polyMesh}/polyMeshInitMesh.cpp
${polyMesh}/polyMeshClear.cpp
${polyMesh}/polyMeshUpdate.cpp
${polyMeshCheck}/polyMeshCheck.cpp
${polyMeshCheck}/polyMeshTools.cpp
${primitiveMesh}/primitiveMesh.cpp
${primitiveMesh}/primitiveMeshCellCells.cpp
${primitiveMesh}/primitiveMeshCellCentresAndVols.cpp
${primitiveMesh}/primitiveMeshCellEdges.cpp
${primitiveMesh}/primitiveMeshCells.cpp
${primitiveMesh}/primitiveMeshClear.cpp
${primitiveMesh}/primitiveMeshEdgeCells.cpp
${primitiveMesh}/primitiveMeshEdgeFaces.cpp
${primitiveMesh}/primitiveMeshEdges.cpp
${primitiveMesh}/primitiveMeshFaceCentresAndAreas.cpp
${primitiveMesh}/primitiveMeshFindCell.cpp
${primitiveMesh}/primitiveMeshPointCells.cpp
${primitiveMesh}/primitiveMeshPointFaces.cpp
${primitiveMesh}/primitiveMeshPointPoints.cpp
${primitiveMesh}/primitiveMeshCellPoints.cpp
${primitiveMesh}/primitiveMeshCalcCellShapes.cpp
${primitiveMeshCheck}/primitiveMeshCheck.cpp
${primitiveMeshCheck}/primitiveMeshCheckPointNearness.cpp
${primitiveMeshCheck}/primitiveMeshCheckEdgeLength.cpp
${primitiveMeshCheck}/primitiveMeshTools.cpp
${primitivePatch}/patchZones.cpp
${primitivePatch}/walkPatch.cpp
${cellMatcher}/cellMatcher.cpp
${cellMatcher}/hexMatcher.cpp
${cellMatcher}/wedgeMatcher.cpp
${cellMatcher}/prismMatcher.cpp
${cellMatcher}/pyrMatcher.cpp
${cellMatcher}/tetWedgeMatcher.cpp
${cellMatcher}/tetMatcher.cpp
${cellMatcher}/degenerateMatcher.cpp
${mapPolyMesh}/mapPolyMesh.cpp
${mapPolyMesh}/faceMapper/faceMapper.cpp
${mapPolyMesh}/cellMapper/cellMapper.cpp
${mapPolyMesh}/mapDistribute/mapDistribute.cpp
${mapPolyMesh}/mapDistribute/mapDistributeBase.cpp
${mapPolyMesh}/mapDistribute/mapDistributePolyMesh.cpp
${mapPolyMesh}/mapDistribute/IOmapDistribute.cpp
${mapPolyMesh}/mapAddedPolyMesh.cpp
${PrimitivePatchN}/PrimitivePatchName.cpp
${pointMesh}/pointMesh.cpp
${pointMeshMapper}/pointMapper.cpp
${pointMeshMapper}/pointPatchMapper.cpp
${pointPatches}/pointPatch/pointPatch.cpp
${pointPatches}/facePointPatch/facePointPatch.cpp
${pointPatches}/facePointPatch/facePointPatchNew.cpp
${basicPointPatches}/coupled/coupledPointPatch.cpp
${basicPointPatches}/generic/genericPointPatch.cpp
${constraintPointPatches}/cyclic/cyclicPointPatch.cpp
${constraintPointPatches}/cyclicSlip/cyclicSlipPointPatch.cpp
${constraintPointPatches}/empty/emptyPointPatch.cpp
${constraintPointPatches}/nonuniformTransformCyclic/nonuniformTransformCyclicPointPatch.cpp
${constraintPointPatches}/processor/processorPointPatch.cpp
${constraintPointPatches}/processorCyclic/processorCyclicPointPatch.cpp
${constraintPointPatches}/symmetryPlane/symmetryPlanePointPatch.cpp
${constraintPointPatches}/symmetry/symmetryPointPatch.cpp
${constraintPointPatches}/wedge/wedgePointPatch.cpp
${derivedPointPatches}/coupled/coupledFacePointPatch.cpp
${derivedPointPatches}/wall/wallPointPatch.cpp
${pointBoundaryMesh}/pointBoundaryMesh.cpp
meshes/boundBox/boundBox.cpp
meshes/treeBoundBox/treeBoundBox.cpp
${meshTools}/matchPoints.cpp
fields/UniformDimensionedFields/uniformDimensionedFields.cpp
fields/cloud/cloud.cpp
${Fields}/labelField/labelField.cpp
${Fields}/scalarField/scalarField.cpp
${Fields}/vectorField/vectorField.cpp
${Fields}/vector2DField/vector2DField.cpp
${Fields}/sphericalTensorField/sphericalTensorField.cpp
${Fields}/diagTensorField/diagTensorField.cpp
${Fields}/symmTensorField/symmTensorField.cpp
${Fields}/tensorField/tensorField.cpp
${Fields}/quaternionField/quaternionField.cpp
${Fields}/triadField/triadField.cpp
${Fields}/complexFields/complexFields.cpp
${Fields}/labelField/labelIOField.cpp
${Fields}/labelField/labelFieldIOField.cpp
${Fields}/scalarField/scalarIOField.cpp
${Fields}/scalarField/scalarFieldIOField.cpp
${Fields}/vectorField/vectorIOField.cpp
${Fields}/vectorField/vectorFieldIOField.cpp
${Fields}/vector2DField/vector2DIOField.cpp
${Fields}/vector2DField/vector2DFieldIOField.cpp
${Fields}/sphericalTensorField/sphericalTensorIOField.cpp
${Fields}/sphericalTensorField/sphericalTensorFieldIOField.cpp
${Fields}/diagTensorField/diagTensorIOField.cpp
${Fields}/diagTensorField/diagTensorFieldIOField.cpp
${Fields}/symmTensorField/symmTensorIOField.cpp
${Fields}/symmTensorField/symmTensorFieldIOField.cpp
${Fields}/tensorField/tensorIOField.cpp
${Fields}/tensorField/tensorFieldIOField.cpp
${Fields}/quaternionField/quaternionIOField.cpp
${Fields}/triadField/triadIOField.cpp
${Fields}/transformField/transformField.cpp
${pointPatchFields}/pointPatchField/pointPatchFields.cpp
${basicPointPatchFields}/calculated/calculatedPointPatchFields.cpp
${basicPointPatchFields}/coupled/coupledPointPatchFields.cpp
${basicPointPatchFields}/value/valuePointPatchFields.cpp
${basicPointPatchFields}/fixedValue/fixedValuePointPatchFields.cpp
${basicPointPatchFields}/zeroGradient/zeroGradientPointPatchFields.cpp
${constraintPointPatchFields}/cyclic/cyclicPointPatchFields.cpp
${constraintPointPatchFields}/cyclicSlip/cyclicSlipPointPatchFields.cpp
${constraintPointPatchFields}/empty/emptyPointPatchFields.cpp
${constraintPointPatchFields}/nonuniformTransformCyclic/nonuniformTransformCyclicPointPatchFields.cpp
${constraintPointPatchFields}/processor/processorPointPatchFields.cpp
${constraintPointPatchFields}/processorCyclic/processorCyclicPointPatchFields.cpp
${constraintPointPatchFields}/symmetryPlane/symmetryPlanePointPatchFields.cpp
${constraintPointPatchFields}/symmetry/symmetryPointPatchFields.cpp
${constraintPointPatchFields}/wedge/wedgePointPatchFields.cpp
${derivedPointPatchFields}/slip/slipPointPatchFields.cpp
${derivedPointPatchFields}/fixedNormalSlip/fixedNormalSlipPointPatchFields.cpp
${derivedPointPatchFields}/uniformFixedValue/uniformFixedValuePointPatchFields.cpp
${derivedPointPatchFields}/timeVaryingUniformFixedValue/timeVaryingUniformFixedValuePointPatchFields.cpp
${derivedPointPatchFields}/codedFixedValue/codedFixedValuePointPatchFields.cpp
fields/GeometricFields/pointFields/pointFields.cpp
meshes/bandCompression/bandCompression.cpp
meshes/preservePatchTypes/preservePatchTypes.cpp
${interpolations}/patchToPatchInterpolation/PatchToPatchInterpolationName.cpp
${interpolations}/interpolationTable/tableReaders/tableReaders.cpp
${interpolations}/interpolationTable/tableReaders/openFoam/openFoamTableReaders.cpp
${interpolations}/interpolationTable/tableReaders/csv/csvTableReaders.cpp
${interpolationWeights}/interpolationWeights/interpolationWeights.cpp
${interpolationWeights}/linearInterpolationWeights/linearInterpolationWeights.cpp
${interpolationWeights}/splineInterpolationWeights/splineInterpolationWeights.cpp
algorithms/indexedOctree/indexedOctreeName.cpp
algorithms/indexedOctree/treeDataCell.cpp
algorithms/indexedOctree/volumeType.cpp
algorithms/dynamicIndexedOctree/dynamicIndexedOctreeName.cpp
algorithms/dynamicIndexedOctree/dynamicTreeDataPoint.cpp
graph/curve/curve.cpp
graph/graph.cpp
${writers}/rawGraph/rawGraph.cpp
${writers}/gnuplotGraph/gnuplotGraph.cpp
${writers}/xmgrGraph/xmgrGraph.cpp
${writers}/jplotGraph/jplotGraph.cpp
meshes/data/data.cpp
)

#LIB = ${FOAM_LIBBIN}/libOpenFOAM

add_library(OpenFOAM STATIC ${SOURCE_FILES})
target_link_libraries(OpenFOAM OSSpecific Pstream z)

add_custom_command(TARGET OpenFOAM
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E
                   copy $<TARGET_FILE:OpenFOAM> ${CMAKE_SOURCE_DIR}/../../lib/$<TARGET_FILE_NAME:OpenFOAM>)
