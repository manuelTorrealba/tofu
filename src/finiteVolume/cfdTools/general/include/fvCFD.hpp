#ifndef fvCFD_H
#define fvCFD_H

#include "OpenFOAM/global/argList/parRun.hpp"

#include "OpenFOAM/db/Time/Time.hpp"
#include "finiteVolume/fvMesh/fvMesh.hpp"
#include "finiteVolume/finiteVolume/fvc/fvc.hpp"
#include "finiteVolume/fvMatrices/fvMatrices.hpp"
#include "finiteVolume/finiteVolume/fvm/fvm.hpp"
#include "finiteVolume/interpolation/surfaceInterpolation/schemes/linear/linear.hpp"
#include "OpenFOAM/fields/UniformDimensionedFields/uniformDimensionedFields.hpp"
#include "finiteVolume/fields/fvPatchFields/basic/calculated/calculatedFvPatchFields.hpp"
#include "finiteVolume/fields/fvPatchFields/basic/extrapolatedCalculated/extrapolatedCalculatedFvPatchFields.hpp"
#include "finiteVolume/fields/fvPatchFields/basic/fixedValue/fixedValueFvPatchFields.hpp"
#include "finiteVolume/fields/fvPatchFields/basic/zeroGradient/zeroGradientFvPatchFields.hpp"
#include "finiteVolume/fields/fvPatchFields/derived/fixedFluxPressure/fixedFluxPressureFvPatchScalarField.hpp"
#include "finiteVolume/cfdTools/general/constrainHbyA/constrainHbyA.hpp"
#include "finiteVolume/cfdTools/general/constrainPressure/constrainPressure.hpp"
#include "finiteVolume/cfdTools/general/adjustPhi/adjustPhi.hpp"
#include "finiteVolume/cfdTools/general/findRefCell/findRefCell.hpp"
#include "finiteVolume/cfdTools/general/MRF/IOMRFZoneList.hpp"
#include "OpenFOAM/global/constants/constants.hpp"

#include "OpenFOAM/include/OSspecific.hpp"
#include "OpenFOAM/global/argList/argList.hpp"
#include "OpenFOAM/db/Time/timeSelector.hpp"

#ifndef namespaceFoam
#define namespaceFoam
    using namespace Foam;
#endif

#endif
