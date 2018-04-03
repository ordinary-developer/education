// region [how to do it]
#include <iostream>
#include <typeinfo>
namespace example_01 {

void func(unsigned char b, double d) { return; }

void run() {
    using byte = unsigned char;
    byte b{ 42 };
    std::cout << "typeid(b): " << typeid(b).name() << std::endl;

    using pbyte = unsigned char*;
    pbyte pb = new byte[10]{ 0 };
    std::cout << "typeid(pb): " << typeid(pb).name() << std::endl;
    delete [] pb;
    pb = nullptr;

    using array_t = int[10];
    array_t a{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << "typeid(a): " << typeid(a).name() << std::endl;

    using fn = void(byte, double);
    fn* f = func;
    std::cout << "typeid(f): " << typeid(f).name() << std::endl;
}
} // example_01

#include <iostream>
#include <vector>
namespace example_02 {

// dumb class 
template <class T>
class custom_allocator { };

template <typename T>
using vec_t = std::vector<T, custom_allocator<T>>;

void run() { }
} // example_02
// endregion [how to do it]


// region [how it works]
#include <iostream>
#include <typeinfo>
#include <vector>
namespace example_03 {

typedef unsigned char byte;
typedef unsigned char* pbyte;
typedef int array_t[10];

template <typename T>
class foo {
    public:
        typedef T value_type;
};

typedef std::vector<int> vint_t;

void run() {
    byte b{ 42 };
    std::cout << "typeid(b): " << typeid(b).name() << std::endl;
    
    pbyte pb = new byte[10]{ 0 };
    std::cout << "typeid(pb): " << typeid(pb).name() << std::endl;
    delete[] pb;
    pb = nullptr;

    array_t a{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << "typeid(a): " << typeid(a).name() << std::endl;

    foo<int>::value_type foo_value_type{};
    std::cout << "typeid(foo_value_type): " 
              << typeid(foo_value_type).name() << std::endl;

    vint_t v{ 0, 1, 2 };
    std::cout << "typeid(v): " << typeid(v).name() << std::endl;
}
}
// endregion [how it works]

using ExampleFunction = void();

#include <array>
#include <cstddef>
#include <iostream>
int main() {
    const size_t ARRAY_SIZE = 3;
    std::array<ExampleFunction*, ARRAY_SIZE> examples{ {
        &example_01::run, &example_02::run, &example_03::run } };
    
    for (const auto & example : examples) {
        std::cout << "example => " << std::endl;
        example();
        std::cout << "end" << std::endl << std::endl;
    }

    std::cout << "DONE" << std::endl;

    return 0;
}
