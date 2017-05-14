#ifndef GCD_HPP_
#define GCD_HPP_

#include <cstdlib>

template<class T>
T gcd(T n, T m) {
    n = std::abs(n);
    while (m != 0) {
        T tmp{ n % m };
        n = m;
        m = tmp;
    }

    return n;
}

#endif
