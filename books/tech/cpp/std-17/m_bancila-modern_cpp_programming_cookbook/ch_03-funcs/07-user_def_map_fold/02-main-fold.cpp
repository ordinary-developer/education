#include "funclib.hpp"

#include <iostream>
#include <functional>
#include <vector>
#include <cassert>
namespace example_01 { // funclib::fold using for std::vector<int>

void run() {
    // arrange
    auto const vnums = std::vector<int>{ 0, 2, -3, 5, -1, 6, 8, -4, 9 };

    // act
    auto const s1 = funclib::foldl(
        [](const int s, const int n) { return s + n; },
        vnums, 0);
    auto const s2 = funclib::foldl(
        std::plus<>(), vnums, 0);
    auto const s3 = funclib::foldr(
        [](const int s, const int n) { return s + n; },
        vnums, 0);
    auto const s4 = funclib::foldr(
        std::plus<>(), vnums, 0);

    // assert
    assert(22 == s1);
    assert(22 == s2);
    assert(22 == s3);
    assert(22 == s4);

    std::cout << "[ok]";
}

} // example_01


#include <string>
#include <vector>
#include <iostream>
#include <cassert>
namespace example_02 { // funclib::fold using for std::vector<std::string>

void run() {
    using namespace std::string_literals;

    // arrange
    auto const txts = std::vector<std::string>{
        "hello"s, " "s, "world"s, "!"s };

    // act
    auto const txt1 = funclib::foldl(
        [](std::string const& s, std::string const& n) { return s + n; },
        txts, ""s);
    auto const txt2 = funclib::foldr(
        [](std::string const& s, std::string const& n) { return s + n; },
        txts, ""s);

    // assert
    assert("hello world!"s == txt1);        
    assert("!world hello"s == txt2);        

    std::cout << "[ok]";
}

} // example_02


#include <string>
#include <iostream>
#include <functional>
#include <cassert>
namespace example_03 { // funclib::fold for c-like array

void run() {
    using namespace std::string_literals;

    // arrange
    char const chars[] = { 'c', 'i', 'v', 'i', 'c' };

    // act
    auto const str1 = funclib::foldl(std::plus<>(), chars, ""s);
    auto const str2 = funclib::foldr(std::plus<>(), chars, ""s);

    // assert
    assert("civic"s == str1);
    assert("civic"s == str2);

    std::cout << "[ok]";
}
} // example_03


#include <map>
#include <iostream>
#include <cassert>
namespace example_04 { // funclib::fold for std::map

void run() {
    // arrange
    auto const words = std::map<std::string, int>{
        { "one", 1 }, { "two", 2 }, { "three", 3 } };
    
    // act
    auto const count = funclib::foldl(
        [](int const s, std::pair<std::string, int> const& kvp) { return s + kvp.second; },
        words, 0);

    // assert
    assert(6 == count);

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
