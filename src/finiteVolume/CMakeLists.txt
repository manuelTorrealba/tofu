cmake_minimum_required (VERSION 3.0)

project (OpenFOAM)

add_definitions(-DWM_LABEL_SIZE=64 -DWM_DP -DNoRepository)

include_directories(../)
link_directories (../../lib)

set(fvBoundaryMesh fvMesh/fvBoundaryMesh)
set(fvPatches fvMesh/fvPatches)
set(basicFvPatches ${fvPatches}/basic)
set(constraintFvPatches ${fvPatches}/constraint)
set(derivedFvPatches ${fvPatches}/derived)
set(wallDist fvMesh/wallDist)
set(fvMeshMapper fvMesh/fvMeshMapper)
set(extendedStencil fvMesh/extendedStencil)
set(cellToCell ${extendedStencil}/cellToCell)
set(cellToFace ${extendedStencil}/cellToFace)
set(faceToCell ${extendedStencil}/faceToCell)
set(fvPatchFields fields/fvPatchFields)
set(basicFvPatchFields ${fvPatchFields}/basic)
set(constraintFvPatchFields ${fvPatchFields}/constraint)
set(derivedFvPatchFields ${fvPatchFields}/derived)
set(fvsPatchFields fields/fvsPatchFields)
set(basicFvsPatchFields ${fvsPatchFields}/basic)
set(constraintFvsPatchFields ${fvsPatchFields}/constraint)
set(interpolation interpolation/interpolation)
set(volPointInterpolation interpolation/volPointInterpolation)
set(surfaceInterpolation interpolation/surfaceInterpolation)
set(schemes ${surfaceInterpolation}/schemes)
set(limitedSchemes ${surfaceInterpolation}/limitedSchemes)
set(multivariateSchemes ${surfaceInterpolation}/multivariateSchemes)
set(ddtSchemes finiteVolume/ddtSchemes)
set(d2dt2Schemes finiteVolume/d2dt2Schemes)
set(divSchemes finiteVolume/divSchemes)
set(gradSchemes finiteVolume/gradSchemes)
set(limitedGradSchemes ${gradSchemes}/limitedGradSchemes)
set(snGradSchemes finiteVolume/snGradSchemes)
set(convectionSchemes finiteVolume/convectionSchemes)
set(laplacianSchemes finiteVolume/laplacianSchemes)
set(general cfdTools/general)
set(solutionControl ${general}/solutionControl)
set(solidControl ${solutionControl}/solidControl)
set(pimpleControl ${solutionControl}/pimpleControl)
set(convergenceControl ${solutionControl}/convergenceControl)
set(porosity ${general}/porosityModel)
set(MRF ${general}/MRF)
set(SRF ${general}/SRF)
set(fvOptions ${general}/fvOptions)


