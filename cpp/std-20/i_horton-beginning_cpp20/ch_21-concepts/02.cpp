#include <concepts>
#include <cassert>

struct EG {};

template <typename T> requires requires (T x) { { x > x } -> std::convertible_to<bool>; }
const T & larger01(const T & a, const T & b) { return a > b ? a : b; }

template <typename T> requires std::totally_ordered<T>
const T & larger02(const T & a, const T & b) { return a > b ? a : b; }

template <typename T1, typename T2> requires std::totally_ordered_with<T1, T2>
auto && larger03(const T1 & a, const T2 & b) { return a > b ? a : b; }

template <std::totally_ordered T>
const T & larger04(const T & a, const T & b) { return a > b ? a : b; }

template <typename T1, std::totally_ordered_with<T1> T2>
auto && larger05(const T1 & a, const T2 & b) { return a > b ? a : b; }

int main() {
    larger01(1, 2);
    //larger01(EG{}, EG{}); // compilation error

    larger02(1, 2);
    //larger02(EG{}, EG{}) // compilation error

    larger03(1, 2);
    //larger03(EG{}, EG{}); // compilation error

    larger04(1, 2);
    // larger04(EG{}, EG{}); // compilation error

    larger05(1, 2);
    //larger05(EG{}, EG{}); // compilation error

    assert(true);
}
