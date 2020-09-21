#include <vector>
#include <list>
#include <iostream>
#include <cassert>
namespace example_01 { // -> initialize of std::vector
void run() {
    std::vector<int> const v1{ 1, 2, 3, 4, 5 };
    assert((std::vector<int>{ 1, 2, 3, 4, 5 } == v1));
    
    int constexpr const arr[] = { 1, 2, 3, 4, 5 };
    std::vector<int> const v2{ arr, arr + 5 };
    assert((std::vector<int>{ 1, 2, 3, 4, 5 } == v2));
    
    std::list<int> const l{ 1, 2, 3, 4, 5 };
    std::vector<int> const v3{ l.begin(), l.end() };
    assert((std::vector<int>{ 1, 2, 3, 4, 5 } == v3));
    
    std::vector<int> const v4(5, 1);
    assert((std::vector<int>{ 1, 1, 1, 1, 1 } == v4));
    
    std::cout << "[ok]";
}    
} // example_01


#include <vector>
#include <string>
#include <iostream>
#include <cassert>
namespace example_02 { // -> modify std::vector
void run() {
    std::vector<int> v1{ 1, 2, 3, 4, 5 };
    v1.push_back(6);
    assert((std::vector<int>{ 1, 2, 3, 4, 5, 6 } == v1));
    
    v1.pop_back();
    assert((std::vector<int>{ 1, 2, 3, 4, 5 } == v1));
    
    int constexpr const arr[] = { 1, 2, 3, 4, 5 };
    std::vector<int> v2{};
    v2.insert(v2.begin(), arr, arr + 5);
    assert((std::vector<int>{ 1, 2, 3, 4, 5 } == v2));
    
    using namespace std::string_literals;
    struct foo final {
        int a;
        double b;
        std::string c;
        
        foo(int const a, double const b, std::string const& c)
            : a{a}, b{b}, c{c} {}
    };
    std::vector<foo> v3{};
    v3.emplace_back(1, 1.0, "one"s);
    assert((
        not v3.empty() and 1 == v3.size() 
        and 1 == v3.begin()->a and "one"s == v3.begin()->c));
    
    v3.emplace(v3.begin(), 2, 2.0, "two"s);
    assert((
        not v3.empty() and 2 == v3.size()
        and 2 == v3.begin()->a and "two"s == v3.begin()->c));
        
    std::cout << "[ok]";
}
} // example_02


#include <vector>
#include <iostream>
#include <cassert>
namespace example_03 { // modify the whole std::vector
void run() {
    std::vector<int> const v1{ 1, 2, 3, 4, 5 };
    std::vector<int> v2{ 10, 20, 30 };
    v2 = v1;
    assert((std::vector<int>{ 1, 2, 3, 4, 5 } == v2));
    
    int constexpr const arr[] = { 1, 2, 3, 4, 5 };
    std::vector<int> v3{};
    v3.assign(arr, arr + 5);
    assert((std::vector<int> { 1, 2, 3, 4, 5 } == v3));
    
    std::vector<int> v4{ 1, 2, 3, 4, 5 };
    std::vector<int> v5{ 10, 20, 30 };
    v4.swap(v5);
    assert((std::vector<int>{ 10, 20, 30 } == v4
        and std::vector<int>{ 1, 2, 3, 4, 5 } == v5));
        
    std::vector<int> v6{ 1, 2, 3, 4, 5 };
    v6.clear();
    assert(v6.empty());
    
    std::vector<int> v7{ 1, 2, 3, 4, 5 };
    v7.erase(v7.begin() + 2, v7.begin() + 4);
    assert((std::vector<int>{ 1, 2, 5 } == v7));
    
    std::cout << "[ok]";
}    
} // example_03


#include <vector>
#include <iostream>
namespace example_04 { // -> std::vector with C-like API

void process([[maybe_unused]] int const * const arr, [[maybe_unused]] int const size) {} // C-like function

void run() {
    std::vector<int> v{ 1, 2, 3, 4, 5 };
    
    process(v.data(), static_cast<int>(v.size()));
    process(&v[0], static_cast<int>(v.size()));
    process(&v.front(), static_cast<int>(v.size()));
    process(&*v.begin(), static_cast<int>(v.size()));

    std::cout << "[ok]";
}
} // example_04


#include <vector>
#include <iostream>
#include <cassert>
namespace example_05 { // -> reserve space for std::vector
void run() {
    std::vector<int> v1{ 1, 2, 3, 4, 5 };
    v1.reserve(10);
    assert(10 == v1.capacity());
    v1.shrink_to_fit();
    assert(v1.size() == v1.capacity());
    
    std::vector<int> v2{ 1, 2, 3, 4, 5 };
    std::vector<int>{}.swap(v2);
    assert(v2.empty() and 0 == v2.capacity());
   
    std::vector<int> v3{ 1, 2, 3, 4, 5 };
    v3.reserve(10);
    assert(10 == v3.capacity());
    v3.clear();
    assert(v3.empty() and 10 == v3.capacity());
    
    std::cout << "[ok]";
}
    
} // example_05


int main() {
    std::cout << "example_01 => " << std::endl; example_01::run(); std::cout << std::endl << std::endl;
    std::cout << "example_02 => " << std::endl; example_02::run(); std::cout << std::endl << std::endl;
    std::cout << "example_03 => " << std::endl; example_03::run(); std::cout << std::endl << std::endl;
    std::cout << "example_04 => " << std::endl; example_04::run(); std::cout << std::endl << std::endl;
    std::cout << "example_05 => " << std::endl; example_05::run(); std::cout << std::endl << std::endl;
    
	return 0;
}
