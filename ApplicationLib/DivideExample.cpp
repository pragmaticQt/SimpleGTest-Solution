#include "DivideExample.h"

#include <stdexcept>

double DivideExample::divide(double dividend, double divisor)
{
    if(divisor == 0.0)
        throw std::invalid_argument("divisor cannot be zero");

    return dividend / divisor;
}
