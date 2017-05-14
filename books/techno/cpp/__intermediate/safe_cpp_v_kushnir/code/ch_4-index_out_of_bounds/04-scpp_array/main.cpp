#include "scpp_array.hpp"

#include <algorithm>
#include <iostream>


int main() {
    scpp::array<int, 5> a(0);
    a[0] = 7;
    a[1] = 2;
    a[2] = 3;
    a[3] = 9;
    a[4] = 0;

    std::cout << "Array before sort: " << a << std::endl;

    std::sort(a.begin(), a.end());
    std::cout << "Array after sort: " << a << std::endl;

    return 0;
}
