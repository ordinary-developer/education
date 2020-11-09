#include <vector>
#include <list>
#include <cassert>
namespace example_01 { // -> initialize std::vector
void run() {
    {
    std::vector<int> const v{ 1, 2, 3, 4, 5 };
    assert((std::vector<int>{ 1, 2, 3, 4, 5 } == v));
    }

    {
    int constexpr const arr[] = { 1, 2, 3, 4, 5 };
    std::vector<int> const v{ arr, arr + 5 };
    assert((std::vector<int>{ 1, 2, 3, 4, 5 } == v));
    }

    {
    std::list<int> const l{ 1, 2, 3, 4, 5 };
    std::vector<int> const v(std::cbegin(l), std::cend(l));
    assert((std::vector<int>{ 1, 2, 3, 4, 5 } == v));
    }

    {
    std::vector<int> const v(5, 1);
    assert((std::vector<int>{ 1, 1, 1, 1, 1 } == v));
    }
}    
} // example_01



#include <vector>
#include <string>
#include <cassert>
namespace example_02 { // -> modify std::vector
void run() {
    {
    std::vector<int> v{ 1, 2, 3, 4, 5 };
    v.push_back(6);
    assert((std::vector<int>{ 1, 2, 3, 4, 5, 6} == v));

    v.pop_back();
    assert((std::vector<int>{ 1, 2, 3, 4, 5 } == v));
    }

    {
    int constexpr const arr[] = { 1, 2, 3, 4, 5 };
    std::vector<int> v{};
    v.insert(std::begin(v), arr, arr + 5);
    assert((std::vector<int>{ 1, 2, 3, 4, 5 } == v));
    }

    {
    using namespace std::string_literals;
    struct foo final {
        int a;
        double b;
        std::string c;        

        foo (int const a, double const b, std::string const& c)
            : a(a), b(b), c(c) {}

        bool operator==(foo const& other) const { return other.a == a and std::abs(other.b - b) < 0.001 and other.c == c; }
    };
    std::vector<foo> v{};
    v.emplace_back(1, 1.0, "one"s);
    assert((std::vector<foo>{ { 1, 1.0, "one"s} } == v));

    v.emplace(std::begin(v), 2, 2.0, "two"s);
    assert((std::vector<foo>{ { 2, 2.0, "two"s }, { 1, 1.0, "one"s} } == v));
    }
}
} // example_02


#include <vector>
#include <cassert>
namespace example_03 { // -> modify the whole std::vector
void run() {
    {
    std::vector<int> const v1{ 1, 2, 3, 4, 5 };
    std::vector<int> v2{ 10, 20, 30 };
    v2 = v1;
    assert((std::vector<int>{ 1, 2, 3, 4, 5 } == v1));
    }

    {
    int constexpr const arr[] = { 1, 2, 3, 4, 5 };
    std::vector<int> v{};
    v.assign(arr, arr + 5);
    assert((std::vector<int>{ 1, 2, 3, 4, 5 } == v));
    }

    {
    std::vector<int> v1{ 1, 2, 3, 4, 5 };
    std::vector<int> v2{ 10, 20, 30 };
    v1.swap(v2);
    assert((std::vector<int>{ 10, 20, 30 } == v1
        and std::vector<int>{ 1, 2, 3, 4, 5 } == v2));
    }

    {
    std::vector<int> v{ 1, 2, 3, 4, 5 };
    v.clear();
    assert((v.empty()));
    }

    {
    std::vector<int> v{ 1, 2, 3, 4, 5 };
    v.erase(std::begin(v) + 2, std::begin(v) + 4);
    assert((std::vector<int>{ 1, 2, 5 } == v));
    }
}
} // example_03


#include <vector>
#include <cassert>
namespace example_04 { // -> std::vector with C-like API

void process([[maybe_unused]] int const * const arr, [[maybe_unused]] int const size) {} // C-like function

void run() {
    std::vector<int> v{ 1, 2, 3, 4, 5 };

    process(v.data(), static_cast<int>(v.size()));
    process(&v[0], static_cast<int>(v.size()));
    process(&v.front(), static_cast<int>(v.size()));
    process(&*std::begin(v), static_cast<int>(v.size()));
    process(&*std::cbegin(v), static_cast<int>(v.size()));
}
} // example_04


#include <vector>
#include <cassert>
namespace example_05 { // -> space allocation/deallocation for std::vector
void run() {
    {
    std::vector<int> v{ 1, 2, 3, 4, 5 };
    v.reserve(10);
    assert((10 == v.capacity()));
    }

    {
    std::vector<int> v{ 1, 2, 3, 4, 5 };
    std::vector<int>{}.swap(v);
    assert((v.empty() and 0 == v.capacity()));
    }

    {
    std::vector<int> v{ 1, 2, 3, 4, 5 };
    v.reserve(10);
    assert((not v.empty() and 10 == v.capacity()));
    v.clear();
    assert((v.empty() and 10 == v.capacity()));
    }
}
} // example_05


#include <iostream>
int main() {
    std::cout << "[ok] - example_01 => " << std::endl; example_01::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example_02 => " << std::endl; example_02::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example_03 => " << std::endl; example_03::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example_04 => " << std::endl; example_04::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example_05 => " << std::endl; example_05::run(); std::cout << std::endl << std::endl;

    return 0;
}