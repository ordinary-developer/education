#include "funclib.hpp"


#include <iostream>
#include <string>
#include <cassert>
namespace example_01 { // a higher order func with one param

void run() {
    // arrange - act
    auto const v = funclib::compose(
        [](int const n) { return std::to_string(n); },
        [](int const n) { return n * n; }
    )(3);

    // assert
    assert("9" == v);

    std::cout << "[ok]";
}
} // exaple_01


#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
namespace example_02 {

void run() {
    // arrange - act
    auto const n = funclib::compose(
        [](int const n) {return std::to_string(n); },
        [](int const n) { return n * n; },
        [](int const n) { return n + n; },
        [](int const n) { return std::abs(n); }
    )(-3);

    // assert
    assert("36" == n);

    std::cout << "[ok]";
}
} // a higher order func with several params


#include <functional>
#include <vector>
#include <iostream>
#include <cassert>
#include <cmath>
namespace example_03 { // composing the "mapf" and "fold" funcs

void run() {
    // arrange
    auto const vnums = std::vector<int>{ 0, 2, -3, 5, -1, 6, 8, -4, 9 };
    
    // act
    auto const s = funclib::compose(
        [](std::vector<int> const& v) { return funclib::foldl(std::plus<>(), v, 0); },
        [](std::vector<int> const& v) { return funclib::mapf([](int const i) { return i + i; }, v); },
        [](std::vector<int> const& v) { return funclib::mapf([](int const i) { return std::abs(i); }, v); }
    )(vnums);

    // assert
    assert(76 == s);

    std::cout << "[ok]";
}

} // example_03


#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>
namespace example_04 { // use overloaded * operator (as a shorthand for the "comose" func)

// #region [* operator as a "compose"]
template <typename F, typename G>
constexpr auto operator*(F&& f, G&& g) {
    return funclib::compose(std::forward<F>(f), std::forward<G>(g));
}

template <typename F, typename... R>
constexpr auto operator*(F&& f, R&&... r) {
    return operator*(std::forward<F>(f), r...);
}
// #endregion

void run() {
    // arrange - act
    auto const n = ( 
        [](int const n) { return std::to_string(n); } *
        [](int const n) { return n * n; } *
        [](int const n) { return n + n; } *
        [](int const n) { return std::abs(n); }
    ) (-3);

    auto const vnums = std::vector<int>{ 0, 2, -3, 5, -1, 6, 8, -4, 9 };
    auto const s = (
        [](std::vector<int> const& v) { return funclib::foldl(std::plus<>(), v, 0); } *
        [](std::vector<int> const& v) { return funclib::mapf([](int const i) { return i + i;}, v); } *
        [](std::vector<int> const& v) { return funclib::mapf([](int const i) { return std::abs(i); }, v); }
    )(vnums);

    // assert
    assert("36" == n);
    assert(76 == s);

    std::cout << "[ok]";
}
} // example_04



#include <iostream>
int main() {
    std::cout << "example_01 =>" << std::endl; example_01::run(); std::cout << std::endl << std::endl;
    std::cout << "example_02 =>" << std::endl; example_02::run(); std::cout << std::endl << std::endl;
    std::cout << "example_03 =>" << std::endl; example_03::run(); std::cout << std::endl << std::endl;
    std::cout << "example_04 =>" << std::endl; example_04::run(); std::cout << std::endl << std::endl;

    return 0;
}