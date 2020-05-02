template <int N>
struct power10;

template <int N>
struct square { 
    enum t {value = N * N }; 
};

template <int N, bool Even>
struct power10_aux { 
    enum t { value = 10 * power10<N-1>::value };
};

template <int N>
struct power10_aux<N, true> { 
    enum t { value = square<power10<N/2>::value>::value };
};

template <int N>
struct power10 {
    enum t { value = power10_aux<N, 0 == N % 2>::value };
};

template <>
struct power10<0> { enum t { value = 1 }; };

#include <iostream>
int main() {
    std::cout << power10<2>::value << std::endl;

    return 0;
}
