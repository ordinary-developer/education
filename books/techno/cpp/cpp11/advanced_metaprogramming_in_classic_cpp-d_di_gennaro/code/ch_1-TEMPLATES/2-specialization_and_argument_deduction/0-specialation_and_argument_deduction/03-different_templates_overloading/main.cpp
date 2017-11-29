#include <iostream>

template <typename T>
void f(const T& x) {
    std::cout << "I am f(reference)" << std::endl;
}

template <typename T>
void f(const T* x) {
    std::cout << "I am f(pointer)" << std::endl;
}

void firstExample() {
    int a = 5;
    int* pa = &a;
    f(&a);
    f(*pa);
    f(a);
}


template <typename T> void f2(T) { }
template <typename T> void f2(T*) { }

template <>         // ambigous: may be the first f with T=int*
void f2(int*)       // or the second with T=int
{}

template <>
void f2<int>(int*) { } // ok

int main() {
    firstExample();

    return 0;
}
