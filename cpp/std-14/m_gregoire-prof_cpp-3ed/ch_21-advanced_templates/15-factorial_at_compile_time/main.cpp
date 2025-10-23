#include <iostream>

template <unsigned char f>
class Factorial {
    public:
        static const unsigned long long val = (f * Factorial<f - 1>::val);
};

template <>
class Factorial<0> {
    public:
        static const unsigned long long val = 1;
};

int main() {
    std::cout << Factorial<6>::val << std::endl;

    return 0;
}
