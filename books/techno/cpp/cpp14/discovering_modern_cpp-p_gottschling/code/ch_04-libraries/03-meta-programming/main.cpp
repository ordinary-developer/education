#include <iostream>
#include <limits>
namespace example01 {

template <typename T>
inline void test(T const& x) {
    std::cout << "x = " << x << " (";
    int oldPrecision = 
        std::cout.precision(std::numeric_limits<T>::digits10 + 1);
    std::cout << x << ")" << std::endl;
    std::cout.precision(oldPrecision);
}

void run() {
    test(1.f / 3.f);
    test(1. / 3.0);
    test(1. / 3.0l);
}
}

#include <iostream>
#include <limits>
#include <array>
namespace example02 {

template <typename Container>
typename Container::value_type
inline minimum(Container const& container) {
    using value_type = typename Container::value_type;

    value_type min_value = std::numeric_limits<value_type>::max();
    for (value_type const& x : container)
        if (x < min_value)
            min_value = x;
    return min_value;
}

void run() {
    std::array<int, 5> integers{ 1, 2, 3, 4, 5 };
    std::cout << minimum(integers) << std::endl;
}

}

#include <iostream>
#include <limits>
#include <cmath>
namespace example03 {

template <typename T>
T square_root(T const& x) {
    T const my_epsilon = T{2} * x * std::numeric_limits<T>::epsilon();
    T r = x;

    while (std::abs((r * r) - x) > my_epsilon)
        r = (r + x / r) / T{2};

    return r;
}

void run() {
    double value{5};
    std::cout << square_root(value) << std::endl;
}

}

#include <iostream>
#include <type_traits>
#include <initializer_list>
#include <cstring>
#include <algorithm>
namespace example04 {

struct simple_point {
#ifdef __cplusplus
    simple_point(double x, double y) : x{x}, y{y} {}
    simple_point() = default;
    simple_point(std::initializer_list<double> initializer_list) {
        auto it = std::begin(initializer_list);
        x = *it;
        y = *std::next(it);
    }
#endif
    double x, y;
};

void run() {
    std::cout << "simple_point is pod = " << std::boolalpha
              << std::is_pod<simple_point>::value << std::endl;

    simple_point p1{ 3.0, 7.1 }, p2{}, p3{};

    static_assert(std::is_trivially_copyable<simple_point>::value,
                  "simple_point is not as simple as you think "
                  "and cannot be memcpyd!");
    std::memcpy(&p2, &p1, sizeof(p1));
    std::cout << "x = " << p2.x << ", y = " << p2.y << std::endl;

    std::copy(&p1, &p1 + 1, &p3);
    std::cout << "x = " << p3.x << ", y = " << p3.y << std::endl;
}

}

int main() {
    example01::run();
    example02::run();
    example03::run();
    example04::run();

    return 0;
}
