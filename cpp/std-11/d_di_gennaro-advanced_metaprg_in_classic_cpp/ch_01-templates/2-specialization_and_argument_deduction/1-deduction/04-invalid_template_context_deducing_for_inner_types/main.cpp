#include <vector>

namespace example1 {

template <typename T>
void f(typename std::vector<T>::iterator) { }

void run() {
    std::vector<double> v;
    // error: cannot deduce T
    // f(v.begin());
}
}


namespace example2 {

template <typename T>
struct A {
    typedef double type;
};

template <typename T>
void f(typename A<T>::type) { }

void run() {
    A<int> a;
    // en error again
    // f(a);
}
}


namespace example3 {

template <typename T>
void f(std::vector<T>&, typename std::vector<T>::iterator) { }

void run() {
    std::vector<double> v;
    f(v, v.begin());
}
}


namespace example4 {

template <typename T>
void f(typename std::vector<T>::iterator) { }

void run() {
    std::vector<double> v;
    f<double>(v.begin());
}
}


int main() {
    example1::run();
    example2::run();
    example3::run();
    example4::run();

    return 0;
}
