#include <string>
#include <vector>

namespace workspace { 

void func(unsigned char b, double d) {}

template <typename T>
using vec_t = std::vector<T>;

void example_01() { // -> how to do it
    {
        using byte = unsigned char;
        using byte_ptr = unsigned char *;
        using array_t = int[10];
        using fn = void(byte, double);

        byte b{42};
        byte_ptr pb = new byte[10]{0};
        array_t a{0, 1, 2, 3, 4, 5, 7, 8, 9};
        fn* f = func;
    }

    {
        vec_t<int> vi;
        vec_t<std::string> vs;
    }
}


template <typename T>
class foo {
    typedef T value_type;
};

void example_02() { // -> how it works
    typedef unsigned char byte;    
    typedef unsigned char * byte_ptr;
    typedef int array_t[10];
    typedef void(*fn)(byte, double);

    typedef std::vector<int> vint_t;
}

void run() {
    example_01();
    example_02();
}


} // workspace

int main() {
    workspace::run();

    return 0;
}