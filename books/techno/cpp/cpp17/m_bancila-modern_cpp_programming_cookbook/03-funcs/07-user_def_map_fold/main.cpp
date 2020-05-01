#include <algorithm>
#include <memory>
#include <map>
#include <numeric>
#include <queue>
namespace funclib {

template <typename F, typename R> // for std::array, std::vector, std::list, c-like array
constexpr R mapf(F&& f, R const& r) {
    R ret{r};
    std::transform(
        std::begin(ret), std::end(ret), std::begin(ret),
        std::forward<F>(f));
    return ret;        
}

template <typename F, typename T, typename U> // for std::map
constexpr std::map<T, U> mapf(F&& f, std::map<T, U> const& m) {
    std::map<T, U> ret{};
    for (auto const& kvp : m)
        ret.insert(f(kvp));
    return ret;
}

template <typename F, typename T> // for std::queue
constexpr std::queue<T> mapf(F&& f, std::queue<T> const& q) {
    std::queue<T> ret{};
    std::queue<T> q_tmp{q};
    while (not q_tmp.empty()) {
        ret.push(f(q_tmp.front()));
        q_tmp.pop();
    }
    return ret;
}

template <typename F, typename R, typename T> // for std::array, std::vector, std::list, std::map
constexpr T foldl(F&& f, R&& r, T i) {
    return std::accumulate(
        std::cbegin(r), std::cend(r), std::move(i), std::forward<F>(f));
}

template <typename F, typename R, typename T>
constexpr T foldr(F&& f, R&& r, T i) {
    return std::accumulate(
        std::crbegin(r), std::crend(r), std::move(i), std::forward<F>(f));
}

} // -> funclib


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
#include <functional>
#include <vector>
#include <cassert>
namespace example_06 { // funclib::fold using for std::vector<int>

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

} // example_06


#include <string>
#include <vector>
#include <iostream>
#include <cassert>
namespace example_07 { // funclib::fold using for std::vector<std::string>

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

} // example_07


#include <string>
#include <iostream>
#include <functional>
#include <cassert>
namespace example_08 { // funclib::fold for c-like array

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
} // example_08


#include <map>
#include <iostream>
#include <cassert>
namespace example_09 { // funclib::fold for std::map

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

} // example_09


#include <iostream>
int main() {
    std::cout << "example_01 =>" << std::endl; example_01::run(); std::cout << std::endl << std::endl;
    std::cout << "example_02 =>" << std::endl; example_02::run(); std::cout << std::endl << std::endl;
    std::cout << "example_03 =>" << std::endl; example_03::run(); std::cout << std::endl << std::endl;
    std::cout << "example_04 =>" << std::endl; example_04::run(); std::cout << std::endl << std::endl;
    std::cout << "example_05 =>" << std::endl; example_05::run(); std::cout << std::endl << std::endl;
    std::cout << "example_06 =>" << std::endl; example_06::run(); std::cout << std::endl << std::endl;
    std::cout << "example_07 =>" << std::endl; example_07::run(); std::cout << std::endl << std::endl;
    std::cout << "example_08 =>" << std::endl; example_08::run(); std::cout << std::endl << std::endl;
    std::cout << "example_09 =>" << std::endl; example_09::run(); std::cout << std::endl << std::endl;

    return 0;
}
