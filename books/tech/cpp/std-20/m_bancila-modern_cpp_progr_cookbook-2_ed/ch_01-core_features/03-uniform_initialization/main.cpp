#include <string>
namespace example_01 { // -> the "getting ready" section

void run() {
    {
        std::string s1("test");
        std::string s2 = "test";
    }
}
} // example_01


#include <vector>
#include <map>
namespace example_02 { // -> the "how to do it" section

void run() {
    {
        std::vector<int> v{ 1, 2, 3 };
        std::map<int, std::string> m{ { 1, "one" }, { 2, "two" } };

        int* arr2 = new int[3]{ 1, 2, 3 };
        delete[] arr2;

        int arr1[3] { 1, 2, 3 };

        int i{42};
        double d{1.2};

        class foo {
            int a_;
            double b_;

        public:
            foo() : a_(0), b_(0) {}
            foo(int a, double b = 0.0) : a_(a), b_(b) {}
        };
        foo f1{};
        foo f2{ 42, 1.2 };
        foo f3{42};

        struct bar { int a_; double b_; };
        bar b{ 42, 1.2 };
    }
}
} // example_02



#include <initializer_list>
#include <iostream>
#include <vector>
#include <cassert>
namespace example_03 { // -> the "how it works" section

void func(int const a, int const b, int const c) { std::cout << a << b << c << '\n'; }
void func(std::initializer_list<int> const list) {
    std::cout << "func with the initializer list\n";
    for (auto const & e : list)
        std::cout << e << '\n';
}

void run() {
    {
        int a0 = 42;
        double b0 = 1.2;

        class foo {
            int a_;
        public:
            foo(int a) : a_(a) {}
        };
        foo f0 = 42;

        class foo_ex {
            int a_;
            double b_;
        public:
            foo_ex() : a_(0), b_(0) {}
            foo_ex(int a, double b = 0.0) : a_(a), b_(b) {}
        };
        foo_ex f1;
        foo_ex f2(42, 1.2);
        foo_ex f3(42);

        struct bar { int a_; double b_; };
        bar b = { 42, 1.2 };
        int a[] = { 1, 2, 3, 4, 5 };
    }

    {
        class foo {
            int a_;
            int b_;
        public:
            foo() : a_(0), b_(0) { std::cout << "default ctor" << std::endl; }
            foo(int a, int b = 0) : a_(a), b_(b) { std::cout << "custom ctor" << std::endl; }
            foo(std::initializer_list<int> l) { std::cout << "ctor with the initializer list" << std::endl; }
        };
        foo f{ 1, 2 };

        func({ 1, 2, 3 });

        std::vector<int> v1{5};
        std::vector<int> v2(5);
    }

    {
        int i{ static_cast<int>(1.2) };
        double d = 42 / 17;
        float f1{ static_cast<float>(d) };
        float f2{ 42 / 17 };
    }
}
} // example_03


#include <typeinfo>
namespace example_04 { // the "there's more" section

void run() {
    {
        auto a = { 42 }; // std::initializer_list<int>
        assert((
            typeid(std::initializer_list<int>{}).name() == typeid(a).name()
        ));

        auto b{42}; // int
        assert((
            typeid(int).name() == typeid(b).name()
        ));

        auto c = { 4, 2 };
        assert((
            typeid(std::initializer_list<int>{}).name() == typeid(c).name()
        ));
    }
}
} // example_04


int main() {
    example_01::run();
    example_02::run();
    example_03::run();
    example_04::run();

    return 0;
}
