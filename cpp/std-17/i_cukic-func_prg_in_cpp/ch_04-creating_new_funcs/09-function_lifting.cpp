#include <algorithm>
#include <string>
#include <cctype>
namespace {

std::string str_to_upper(std::string& s) {
    std::transform(std::cbegin(s), std::cend(s), std::begin(s),
        [](unsigned char c) { return std::toupper(c); });

    return s;
}

} // anonymous namespace


#include <string>
#include <vector>
#include <cassert>
namespace test_01 { // -> lifting a fuction with functions

void pointer_to_upper(std::string* pStr) {
    if (pStr)
        str_to_upper(*pStr);
}

void vector_to_upper(std::vector<std::string>& strs) {
    for (auto& str : strs)
        str_to_upper(str);
}

void run() {
    std::string str = "abc";
    pointer_to_upper(&str);
    assert("ABC" == str);

    std::vector<std::string> strs{ "abc", "cba" };
    vector_to_upper(strs);
    assert((std::vector<std::string>{ "ABC", "CBA" } == strs));
}

} // test_01


#include <string>
#include <vector>
#include <cassert>
namespace test_02 { // lifting a function with lambdas

template <typename Function>
auto pointer_lift(Function f) {
    return [f](auto* item) {
        if (item)
            f(*item);
    };
}

template <typename Function>
auto collection_lift(Function f) {
    return [f](auto& items) {
        for (auto& item : items)
            f(item);
    };
}

void run() {
    std::string str = "abc";
    pointer_lift(str_to_upper)(&str);
    assert("ABC" == str);

    std::vector<std::string> strs{ "abc", "cba" };
    collection_lift(str_to_upper)(strs);
    assert((std::vector<std::string>{ "ABC", "CBA" } == strs));
}

} // test_02


#include <iostream>
int main() {
    std::cout << "test_01 => [ok]" << std::endl; test_01::run(); std::cout << std::endl;
    std::cout << "test_02 => [ok]" << std::endl; test_02::run(); std::cout << std::endl;

    return 0;
}
