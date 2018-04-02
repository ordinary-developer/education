// region [how to do it]
#include <iostream>
#include <typeinfo>
#include <cassert>
#include <initializer_list>
namespace example_01 {

void run() {
    static_assert(true);
    auto i = 42;
    auto d = 42.5;
    auto s = "text";
    auto v = {1, 2, 3};

    int i2 = 42;
    double d2 = 42.5;
    char const* s2 = "text";
    std::initializer_list<int> v2 = {1, 2, 3};
    assert(typeid(i) == typeid(i2));
    assert(typeid(d) == typeid(d2));
    assert(typeid(s) == typeid(s2));
    assert(typeid(v) == typeid(v2));

    std::cout << "typeid(i): " << typeid(i).name() << std::endl;
    std::cout << "typeif(d): " << typeid(d).name() << std::endl;
    std::cout << "typeif(s): " << typeid(s).name() << std::endl;
    std::cout << "typeif(v): " << typeid(v).name() << std::endl;
}
}


#include <cassert>
#include <typeinfo>
#include <string>
#include <vector>
#include <memory>
#include <iostream>
namespace example_02 {

void run() {
    auto b = new char[10]{ 0 };
    auto s = std::string{ "text" };
    auto v = std::vector<int>{ 1, 2, 3 };
    auto p = std::make_shared<int>(42);

    char* b2 = new char[10]{ 0 };
    std::string s2 = std::string{ "text" };
    std::vector<int> v2 = std::vector<int>{ 1, 2, 3 };
    std::shared_ptr<int> p2 = std::make_shared<int>(42);
    assert(typeid(b) == typeid(b2));
    assert(typeid(s) == typeid(s2));
    assert(typeid(v) == typeid(v2));
    assert(typeid(p) == typeid(p2));

    std::cout << "typeid(b): " << typeid(b).name() << std::endl;
    std::cout << "typeid(s): " << typeid(s).name() << std::endl;
    std::cout << "typeid(v): " << typeid(v).name() << std::endl;
    std::cout << "typeid(p): " << typeid(p).name() << std::endl;


    delete b;
    b = nullptr;
    delete b2;
    b2 = nullptr;
}
}


#include <iostream>
#include <typeinfo>
#include <cctype>
#include <functional>
namespace example_03 {

void run() {
    auto upper = [](char const c) { return toupper(c); };

    std::function<int(char const)> upper2 = 
        [](char const c) { return toupper(c); };

    std::cout << "typeid(upper): " << typeid(upper).name() << std::endl;
    std::cout << "typeid(upper2): " << typeid(upper2).name() << std::endl;
}
}


#include <iostream>
#include <typeinfo>
#include <functional>
namespace example_04 {

void run() {
    auto add = [](auto const a, auto const b) { return a + b; };

    std::cout << "typeid(add): " << typeid(add).name() << std::endl;
}
}


namespace example_05 {

template <typename F, typename T>
auto apply(F&& f, T value) {
    return f(value);
}

void run() {
}
}
// endregion [how to do it]

// region [how it works]
#include <vector>
#include <cstddef>
#include <typeinfo>
#include <cassert>

namespace example_06 {

void run() {
    auto v = std::vector<int>{ 1, 2, 3 };
    int size1 = v.size();
    auto size2 = v.size();
    auto size3 = int{ v.size() }; // here an warning will be

    std::cout << "typeid(size1): " << typeid(size1).name() << std::endl;
    std::cout << "typeid(size2): " << typeid(size2).name() << std::endl;
    std::cout << "typeid(size3): " << typeid(size3).name() << std::endl;
}

}

#include <iostream>
namespace example_07 {

class foo {
    public:
        foo(int const x = 0) : x_{ x } {}
        int& get() { return x_; }

    private:
        int x_;
};

void run() {
    foo f{42};
    auto x = f.get();
    x = x + 100; 
    std::cout << f.get() << std::endl;
}
}


#include <iostream>
#include <typeinfo>
namespace example_08 {

void run() {
    auto l = 42LL;

    std::cout << "typeid(l): " << typeid(l).name() << std::endl;
}
}


namespace example_09 {

auto func1(int const i) -> int { return 2 * i; }

auto func2(int const i) { return 2 * i; }

void run() {
}
}


#include <iostream>
namespace example_10 {

class foo {
    public:
        foo(int const x = 0) : x_{ x } {}
        int& get() { return x_; }

    private:
        int x_;
};

decltype(auto) proxy_get(foo& f) { return f.get(); }

void run() {
    auto f = foo{ 42 };
    decltype(auto) x = proxy_get(f);
    x += 100;
    std::cout << f.get() << std::endl;
}
}


#include <iostream>
#include <string>
namespace example_11 {

struct {
    template <typename T, typename U>
    auto operator() (T const a, U const b) const { return a + b; }
} struct_add;

void run() {
    auto lambda_add = [](auto const a, auto const b) { return a + b; };

    auto i = lambda_add(40, 2);

    using namespace std::literals;
    auto s = lambda_add("forty"s, "two"s);
}
}
// endregion [how it works]



typedef void (*ExampleFunction)();

#include <array>
#include <cstddef>
int main() {
    const size_t ARRAY_SIZE = 11;
    std::array<ExampleFunction, ARRAY_SIZE> examples{ {
        &example_01::run, &example_02::run, &example_03::run,
        &example_04::run, &example_05::run, &example_06::run,
        &example_07::run, &example_08::run, &example_09::run,
        &example_10::run, &example_11::run } };
    
    for (const auto & example : examples) {
        std::cout << "example => " << std::endl;
        example();
        std::cout << "end" << std::endl << std::endl;
    }

    return 0;
}
