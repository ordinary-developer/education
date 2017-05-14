#include <iostream>

template <typename T>
void f(const T& x) {
    std::cout << "My arg is a reference" << std::endl;
}

template <typename T>
void f(const T* x) {
    std::cout << "My arg is a pointer" << std::endl;
}

int main() {
    const char* s = "text";
    f(s);
    f(3.14);

    double p = 0;
    f(&p);

    return 0;
}
