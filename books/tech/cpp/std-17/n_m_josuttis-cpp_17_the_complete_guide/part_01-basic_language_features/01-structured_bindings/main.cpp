#include <string>
#include <map>
#include <cassert>
namespace example_01 { // -> structured binding

struct MyStruct {
    int i = 0;
    std::string s;
};

MyStruct getStruct() { return MyStruct{ 42, "abc" }; }

void run() {
    using namespace std::literals::string_literals;

    {
    MyStruct const ms{ 17, "abc"s };

    auto const [u, v] = ms;
    assert((17 == u and "abc"s == v));
    }

    {
    auto const [id, val] = getStruct();
    assert((42 == id and "abc"s == val));
    }

    {
    std::map<int, std::string> const mymap{ { 17, "17"s }, { 42, "42"s } };

    for (auto const& elem : mymap)
        assert(((17 == elem.first or 42 == elem.first) and ("17"s == elem.second or "42"s == elem.second)));

    for (auto const& [key, val] : mymap)
        assert(((17 == key or 42 == key) and ("17"s == val or "42"s == val)));
    }
}
} // example_01


#include <string>
#include <cassert>
namespace example_02 { // -> binding to an anonymous entity

struct MyStruct {
    int i = 0;
    std::string s;
};

void run() {
    using namespace std::literals::string_literals;

    {
    MyStruct ms{ 42, "abc"s };
    auto [u, v] = ms;
    ms.i = 77;
    assert((42 == u));
    u = 99;
    assert((77 == ms.i));
    }

    {
    MyStruct ms{ 42, "abc"s };
    auto const [u, v] = ms;
    assert((&v == &((MyStruct*)&u)->s));
    }
}
} // example_02


#include <string>
#include <cassert>
namespace example_03 { // -> using qualifiers

struct MyStruct {
    int i = 0;
    std::string s;
};

MyStruct getStruct() { return MyStruct{ 42, "abc" }; }

void run() {
    using namespace std::literals::string_literals;

    {
    MyStruct ms{ 42, "abc"s };
    auto const& [u, v] = ms;
    ms.i = 77;
    assert((77 == u));
    }

    {
    MyStruct ms{ 42, "abc"s };
    auto& [u, v] = ms;
    ms.i = 77;
    assert((77 == u));
    u = 99;
    assert((99 == ms.i));
    }

    {
    auto const& [a, b] = getStruct();
    assert((42 == a and "abc"s == b));
    }
}
} // example_03


#include <string>
#include <typeinfo>
#include <cassert>
namespace example_04 { // -> qualifiers and structured bindings

struct MyStruct {
    int i = 0;
    std::string s;
};

void run() {
    using namespace std::literals::string_literals;

    {
    auto const& [u, v] = MyStruct{ 42, "abc"s };
    assert((typeid(int) == typeid(u) and typeid(std::string) == typeid(v)));
    }

    {
    MyStruct ms{ 42, "abc"s };
    alignas(16) auto [u, v] = ms;
    }

    {
    struct S {
        const char x[6];
        const char y[3];
    } s1{};
    auto [a, b] = s1;
    assert((typeid(const char[6]) == typeid(a) and typeid(const char[3]) == typeid(b)));
    assert((typeid(char[6]) == typeid(a) and typeid(char[3]) == typeid(b)));
    assert((typeid(const char (&)[6]) == typeid(a) and typeid(const char(&)[3]) == typeid(b)));
    assert((typeid(char (&)[6]) == typeid(a) and typeid(char (&)[3]) == typeid(b)));

    auto a2 = a;
    assert((typeid(const char*) == typeid(a2) and typeid(const char* const) == typeid(a2)));

    auto b2 = b;
    assert((typeid(const char*) == typeid(b2) and typeid(const char* const) == typeid(b2)));

    assert((typeid(a2) == typeid(b2)));
    }
}
} // example_04


