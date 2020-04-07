#ifndef calcEk_H
#define calcEk_H

#include "finiteVolume/fields/volFields/volFieldsFwd.hpp"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

class graph;
class Kmesh;

graph calcEk
(
    const volVectorField& U,
    const Kmesh& K
);


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

#endif
