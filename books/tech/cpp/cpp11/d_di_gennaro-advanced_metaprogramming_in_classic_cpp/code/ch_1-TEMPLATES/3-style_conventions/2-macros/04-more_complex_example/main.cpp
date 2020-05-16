#include <cmath>

#define mXT_C(NAME, VALUE)                      \
static scalar_t NAME()                          \
{                                               \
    static const scalar_t NAME##_ = (VALUE);    \
    return NAME##_;                             \
}                                               \

template <typename scalar_t>
struct constant {
    mXT_C(Pi, acos(scalar_t(-1)));
    mXT_C(TwoPi, 2 * acos(scalar_t(-1)));
    mXT_C(PiHalf, acos(scalar_t(0)));
    mXT_C(PiQrtr, atan(scalar_t(1)));
    mXT_C(Log2, log(scalar_t(2)));
};

#undef mXT_C                        

#include <iostream>
int main() {
    double x = constant<double>::TwoPi();
    std::cout << x << std::endl;

    return 0;
}
