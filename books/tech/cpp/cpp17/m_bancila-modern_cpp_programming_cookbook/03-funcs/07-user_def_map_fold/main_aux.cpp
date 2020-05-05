#include "funclib.hpp"


#include <iostream>
#include <functional>
#include <vector>
#include <cassert>
#include <cmath>
namespace example_01 { // function combination using

void run() {
    // arrange
    auto const vnums = std::vector<int>{
        0, 2, -3, 5, -1, 6, 8, -4, 9 };

    // act
    auto const s = funclib::foldl(
        std::plus<>(),
        funclib::mapf(
            [](int const i) { return i * i; },
            funclib::mapf(
                [](int const i) { return std::abs(i); },
                vnums
            )),
        0);

    // assert
    assert(236 == s);
 
    std::cout << "[ok]";
}    

} // example_01


#include <iostream>
#include <memory>
#include <string>
#include <cassert>
#include <cmath>
namespace example_02 { // implement the "fold" func via variadic templates

template <typename F, typename T1, typename T2>
constexpr auto foldl(F&& f, T1 const& arg1, T2 const& arg2) {
    return f(arg1, arg2);
}

template <typename F, typename T, typename... Ts>
constexpr auto foldl(F&& f, T const& head, const Ts... rest) {
    return f(head, foldl(std::forward<F>(f), rest...));
}

void run() {
    using namespace std::string_literals;
 
    // arrange - act
    auto const s1 = foldl(std::plus<>(), 1, 2, 3, 4, 5);
    auto const s2 = foldl(std::plus<>(), "hello"s, ' ', "world"s, '!');
    // auto const s3 = foldl(std::plus<>(), 1); // compilation error

    // assert
    assert(15 == s1);
    assert("hello world!"s == s2);

    std::cout << "[ok]";
}

} // example_02


#include <iostream>
int main() {
    std::cout << "example_01 => " << std::endl; example_01::run(); std::cout << std::endl << std::endl;
    std::cout << "example_02 => " << std::endl; example_02::run(); std::cout << std::endl << std::endl;

    return 0;
}