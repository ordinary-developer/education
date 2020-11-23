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


// example 07 -> read-only structured bindings
#include <string>
#include <utility>
#include <vector>

class Customer1 {
    public:
        Customer1(std::string f, std::string l, long v)
            : first_(std::move(f)), last_(std::move(l)), val_(v) {}

        std::string getFirst() const { return first_; }
        std::string getLast() const { return last_; }
        long getValue() const { return val_; }
        
    private:
        std::string first_;
        std::string last_;
        long val_;
};

template<>
struct std::tuple_size<Customer1> {
    static constexpr int value = 3;
};

template <>
struct std::tuple_element<2, Customer1> {
    using type = long;
};

template <std::size_t Idx>
struct std::tuple_element<Idx, Customer1> {
    using type = std::string;
};

template<std::size_t I> auto get(Customer1 const& c) {
    static_assert(I < 3);
    if constexpr(0 == I)
        return c.getFirst();
    else if constexpr(1 == I)
        return c.getLast();
    else
        return c.getValue();
}

template<> auto get<0>(Customer1 const& c) { return c.getFirst(); }
template<> auto get<1>(Customer1 const& c) { return c.getLast(); }
template<> auto get<2>(Customer1 const& c) { return c.getValue(); }

namespace example_07 { 

void run() {
    {
    using namespace std::literals::string_literals;

    Customer1 c("Tim"s, "Starr"s, 42);
    auto [f, l, v] = c;
    assert(("Tim"s == f and "Starr"s == l and 42 == v));

    std::string s = std::move(f);
    l = "Waters"s;
    v += 10;
    assert(("Tim"s == s));
    assert((""s == f and "Waters"s == l and 52 == v));
    assert(("Tim"s == c.getFirst() and "Starr"s == c.getLast() and 42 == c.getValue()));
    }

    {
    using namespace std::literals::string_literals;

    std::vector<Customer1> coll{ { "first1"s, "last1", 1 }, { "first2"s, "last2"s, 2 }, { "first3"s, "last3"s, 3 }};
    for (auto const& [first, last, val]: coll)
        assert((
            ("first1"s == first or "first2"s == first or "first3"s == first) and
            ("last1"s == last or "last2"s == last or "last3"s == last) and
            (1 == val or 2 == val or 3 == val)));
    }    
}
} // example_07



#include <string>
#include <utility>

class Customer2 {
    public:
        Customer2(std::string f, std::string l, long v)
            : first_(std::move(f)), last_(std::move(l)), val_(v) {}

        const std::string& firstname() const {
            return first_;
        }
        std::string& firstname() { 
            return first_;
        }

        const std::string& lastname() const {
            return last_;
        }
        std::string& lastname() {
            return last_;
        }

        long value() const {
            return val_;
        }
        long& value() { 
            return val_;
        } 

    private:
        std::string first_;
        std::string last_;
        long val_;
};


template<>
struct std::tuple_size<Customer2> {
    static constexpr int value = 3;
};

template<>
struct std::tuple_element<2, Customer2> {
    using type = long;
};
template<std::size_t Idx>
struct std::tuple_element<Idx, Customer2> {
    using type = std::string;
};

template<std::size_t I> decltype(auto) get(Customer2& c) {
    static_assert(I < 3);
    if constexpr(0 == I)
        return c.firstname();
    else if constexpr (1 == I)
        return c.lastname();
    else
        return c.value();
}
template<std::size_t I> decltype(auto) get(Customer2 const& c) {
    static_assert(I < 3);
    if constexpr (0 == I)
        return c.firstname();
    else if constexpr (1 == I)
        return c.lastname();
    else
        return c.value();
}
template<std::size_t I> decltype(auto) get(Customer2&& c) {
    static_assert(I < 3);
    if constexpr (0 == I)
        return std::move(c.firstname());
    else if constexpr (1 == I)
        return std::move(c.lastname());
    else
        return c.value();
}

namespace example_08 { // -> structured bindings with write-access
void run() {    
    Customer2 c{ "Tim", "Starr", 42 };
    auto [f, l, v] = c;
    assert(("Tim" == f and "Starr" == l and 42 == v));

    // modify structured bindings via refs
    auto&& [f2, l2, v2] = c;
    std::string s = std::move(f2);
    f2 = "Ringo";
    v2 += 10;
    assert((
        ("Ringo" == f2 and "Ringo" == c.firstname()) and
        ("Starr" == l2 and "Starr" == c.lastname()) and
        (52 == v2 and 52 == c.value()) and
        ("Tim" == s ) ));    
}
}


#include <iostream>
int main() {
    std::cout << "[ok] - example 01 =>" << std::endl; example_01::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example 02 =>" << std::endl; example_02::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example 03 =>" << std::endl; example_03::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example 04 =>" << std::endl; example_04::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example 05 =>" << std::endl; example_05::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example 06 =>" << std::endl; example_06::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example 07 =>" << std::endl; example_07::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example 08 =>" << std::endl; example_08::run(); std::cout << std::endl << std::endl;

    return 0;
}