#include <string>
#include <memory>
#include <cassert>
namespace example_05 { // -> move semantics

struct MyStruct {
    int i = 0;
    std::string s;
};

void run() {
    using namespace std::literals::string_literals;

    {
    MyStruct ms = { 42, "abc" };
    auto&& [v, n] = std::move(ms);
    assert(("abc"s == ms.s));

    std::string s = std::move(n);
    assert(("abc"s != ms.s and "abc"s != n and "abc"s == s));
    }

    {
    MyStruct ms = { 42, "abc"s };
    auto [v, n] = std::move(ms);
    assert(("abc"s != ms.s and "abc"s == n));

    std::string s = std::move(n);
    assert(("abc"s != ms.s and "abc"s != n and "abc"s == s));

    n = "cba";
    assert(("abc"s != ms.s and "cba"s != ms.s and "cba"s == n and "abc"s == s));
    }
}
} // example_05


#include <string>
#include <array>
#include <tuple>
#include <utility>
#include <map>
#include <functional>
#include <cmath>
#include <cassert>
#include <iostream>
namespace example_06 { // -> where structured bindings can be used

struct MyStruct {
    int i = 0;
    std::string s;
};

MyStruct getStruct() { return MyStruct{ 42, "abc" }; }

int arr[2] = { 17, 42 };
auto getArr() -> int(&)[2] { return arr; }

std::array<int, 4> getArray() { return std::array<int, 4>{ 1, 2, 3, 4 }; }
std::tuple<char, float, std::string> getTuple() { return std::tuple<char, float, std::string>{ 'a', 42.0, "abc" }; }
std::tuple<char, float, std::string> getTuple2() { return std::tuple<char, float, std::string>{ 'b', 17.0, "cba" }; }

void run() {
    using namespace std::literals::string_literals;

    {
    auto [_, val] = getStruct();
    assert((42 == _ and "abc"s == val));
    }

    {
    struct B {
        int a = 1;
        int b = 2;
    };
    struct D1 : B {};

    auto [x, y] = D1{};
    assert((1 == x and 2 == y));
    }

    {
    int arr[] = { 47, 11 };
    auto [x, y] = arr;
    assert((47 == x and 11 == y));

    auto [x2, y2] = getArr();
    assert((17 == x2 and 42 == y2));
    }

    {
    auto [i, j, k, l] = getArray();
    assert((1 == i and 2 == j and 3 == k and 4 == l));

    std::array<int, 4> stdarr{ 1, 2, 3, 4 };
    auto& [i2, _, __, ___] = stdarr;
    i2 += 10;
    assert((11 == stdarr[0]));
    }

    {
    auto [a, b, c] = getTuple();
    assert(('a' == a and std::abs(b - 42.0) < 0.001 and "abc"s == c));
    }

    {
    std::map<std::string, int> coll;

    auto [pos, ok] = coll.insert({ "42"s, 42});
    assert((ok and "42"s == pos->first and 42 == pos->second) or (not ok));
    }

    {
    auto [a, b, c] = getTuple();
    assert(('a' == a and std::abs(b - 42.0) < 0.001 and "abc"s == c));

    std::tie(a, b, c) = getTuple2();
    assert(('b' == a and std::abs(b - 17.0) < 0.001 and "cba"s == c));
    }

    {
    std::string const txt = "cbaabccbaabccba"s;
    std::string const sub = "abc";
    std::boyer_moore_searcher bm{ std::cbegin(sub), std::cend(sub) };
    for (auto [beg, end] = bm(std::cbegin(txt), std::cend(txt)); beg != std::cend(txt); std::tie(beg, end) = bm(end, std::cend(txt))) 
        assert((
            (3 == std::distance(std::cbegin(txt), beg) and 6 == std::distance(std::cbegin(txt), end))
            or
            (9 == std::distance(std::cbegin(txt), beg) and 12 == std::distance(std::cbegin(txt), end))));
    }

}
} // example_06


#include <iostream>
int main() {
    std::cout << "[ok] - example 01 =>" << std::endl; example_01::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example 02 =>" << std::endl; example_02::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example 03 =>" << std::endl; example_03::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example 04 =>" << std::endl; example_04::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example 05 =>" << std::endl; example_05::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example 06 =>" << std::endl; example_06::run(); std::cout << std::endl << std::endl;

    return 0;
}