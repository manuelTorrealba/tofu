#include "s/tests/Field/Test-Field.hpp"

int main()
{
    Vector<double> v1(1, 2);
    Vector<double> v2(2, 3);

    std::cout << v1 + v2;

    return 0;
}
