#include <cstddef>
#include <iostream>


template <int N>
struct A {
    char data[N];
};


int main() {
    std::cout << sizeof(A<42>) << std::endl;
    return 0;
}
