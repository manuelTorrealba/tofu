#include "OpenFOAM/fields/Fields/uniformField/UniformField.hpp"
#include "OpenFOAM/primitives/Vector/vector/vector.hpp"
#include "OpenFOAM/db/IOstreams/IOstreams.hpp"

using namespace Foam;

int main()
{
    UniformField<scalar> uf1(13.1);
    UniformField<vector> uf2(vector(1, 2, 3));

    Info<< "uf1 = " << uf1[22] << "; uf2 = " << uf2[1002] << endl;

    return 0;
}
