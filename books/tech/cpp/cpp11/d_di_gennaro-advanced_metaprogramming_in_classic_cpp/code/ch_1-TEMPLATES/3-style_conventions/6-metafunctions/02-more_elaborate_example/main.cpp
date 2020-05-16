#include <iostream>


template <typename T>
struct largest_precision_type;

template <>
struct largest_precision_type<float> {
    typedef double type;
};

template <>
struct largest_precision_type<double> {
    typedef double type;
};

template <>
struct largest_precision_type<int> {
    typedef long type;
};


template <unsigned int N>
struct two_to {
    static const unsigned int value = (1 << N);
};

template <unsigned int N>
struct another_two_to {
    enum { value = (1 << N) };
};


int main() {
    unsigned int i = two_to<5>::value;
    largest_precision_type<int>::type j = i + 100;
    std::cout << i << std::endl;
    std::cout << j << std::endl;

    return 0;
}
