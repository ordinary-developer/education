#include <iostream>
namespace example01 {

template <unsigned int x, unsigned int y>
struct GreatestCommonDivisor {
    static unsigned int const result = 
        GreatestCommonDivisor<y, x % y>::result;
};

template <unsigned x>
struct GreatestCommonDivisor<x, 0> {
    static unsigned int const result = x;
};

void run() {
    std::cout << "The GCD of 40 and 10 is: "
              << GreatestCommonDivisor<40u, 10u>::result << std::endl;
    std::cout << "The GCD of 366 and 60 is: "
              << GreatestCommonDivisor<366u, 60u>::result << std::endl;
}

}

#include <iostream>
namespace example02 {

constexpr unsigned int greatestCommonDivisor(unsigned int const x,
                                             unsigned int const y) noexcept
{
    return 0 == y ? x : greatestCommonDivisor(y, x % y);
}

void run() {
    std::cout << "The GCD of 40 and 10 is: "
              << greatestCommonDivisor(40, 10) << std::endl;
    std::cout << "The GCD of 366 and 60 is: "
              << greatestCommonDivisor(366, 60) << std::endl;
}
}

#include <iostream>
#include <numeric>
namespace example03 {
void run() {
    constexpr auto result = std::gcd(40, 10);
    std::cout << "The GCD of 40 and 10 is: " << result << std::endl;
}
}

int main() {
    example01::run();
    example02::run();
    example03::run();

    return 0;
}
