#include <functional>
#include <iostream>
namespace example01 {

constexpr double multiply(double const multiplicand, 
                          double const multiplier) noexcept 
{
    return multiplicand * multiplier;
}

void run() {
    auto const result1 = multiply(10.0, 5.0);
    auto boundMultiplyFunctor = std::bind(multiply, 10.0, 5.0);
    auto const result2 = boundMultiplyFunctor();

    std::cout << "result1 = " << result1 << ", result2 = " << result2
              << std::endl;
}

}

#include <functional>
#include <iostream>
namespace example02 {

constexpr double multiply(double const multiplicand,
                          double const multiplier) noexcept 
{
    return multiplicand * multiplier;
}

void run() {
    auto multiplyWith10 = std::bind(multiply, 
                                    std::placeholders::_1,
                                    10.0);
    std::cout << "result = " << multiplyWith10(5.0) << std::endl;

    std::function<double(double, double)> multiplyFunc{ multiply };
    auto result = multiplyFunc(10.0, 5.0);
    std::cout << "result = " << result << std::endl;
}

}

int main() {
    example01::run();
    example02::run();

    return 0;
}
