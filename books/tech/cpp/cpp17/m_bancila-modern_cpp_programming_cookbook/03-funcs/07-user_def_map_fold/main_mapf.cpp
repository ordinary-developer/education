#include "funclib.hpp"

#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
namespace example_01 { // -> mapf using for vector, list and array

void run() {
    // arrange
    auto const vnums = std::vector<int>{ 
        0, 2, -3, 5, -1, 6, 8, -4, 9 };

    // act
    auto const r =  funclib::mapf([](int const i) {
        return std::abs(i); }, vnums);

    // assert
    assert((std::vector<int>{ 0, 2, 3, 5, 1, 6, 8, 4, 9 } == r));

    std::cout << "[ok]";
}

} // example_01


#include <iostream>
#include <list>
#include <cassert>
namespace example_02 { // mapf using for std::list

void run() {
    // arrange
    auto const lnums = std::list<int>{ 1, 2, 3, 4, 5 };

    // act
    auto const l = funclib::mapf([](int const i) {
        return i * i; }, lnums);
    
    // assert
    assert((std::list<int>{ 1, 4, 9, 16, 25} == l));

    std::cout << "[ok]";
}

} // example_02


#include <algorithm>
#include <array>
#include <limits>
#include <type_traits>
#include <cassert>
#include <cmath>
namespace example_03 { // mapf using for std::array

template <typename T = double>
struct fround {
    typename std::enable_if<
        std::is_floating_point<T>::value, T>::type
    operator()(T const& val) const {
        return std::round(val);
    }
};
void run() {
    // arrange
    auto const amounts = std::array<double, 5>{ 
        10.42, 2.50, 100.0, 23.75, 12.99 };

    // act        
    auto const act = funclib::mapf(fround<>(), amounts);

    // assert
    auto const exp = std::array<double, 5>{
        10.0, 3.0, 100.0, 24.0, 13.0 };
    const auto are_equal = std::equal(
        std::cbegin(exp), std::cend(exp), std::cbegin(act),
        [](double const lhs, double const rhs) { 
            return std::abs(lhs - rhs) < std::numeric_limits<double>::epsilon(); });
    assert(are_equal);

    std::cout << "[ok]";
}
} // example_03


#include <map>
#include <string>
#include <locale>
#include <cctype>
#include <cassert>
namespace example_04 { // funclib::mapf using for std::map

void run() {
    // arrange
    auto const words = std::map<std::string, int>{ 
        { "one", 1 }, { "two", 2 }, { "three", 3 } };

    // act
    auto const act = funclib::mapf(
        [](std::pair<std::string, int> const& kvp) {
            return std::make_pair(
                funclib::mapf(toupper, kvp.first),
                kvp.second);
        },
        words);

    // assert
    auto const exp = std::map<std::string, int>{
        { "ONE", 1}, { "TWO", 2 }, { "THREE", 3 } };
    assert((exp == act));
        
    std::cout << "[ok]";
}

} // example_04


#include <iostream>
#include <queue>
#include <cassert>
namespace example_05 { // funclib::mapf using for std::queue

void run() {
    // arrange
    auto priorities = std::queue<int>{};
    for (int i{0}; i < 5; ++i)
        priorities.push(10 * (i + 1));

    // act
    auto const act = funclib::mapf(
        [](int const i) { return i > 30 ? 2 : 1; },
        priorities);

    // assert
    auto exp = std::queue<int>{};
    exp.push(1); exp.push(1); exp.push(1); exp.push(2); exp.push(2);
    assert(exp == act);

    std::cout << "[ok]";
}

} // example_05


#include <iostream>
int main() {
    std::cout << "example_01 =>" << std::endl; example_01::run(); std::cout << std::endl << std::endl;
    std::cout << "example_02 =>" << std::endl; example_02::run(); std::cout << std::endl << std::endl;
    std::cout << "example_03 =>" << std::endl; example_03::run(); std::cout << std::endl << std::endl;
    std::cout << "example_04 =>" << std::endl; example_04::run(); std::cout << std::endl << std::endl;
    std::cout << "example_05 =>" << std::endl; example_05::run(); std::cout << std::endl << std::endl;

    return 0;
}
