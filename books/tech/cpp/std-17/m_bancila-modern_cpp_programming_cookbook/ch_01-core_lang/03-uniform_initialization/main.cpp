// region [getting ready]
#include <string>
#include <iostream>
namespace example_01 {

void run() {
    std::string s1("test");
    std::string s2 = "test";

    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
}
} // example_02
// endregion [getting ready]


// region [how to do it]
#include <vector>
#include <map>
#include <string>
namespace example_02 {

class foo {
    public:
        foo() : a_{ 0 }, b_{ 0 } {}
        foo(int a, double b = 0.0) : a_{ a }, b_{ b } {}

    private:
        int a_;
        double b_;
};

void run() {
    std::vector<int> v{ 1, 2, 3 };
    std::map<int, std::string> m{ { 1, "one" }, { 2, "two" } };

    int arr1[3]{ 1, 2, 3 };

    int* arr2 = new int[3]{ 1, 2, 3 };
    delete[] arr2;
    arr2 = nullptr;

    int i{ 42 };
    double d{ 1.2 };

    foo f1{};
    foo f2{ 42, 1.2 };
    foo f3{ 42 };

    struct bar { int a_; double b_; };
    bar b{ 42, 1.2 };
}
} // example_02
// endregion [how to do it]


// region [how it works]
namespace example_03 {

class foo {
    public:
        foo() : a_{ 0 }, b_{ 0.0 } {}
        foo(int a, double b = 0.0) : a_{ a }, b_{ b } {}

    private:
        int a_;
        double b_;
};

class foobar {
    public:
        foobar(int a) : a_{ a } {}

    private:
        int a_;
};

void run() {
    int i = 42;
    double d = 1.2;

    foo f1;
    foo f2(42, 1.2);
    foo f3(42);
    foo f4(); // function declaration

    foobar fb = 42;

    struct bar{ int a_; double b_; };
    bar b = { 42, 1.2 };

    int a[] = { 1, 2, 3, 4 };
}
} // example_03

#include <initializer_list>
#include <iostream>
namespace example_04 {

class foo {
    public:
        foo() : a_{ 0 }, b_{ 0 } {}
        foo(int a, int b = 0) : a_{ a }, b_{ b } {}
        foo(std::initializer_list<int> l) { 
            std::cout << "ctor with an initializer_list" << std::endl;
        }

    private:
        int a_;
        int b_;
};

void run() {
    foo f{ 1, 2 };
}
} // example_04

#include <iostream>
#include <initializer_list>
namespace example_05 {

void func(int const a, int const b, int const c) {
    std::cout << a << " " << b << " " << c << std::endl;
}

void func(std::initializer_list<int> const l) {
    std::cout << "func with a initializer_list" << std::endl;
    for (auto const & e : l) 
        std::cout << e << std::endl;
}

void run() {
    func({ 1, 2, 3 });
}
} // example_05

#include <vector>
#include <iostream>
namespace example_06 {

void run() {
    std::vector<int> v1{ 5 };
    std::vector<int> v2(5);

    std::cout << "v1.size(): " << v1.size() << std::endl;
    std::cout << "v2.size(): " << v2.size() << std::endl;
}
} // example_06

namespace example_07 {

void run() {
    int i{ static_cast<int>(1.2) };
    double d = 47 / 13;
    float f1{ static_cast<float>(d) };
}
} // example_07
// endregion [how it works]


// region [there's more]
#include <initializer_list>
#include <typeinfo>
#include <iostream>
namespace example_08 {

void run() {
    auto a = { 42 };
    auto b{ 42 };
    auto c = { 4, 2 };

    std::cout << "typeid(a): " << typeid(a).name() << std::endl;
    std::cout << "typeid(b): " << typeid(b).name() << std::endl;
    std::cout << "typeid(c): " << typeid(c).name() << std::endl;
}
} // example_08
// endregion [there's more]


using ExampleFunction = void();

#include <array>
#include <cstddef>
#include <iostream>
int main() {
    const size_t ARRAY_SIZE = 7;
    std::array<ExampleFunction*, ARRAY_SIZE> examples{ {
        &example_01::run, &example_02::run, &example_03::run,
        &example_04::run, &example_05::run, &example_06::run,
        &example_07::run } };
    
    for (const auto & example : examples) {
        std::cout << "example => " << std::endl;
        example();
        std::cout << "end" << std::endl << std::endl;
    }

    std::cout << "DONE" << std::endl;

    return 0;
}
