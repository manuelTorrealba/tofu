
//#include "OpenFOAM/db/IOstreams/StringStreams/IStringStream.hpp"
#include "OpenFOAM/global/foamVersion.hpp"
//#include "OpenFOAM/interpolations/interpolateSplineXY/interpolateSplineXY.hpp"

#include <stdio.h>

int main(int narg, char** arg) {

    //spline XY interpolation test
    // Foam::IStringStream xNew_ss("1 2 3 4 5 6");
    // Foam::IStringStream xOld_ss("1 2 3 4 5 6");
    // Foam::IStringStream yOld_ss("1.5 2.2 3.5 4.5 5 6.5");

    //std::cout << xNew_ss.str() << std::endl;
    //std::cout << xOld_ss.str() << std::endl;
    //std::cout << yOld_ss.str() << std::endl;
    
    
    
    // Foam::scalarField xNew(xNew_ss);
    // Foam::scalarField xOld(xOld_ss);
    // Foam::scalarField yOld(yOld_ss);
    // Foam::Field<Foam::scalar> yNew = Foam::interpolateSplineXY(xNew, xOld, yOld);
    
    //std::cout << yNew.str() << std::endl;
    printf(Foam::FOAMversion);
	return 1;

}
