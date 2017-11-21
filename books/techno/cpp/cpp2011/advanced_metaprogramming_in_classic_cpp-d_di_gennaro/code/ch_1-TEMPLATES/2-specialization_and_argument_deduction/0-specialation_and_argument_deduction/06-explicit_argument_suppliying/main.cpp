#include <iostream>

namespace n1 {

template <typename T>
T max(const T& a, const T& b) { return a; }

void example() {
    int a = 7;
    long b = 6;

    // error: ambigous, T can be int or long
    // long m1 = max(a, b); 
    long m2 = max<long>(a, b);
}
}


namespace n2 {

template <typename T>
T get_random() {
    return T();
}

void example() {
    double r = get_random<double>();
}
}


namespace n3 {

template <typename X, typename T>
X sabotage_cast(T* p) {
    return reinterpret_cast<X>(p + 1);
}

void example() {
    std::string s = "string";
    double* p = sabotage_cast<double*>(&s);
}
}


namespace n4 {

template <typename scalar_t>
scalar_t sq(const scalar_t& x) {
    return x * x;
}

void example() {
    double y = sq<int>(6.28);
}
}


namespace n5 {
template <typename LESS_T>
void nonstd_sort(LESS_T cmp = LESS_T()) { }

void example() {
    nonstd_sort<std::less<int>>();
    nonstd_sort(std::less<int>());
}
}

// explicitly supplying argument type is necessary
int main() {
    // for disambiguation
    n1::example();

    // when a type in non-deducible
    n2::example();

    // when you want a function template to look similar to 
    // a built-in C++ cast operator
    n3::example();

    // to perform simultaneously a cast 
    // and a function template invocation
    n4::example();

    // when an algorithm has an argument whose default value
    // is template-dependent (usually a functor)
    n5::example();

    return 0;
}