set(SOURCE_FILES
fvMesh/fvMeshGeometry.cpp
fvMesh/fvMesh.cpp
fvMesh/singleCellFvMesh/singleCellFvMesh.cpp
${fvBoundaryMesh}/fvBoundaryMesh.cpp
${fvPatches}/fvPatch/fvPatch.cpp
${fvPatches}/fvPatch/fvPatchNew.cpp
${basicFvPatches}/coupled/coupledFvPatch.cpp
${basicFvPatches}/generic/genericFvPatch.cpp
${constraintFvPatches}/cyclic/cyclicFvPatch.cpp
${constraintFvPatches}/cyclicAMI/cyclicAMIFvPatch.cpp
${constraintFvPatches}/cyclicACMI/cyclicACMIFvPatch.cpp
${constraintFvPatches}/cyclicSlip/cyclicSlipFvPatch.cpp
${constraintFvPatches}/empty/emptyFvPatch.cpp
${constraintFvPatches}/nonuniformTransformCyclic/nonuniformTransformCyclicFvPatch.cpp
${constraintFvPatches}/cyclicRepeatAMI/cyclicRepeatAMIFvPatch.cpp
${constraintFvPatches}/processor/processorFvPatch.cpp
${constraintFvPatches}/processorCyclic/processorCyclicFvPatch.cpp
${constraintFvPatches}/symmetryPlane/symmetryPlaneFvPatch.cpp
${constraintFvPatches}/symmetry/symmetryFvPatch.cpp
${constraintFvPatches}/wedge/wedgeFvPatch.cpp
${derivedFvPatches}/wall/wallFvPatch.cpp
${derivedFvPatches}/mapped/mappedFvPatch.cpp
${derivedFvPatches}/mapped/mappedWallFvPatch.cpp
${derivedFvPatches}/regionCoupled/regionCoupledBaseFvPatch.cpp
${derivedFvPatches}/regionCoupled/regionCoupledFvPatch.cpp
${derivedFvPatches}/regionCoupled/regionCoupledWallFvPatch.cpp
${wallDist}/wallPointYPlus/wallPointYPlus.cpp
${wallDist}/nearWallDist/nearWallDistNoSearch.cpp
${wallDist}/nearWallDist/nearWallDist.cpp
${wallDist}/wallDist/wallDist.cpp
${wallDist}/patchDistMethods/patchDistMethod/patchDistMethod.cpp
${wallDist}/patchDistMethods/meshWave/meshWavePatchDistMethod.cpp
${wallDist}/patchDistMethods/Poisson/PoissonPatchDistMethod.cpp
${wallDist}/patchDistMethods/advectionDiffusion/advectionDiffusionPatchDistMethod.cpp
${fvMeshMapper}/fvPatchMapper.cpp
${fvMeshMapper}/fvSurfaceMapper.cpp
${cellToCell}/extendedCellToCellStencil.cpp
${cellToCell}/extendedCentredCellToCellStencil.cpp
${cellToCell}/globalIndexStencils/cellToCellStencil.cpp
${cellToCell}/globalIndexStencils/CFCCellToCellStencil.cpp
${cellToCell}/globalIndexStencils/CPCCellToCellStencil.cpp
${cellToCell}/globalIndexStencils/CECCellToCellStencil.cpp
${cellToCell}/MeshObjects/centredCECCellToCellStencilObject.cpp
${cellToCell}/MeshObjects/centredCFCCellToCellStencilObject.cpp
${cellToCell}/MeshObjects/centredCPCCellToCellStencilObject.cpp
${cellToFace}/globalIndexStencils/cellToFaceStencil.cpp
${cellToFace}/globalIndexStencils/CFCCellToFaceStencil.cpp
${cellToFace}/globalIndexStencils/CECCellToFaceStencil.cpp
${cellToFace}/globalIndexStencils/CPCCellToFaceStencil.cpp
${cellToFace}/globalIndexStencils/FECCellToFaceStencil.cpp
${cellToFace}/extendedCellToFaceStencil.cpp
${cellToFace}/extendedCentredCellToFaceStencil.cpp
${cellToFace}/extendedUpwindCellToFaceStencil.cpp
${cellToFace}/MeshObjects/centredCECCellToFaceStencilObject.cpp
${cellToFace}/MeshObjects/centredCFCCellToFaceStencilObject.cpp
${cellToFace}/MeshObjects/centredCPCCellToFaceStencilObject.cpp
${cellToFace}/MeshObjects/centredFECCellToFaceStencilObject.cpp
${cellToFace}/MeshObjects/upwindCECCellToFaceStencilObject.cpp
${cellToFace}/MeshObjects/upwindCFCCellToFaceStencilObject.cpp
${cellToFace}/MeshObjects/upwindCPCCellToFaceStencilObject.cpp
${cellToFace}/MeshObjects/upwindFECCellToFaceStencilObject.cpp
${cellToFace}/MeshObjects/pureUpwindCFCCellToFaceStencilObject.cpp
${faceToCell}/globalIndexStencils/faceToCellStencil.cpp
${faceToCell}/globalIndexStencils/CFCFaceToCellStencil.cpp
${faceToCell}/extendedFaceToCellStencil.cpp
${faceToCell}/extendedCentredFaceToCellStencil.cpp
${faceToCell}/MeshObjects/centredCFCFaceToCellStencilObject.cpp
functionObjects/fvMeshFunctionObject/fvMeshFunctionObject.cpp
functionObjects/volRegion/volRegion.cpp
${fvPatchFields}/fvPatchField/fvPatchFields.cpp
${basicFvPatchFields}/basicSymmetry/basicSymmetryFvPatchScalarField.cpp
${basicFvPatchFields}/calculated/calculatedFvPatchFields.cpp
${basicFvPatchFields}/extrapolatedCalculated/extrapolatedCalculatedFvPatchFields.cpp
${basicFvPatchFields}/coupled/coupledFvPatchFields.cpp
${basicFvPatchFields}/directionMixed/directionMixedFvPatchFields.cpp
${basicFvPatchFields}/fixedGradient/fixedGradientFvPatchFields.cpp
${basicFvPatchFields}/fixedValue/fixedValueFvPatchFields.cpp
${basicFvPatchFields}/mixed/mixedFvPatchFields.cpp
${basicFvPatchFields}/sliced/slicedFvPatchFields.cpp
${basicFvPatchFields}/transform/transformFvPatchFields.cpp
${basicFvPatchFields}/transform/transformFvPatchScalarField.cpp
${basicFvPatchFields}/zeroGradient/zeroGradientFvPatchFields.cpp
${constraintFvPatchFields}/cyclic/cyclicFvPatchFields.cpp
${constraintFvPatchFields}/cyclicAMI/cyclicAMIFvPatchFields.cpp
${constraintFvPatchFields}/cyclicACMI/cyclicACMIFvPatchFields.cpp
${constraintFvPatchFields}/cyclicSlip/cyclicSlipFvPatchFields.cpp
${constraintFvPatchFields}/empty/emptyFvPatchFields.cpp
${constraintFvPatchFields}/jumpCyclic/jumpCyclicFvPatchFields.cpp
${constraintFvPatchFields}/jumpCyclicAMI/jumpCyclicAMIFvPatchFields.cpp
${constraintFvPatchFields}/nonuniformTransformCyclic/nonuniformTransformCyclicFvPatchFields.cpp
${constraintFvPatchFields}/cyclicRepeatAMI/cyclicRepeatAMIFvPatchFields.cpp
${constraintFvPatchFields}/processor/processorFvPatchFields.cpp
${constraintFvPatchFields}/processor/processorFvPatchScalarField.cpp
${constraintFvPatchFields}/processorCyclic/processorCyclicFvPatchFields.cpp
${constraintFvPatchFields}/symmetryPlane/symmetryPlaneFvPatchFields.cpp
${constraintFvPatchFields}/symmetryPlane/symmetryPlaneFvPatchScalarField.cpp
${constraintFvPatchFields}/symmetry/symmetryFvPatchFields.cpp
${constraintFvPatchFields}/wedge/wedgeFvPatchFields.cpp
${constraintFvPatchFields}/wedge/wedgeFvPatchScalarField.cpp
${derivedFvPatchFields}/activeBaffleVelocity/activeBaffleVelocityFvPatchVectorField.cpp
${derivedFvPatchFields}/activePressureForceBaffleVelocity/activePressureForceBaffleVelocityFvPatchVectorField.cpp
${derivedFvPatchFields}/advective/advectiveFvPatchFields.cpp
${derivedFvPatchFields}/codedFixedValue/codedFixedValueFvPatchFields.cpp
${derivedFvPatchFields}/codedMixed/codedMixedFvPatchFields.cpp
${derivedFvPatchFields}/cylindricalInletVelocity/cylindricalInletVelocityFvPatchVectorField.cpp
${derivedFvPatchFields}/externalCoupledMixed/externalCoupledMixedFvPatchFields.cpp
${derivedFvPatchFields}/fan/fanFvPatchFields.cpp
${derivedFvPatchFields}/fanPressure/fanPressureFvPatchScalarField.cpp
${derivedFvPatchFields}/fixedFluxPressure/fixedFluxPressureFvPatchScalarField.cpp
${derivedFvPatchFields}/fixedFluxExtrapolatedPressure/fixedFluxExtrapolatedPressureFvPatchScalarField.cpp
${derivedFvPatchFields}/fixedInternalValueFvPatchField/fixedInternalValueFvPatchFields.cpp
${derivedFvPatchFields}/fixedJump/fixedJumpFvPatchFields.cpp
${derivedFvPatchFields}/fixedJumpAMI/fixedJumpAMIFvPatchFields.cpp
${derivedFvPatchFields}/fixedMean/fixedMeanFvPatchFields.cpp
${derivedFvPatchFields}/fixedNormalSlip/fixedNormalSlipFvPatchFields.cpp
${derivedFvPatchFields}/fixedPressureCompressibleDensity/fixedPressureCompressibleDensityFvPatchScalarField.cpp
${derivedFvPatchFields}/flowRateInletVelocity/flowRateInletVelocityFvPatchVectorField.cpp
${derivedFvPatchFields}/flowRateOutletVelocity/flowRateOutletVelocityFvPatchVectorField.cpp
${derivedFvPatchFields}/fluxCorrectedVelocity/fluxCorrectedVelocityFvPatchVectorField.cpp
${derivedFvPatchFields}/freestream/freestreamFvPatchFields.cpp
${derivedFvPatchFields}/freestreamVelocity/freestreamVelocityFvPatchVectorField.cpp
${derivedFvPatchFields}/freestreamPressure/freestreamPressureFvPatchScalarField.cpp
${derivedFvPatchFields}/inletOutlet/inletOutletFvPatchFields.cpp
${derivedFvPatchFields}/inletOutletTotalTemperature/inletOutletTotalTemperatureFvPatchScalarField.cpp
${derivedFvPatchFields}/mappedField/mappedFieldFvPatchFields.cpp
${derivedFvPatchFields}/mappedFixedInternalValue/mappedFixedInternalValueFvPatchFields.cpp
${derivedFvPatchFields}/mappedFixedPushedInternalValue/mappedFixedPushedInternalValueFvPatchFields.cpp
${derivedFvPatchFields}/mappedFixedValue/mappedFixedValueFvPatchFields.cpp
${derivedFvPatchFields}/mappedFlowRate/mappedFlowRateFvPatchVectorField.cpp
${derivedFvPatchFields}/mappedVelocityFluxFixedValue/mappedVelocityFluxFixedValueFvPatchField.cpp
${derivedFvPatchFields}/matchedFlowRateOutletVelocity/matchedFlowRateOutletVelocityFvPatchVectorField.cpp
${derivedFvPatchFields}/noSlip/noSlipFvPatchVectorField.cpp
${derivedFvPatchFields}/movingWallVelocity/movingWallVelocityFvPatchVectorField.cpp
${derivedFvPatchFields}/outletInlet/outletInletFvPatchFields.cpp
${derivedFvPatchFields}/outletMappedUniformInlet/outletMappedUniformInletFvPatchFields.cpp
${derivedFvPatchFields}/fixedMeanOutletInlet/fixedMeanOutletInletFvPatchFields.cpp
${derivedFvPatchFields}/partialSlip/partialSlipFvPatchFields.cpp
${derivedFvPatchFields}/phaseHydrostaticPressure/phaseHydrostaticPressureFvPatchScalarField.cpp
${derivedFvPatchFields}/pressureDirectedInletOutletVelocity/pressureDirectedInletOutletVelocityFvPatchVectorField.cpp
${derivedFvPatchFields}/pressureDirectedInletVelocity/pressureDirectedInletVelocityFvPatchVectorField.cpp
${derivedFvPatchFields}/pressureInletOutletParSlipVelocity/pressureInletOutletParSlipVelocityFvPatchVectorField.cpp
${derivedFvPatchFields}/pressureInletOutletVelocity/pressureInletOutletVelocityFvPatchVectorField.cpp
${derivedFvPatchFields}/pressureInletUniformVelocity/pressureInletUniformVelocityFvPatchVectorField.cpp
${derivedFvPatchFields}/pressureInletVelocity/pressureInletVelocityFvPatchVectorField.cpp
${derivedFvPatchFields}/pressureNormalInletOutletVelocity/pressureNormalInletOutletVelocityFvPatchVectorField.cpp
${derivedFvPatchFields}/fixedNormalInletOutletVelocity/fixedNormalInletOutletVelocityFvPatchVectorField.cpp
${derivedFvPatchFields}/rotatingPressureInletOutletVelocity/rotatingPressureInletOutletVelocityFvPatchVectorField.cpp
${derivedFvPatchFields}/rotatingTotalPressure/rotatingTotalPressureFvPatchScalarField.cpp
${derivedFvPatchFields}/rotatingWallVelocity/rotatingWallVelocityFvPatchVectorField.cpp
${derivedFvPatchFields}/slip/slipFvPatchFields.cpp
${derivedFvPatchFields}/supersonicFreestream/supersonicFreestreamFvPatchVectorField.cpp
${derivedFvPatchFields}/surfaceNormalFixedValue/surfaceNormalFixedValueFvPatchVectorField.cpp
${derivedFvPatchFields}/swirlFlowRateInletVelocity/swirlFlowRateInletVelocityFvPatchVectorField.cpp
${derivedFvPatchFields}/swirlInletVelocity/swirlInletVelocityFvPatchVectorField.cpp
${derivedFvPatchFields}/syringePressure/syringePressureFvPatchScalarField.cpp
${derivedFvPatchFields}/timeVaryingMappedFixedValue/timeVaryingMappedFixedValueFvPatchFields.cpp
${derivedFvPatchFields}/totalPressure/totalPressureFvPatchScalarField.cpp
${derivedFvPatchFields}/totalTemperature/totalTemperatureFvPatchScalarField.cpp
${derivedFvPatchFields}/translatingWallVelocity/translatingWallVelocityFvPatchVectorField.cpp
${derivedFvPatchFields}/turbulentInlet/turbulentInletFvPatchFields.cpp
${derivedFvPatchFields}/turbulentIntensityKineticEnergyInlet/turbulentIntensityKineticEnergyInletFvPatchScalarField.cpp
${derivedFvPatchFields}/uniformDensityHydrostaticPressure/uniformDensityHydrostaticPressureFvPatchScalarField.cpp
${derivedFvPatchFields}/uniformFixedGradient/uniformFixedGradientFvPatchFields.cpp
${derivedFvPatchFields}/uniformFixedValue/uniformFixedValueFvPatchFields.cpp
${derivedFvPatchFields}/uniformInletOutlet/uniformInletOutletFvPatchFields.cpp
${derivedFvPatchFields}/uniformJump/uniformJumpFvPatchFields.cpp
${derivedFvPatchFields}/uniformJumpAMI/uniformJumpAMIFvPatchFields.cpp
${derivedFvPatchFields}/uniformTotalPressure/uniformTotalPressureFvPatchScalarField.cpp
${derivedFvPatchFields}/variableHeightFlowRate/variableHeightFlowRateFvPatchField.cpp
${derivedFvPatchFields}/variableHeightFlowRateInletVelocity/variableHeightFlowRateInletVelocityFvPatchVectorField.cpp
${derivedFvPatchFields}/outletPhaseMeanVelocity/outletPhaseMeanVelocityFvPatchVectorField.cpp
${derivedFvPatchFields}/waveTransmissive/waveTransmissiveFvPatchFields.cpp
${derivedFvPatchFields}/waveSurfacePressure/waveSurfacePressureFvPatchScalarField.cpp
${derivedFvPatchFields}/interstitialInletVelocity/interstitialInletVelocityFvPatchVectorField.cpp
${derivedFvPatchFields}/fixedProfile/fixedProfileFvPatchFields.cpp
${derivedFvPatchFields}/plenumPressure/plenumPressureFvPatchScalarField.cpp
${derivedFvPatchFields}/interfaceCompression/interfaceCompressionFvPatchScalarField.cpp
${derivedFvPatchFields}/pressure/pressureFvPatchScalarField.cpp
${derivedFvPatchFields}/PrghPressure/prghPressureFvPatchScalarFields.cpp
${derivedFvPatchFields}/prghTotalHydrostaticPressure/prghTotalHydrostaticPressureFvPatchScalarField.cpp
${fvsPatchFields}/fvsPatchField/fvsPatchFields.cpp
${basicFvsPatchFields}/calculated/calculatedFvsPatchFields.cpp
${basicFvsPatchFields}/coupled/coupledFvsPatchFields.cpp
${basicFvsPatchFields}/fixedValue/fixedValueFvsPatchFields.cpp
${basicFvsPatchFields}/sliced/slicedFvsPatchFields.cpp
${constraintFvsPatchFields}/cyclic/cyclicFvsPatchFields.cpp
${constraintFvsPatchFields}/cyclicAMI/cyclicAMIFvsPatchFields.cpp
${constraintFvsPatchFields}/cyclicACMI/cyclicACMIFvsPatchFields.cpp
${constraintFvsPatchFields}/cyclicSlip/cyclicSlipFvsPatchFields.cpp
${constraintFvsPatchFields}/empty/emptyFvsPatchFields.cpp
${constraintFvsPatchFields}/nonuniformTransformCyclic/nonuniformTransformCyclicFvsPatchFields.cpp
${constraintFvsPatchFields}/cyclicRepeatAMI/cyclicRepeatAMIFvsPatchFields.cpp
${constraintFvsPatchFields}/processor/processorFvsPatchFields.cpp
${constraintFvsPatchFields}/processorCyclic/processorCyclicFvsPatchFields.cpp
${constraintFvsPatchFields}/symmetryPlane/symmetryPlaneFvsPatchFields.cpp
${constraintFvsPatchFields}/symmetry/symmetryFvsPatchFields.cpp
${constraintFvsPatchFields}/wedge/wedgeFvsPatchFields.cpp
fields/volFields/volFields.cpp
fields/surfaceFields/surfaceFields.cpp
fvMatrices/fvMatrices.cpp
fvMatrices/fvScalarMatrix/fvScalarMatrix.cpp
fvMatrices/solvers/MULES/MULES.cpp
fvMatrices/solvers/GAMGSymSolver/GAMGAgglomerations/faceAreaPairGAMGAgglomeration/faceAreaPairGAMGAgglomeration.cpp
${interpolation}/interpolation/interpolations.cpp
${interpolation}/interpolationCell/makeInterpolationCell.cpp
${interpolation}/interpolationCellPatchConstrained/makeInterpolationCellPatchConstrained.cpp
${interpolation}/interpolationCellPoint/cellPointWeight/cellPointWeight.cpp
${interpolation}/interpolationCellPoint/makeInterpolationCellPoint.cpp
${interpolation}/interpolationCellPointFace/makeInterpolationCellPointFace.cpp
${interpolation}/interpolationPointMVC/pointMVCWeight.cpp
${interpolation}/interpolationPointMVC/makeInterpolationPointMVC.cpp
${volPointInterpolation}/volPointInterpolation.cpp
${volPointInterpolation}/pointConstraints.cpp
${surfaceInterpolation}/surfaceInterpolation/surfaceInterpolation.cpp
${surfaceInterpolation}/surfaceInterpolationScheme/surfaceInterpolationSchemes.cpp
${surfaceInterpolation}/blendedSchemeBase/blendedSchemeBaseName.cpp
${schemes}/linear/linear.cpp
${schemes}/pointLinear/pointLinear.cpp
${schemes}/midPoint/midPoint.cpp
${schemes}/downwind/downwind.cpp
${schemes}/weighted/weighted.cpp
${schemes}/cubic/cubic.cpp
${schemes}/skewCorrected/skewCorrectionVectors.cpp
${schemes}/skewCorrected/skewCorrected.cpp
${schemes}/outletStabilised/outletStabilised.cpp
${schemes}/reverseLinear/reverseLinear.cpp
${schemes}/clippedLinear/clippedLinear.cpp
${schemes}/harmonic/harmonic.cpp
${schemes}/fixedBlended/fixedBlended.cpp
${schemes}/localBlended/localBlended.cpp
${schemes}/limiterBlended/limiterBlended.cpp
${schemes}/CoBlended/CoBlended.cpp
${schemes}/cellCoBlended/cellCoBlended.cpp
${schemes}/localMax/localMax.cpp
${schemes}/localMin/localMin.cpp
${schemes}/linearFit/linearFit.cpp
${schemes}/biLinearFit/biLinearFit.cpp
${schemes}/quadraticLinearFit/quadraticLinearFit.cpp
${schemes}/quadraticFit/quadraticFit.cpp
${schemes}/quadraticLinearUpwindFit/quadraticLinearUpwindFit.cpp
${schemes}/quadraticUpwindFit/quadraticUpwindFit.cpp
${schemes}/cubicUpwindFit/cubicUpwindFit.cpp
#${schemes}/quadraticLinearPureUpwindFit/quadraticLinearPureUpwindFit.cpp
${schemes}/linearPureUpwindFit/linearPureUpwindFit.cpp
${schemes}/linearUpwind/linearUpwind.cpp
${schemes}/linearUpwind/linearUpwindV.cpp
${schemes}/LUST/LUST.cpp
${limitedSchemes}/limitedSurfaceInterpolationScheme/limitedSurfaceInterpolationSchemes.cpp
${limitedSchemes}/upwind/upwind.cpp
${limitedSchemes}/blended/blended.cpp
${limitedSchemes}/Gamma/Gamma.cpp
${limitedSchemes}/SFCD/SFCD.cpp
${limitedSchemes}/Minmod/Minmod.cpp
${limitedSchemes}/vanLeer/vanLeer.cpp
${limitedSchemes}/vanAlbada/vanAlbada.cpp
${limitedSchemes}/OSPRE/OSPRE.cpp
${limitedSchemes}/limitedLinear/limitedLinear.cpp
${limitedSchemes}/limitedCubic/limitedCubic.cpp
${limitedSchemes}/SuperBee/SuperBee.cpp
${limitedSchemes}/QUICK/QUICK.cpp
${limitedSchemes}/MUSCL/MUSCL.cpp
${limitedSchemes}/UMIST/UMIST.cpp
${limitedSchemes}/Phi/Phi.cpp
${limitedSchemes}/filteredLinear/filteredLinear.cpp
${limitedSchemes}/filteredLinear2/filteredLinear2.cpp
${limitedSchemes}/filteredLinear3/filteredLinear3.cpp
${limitedSchemes}/limitWith/limitWith.cpp
${multivariateSchemes}/multivariateSurfaceInterpolationScheme/multivariateSurfaceInterpolationSchemes.cpp
${multivariateSchemes}/multivariateSelectionScheme/multivariateSelectionSchemes.cpp
${multivariateSchemes}/multivariateIndependentScheme/multivariateIndependentSchemes.cpp
${multivariateSchemes}/upwind/multivariateUpwind.cpp
${multivariateSchemes}/Gamma/multivariateGamma.cpp
${multivariateSchemes}/vanLeer/multivariateVanLeer.cpp
${multivariateSchemes}/Minmod/multivariateMinmod.cpp
${multivariateSchemes}/SuperBee/multivariateSuperBee.cpp
${multivariateSchemes}/MUSCL/multivariateMUSCL.cpp
${multivariateSchemes}/limitedLinear/multivariateLimitedLinear.cpp
${multivariateSchemes}/limitedCubic/multivariateLimitedCubic.cpp
finiteVolume/fv/fv.cpp
finiteVolume/fvSchemes/fvSchemes.cpp
${ddtSchemes}/ddtScheme/ddtSchemes.cpp
${ddtSchemes}/steadyStateDdtScheme/steadyStateDdtSchemes.cpp
${ddtSchemes}/EulerDdtScheme/EulerDdtSchemes.cpp
${ddtSchemes}/CoEulerDdtScheme/CoEulerDdtSchemes.cpp
${ddtSchemes}/SLTSDdtScheme/SLTSDdtSchemes.cpp
${ddtSchemes}/localEulerDdtScheme/localEulerDdt.cpp
${ddtSchemes}/localEulerDdtScheme/localEulerDdtSchemes.cpp
${ddtSchemes}/backwardDdtScheme/backwardDdtSchemes.cpp
${ddtSchemes}/CrankNicolsonDdtScheme/CrankNicolsonDdtSchemes.cpp
${ddtSchemes}/boundedDdtScheme/boundedDdtSchemes.cpp
${d2dt2Schemes}/d2dt2Scheme/d2dt2Schemes.cpp
${d2dt2Schemes}/steadyStateD2dt2Scheme/steadyStateD2dt2Schemes.cpp
${d2dt2Schemes}/EulerD2dt2Scheme/EulerD2dt2Schemes.cpp
${divSchemes}/divScheme/divSchemes.cpp
${divSchemes}/gaussDivScheme/gaussDivSchemes.cpp
${gradSchemes}/gradScheme/gradSchemes.cpp
${gradSchemes}/gaussGrad/gaussGrads.cpp
${gradSchemes}/leastSquaresGrad/leastSquaresVectors.cpp
${gradSchemes}/leastSquaresGrad/leastSquaresGrads.cpp
${gradSchemes}/LeastSquaresGrad/LeastSquaresGrads.cpp
${gradSchemes}/fourthGrad/fourthGrads.cpp
${limitedGradSchemes}/faceLimitedGrad/faceLimitedGrads.cpp
${limitedGradSchemes}/cellLimitedGrad/cellLimitedGrads.cpp
${limitedGradSchemes}/faceMDLimitedGrad/faceMDLimitedGrads.cpp
${limitedGradSchemes}/cellMDLimitedGrad/cellMDLimitedGrads.cpp
${snGradSchemes}/snGradScheme/snGradSchemes.cpp
${snGradSchemes}/correctedSnGrad/correctedSnGrads.cpp
${snGradSchemes}/faceCorrectedSnGrad/faceCorrectedSnGrads.cpp
${snGradSchemes}/limitedSnGrad/limitedSnGrads.cpp
${snGradSchemes}/uncorrectedSnGrad/uncorrectedSnGrads.cpp
${snGradSchemes}/orthogonalSnGrad/orthogonalSnGrads.cpp
${snGradSchemes}/quadraticFitSnGrad/quadraticFitSnGrads.cpp
${snGradSchemes}/linearFitSnGrad/linearFitSnGrads.cpp
${convectionSchemes}/convectionScheme/convectionSchemes.cpp
${convectionSchemes}/gaussConvectionScheme/gaussConvectionSchemes.cpp
${convectionSchemes}/multivariateGaussConvectionScheme/multivariateGaussConvectionSchemes.cpp
${convectionSchemes}/boundedConvectionScheme/boundedConvectionSchemes.cpp
${laplacianSchemes}/laplacianScheme/laplacianSchemes.cpp
${laplacianSchemes}/gaussLaplacianScheme/gaussLaplacianSchemes.cpp
finiteVolume/fvc/fvcFlux.cpp
finiteVolume/fvc/fvcMeshPhi.cpp
finiteVolume/fvc/fvcSmooth/fvcSmooth.cpp
finiteVolume/fvc/fvcReconstructMag.cpp
${general}/findRefCell/findRefCell.cpp
${general}/constrainHbyA/constrainHbyA.cpp
${general}/adjustPhi/adjustPhi.cpp
${general}/bound/bound.cpp
${general}/CorrectPhi/correctUphiBCs.cpp
${general}/pressureControl/pressureControl.cpp
${general}/levelSet/levelSet.cpp
${solutionControl}/solutionControl/solutionControl/solutionControl.cpp
${solutionControl}/solutionControl/singleRegionSolutionControl/singleRegionSolutionControl.cpp
${solutionControl}/solutionControl/multiRegionSolutionControl/multiRegionSolutionControl.cpp
${solutionControl}/solutionControl/nonOrthogonalSolutionControl/nonOrthogonalSolutionControl.cpp
${solutionControl}/solutionControl/fluidSolutionControl/fluidSolutionControl.cpp
${solutionControl}/simpleControl/simpleControl.cpp
${solutionControl}/pisoControl/pisoControl.cpp
${solidControl}/solidNoLoopControl/solidNoLoopControl.cpp
${pimpleControl}/pimpleControl/pimpleControl.cpp
${pimpleControl}/pimpleNoLoopControl/pimpleNoLoopControl.cpp
${pimpleControl}/pimpleLoop/pimpleLoop.cpp
${pimpleControl}/pimpleMultiRegionControl/pimpleMultiRegionControl.cpp
${convergenceControl}/convergenceControl/convergenceControl.cpp
${convergenceControl}/singleRegionConvergenceControl/singleRegionConvergenceControl.cpp
${convergenceControl}/correctorConvergenceControl/correctorConvergenceControl.cpp
${convergenceControl}/singleRegionCorrectorConvergenceControl/singleRegionCorrectorConvergenceControl.cpp
${porosity}/porosityModel/porosityModel.cpp
${porosity}/porosityModel/porosityModelNew.cpp
${porosity}/porosityModel/porosityModelList.cpp
${porosity}/porosityModel/IOporosityModelList.cpp
${porosity}/DarcyForchheimer/DarcyForchheimer.cpp
${porosity}/fixedCoeff/fixedCoeff.cpp
${porosity}/powerLaw/powerLaw.cpp
${porosity}/solidification/solidification.cpp
${MRF}/MRFZone.cpp
${MRF}/MRFZoneList.cpp
${MRF}/IOMRFZoneList.cpp
${SRF}/SRFModel/SRFModel/SRFModel.cpp
${SRF}/SRFModel/SRFModel/SRFModelNew.cpp
${SRF}/SRFModel/rpm/rpm.cpp
${SRF}/derivedFvPatchFields/SRFVelocityFvPatchVectorField/SRFVelocityFvPatchVectorField.cpp
${SRF}/derivedFvPatchFields/SRFWallVelocityFvPatchVectorField/SRFWallVelocityFvPatchVectorField.cpp
${SRF}/derivedFvPatchFields/SRFFreestreamVelocityFvPatchVectorField/SRFFreestreamVelocityFvPatchVectorField.cpp
${fvOptions}/fvOption.cpp
${fvOptions}/fvOptionIO.cpp
${fvOptions}/fvOptionList.cpp
${fvOptions}/fvOptions.cpp
)

add_library(finiteVolume STATIC ${SOURCE_FILES})
target_link_libraries(finiteVolume OpenFOAM triSurface meshTools)

add_custom_command(TARGET finiteVolume
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E
                   copy $<TARGET_FILE:finiteVolume> ${CMAKE_SOURCE_DIR}/../../lib/$<TARGET_FILE_NAME:finiteVolume>)
