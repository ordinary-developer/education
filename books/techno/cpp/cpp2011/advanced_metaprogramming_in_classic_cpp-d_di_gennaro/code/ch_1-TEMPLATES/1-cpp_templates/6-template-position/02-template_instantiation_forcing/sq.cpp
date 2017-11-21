#include "sq.h"

template <typename T>
T sq(const T& x) {
    return x * x;
}

template double sq<double>(const double&);
