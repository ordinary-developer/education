#include <future>
#include <iostream>

using FactorialPromise = std::promise<long long>;

long long Factorial(unsigned int value) {
    return (value == 1 ? 1 : value * Factorial(value - 1));
}

int main() {
    FactorialPromise promise{};
    std::future<long long> taskFuture{ promise.get_future() };

    promise.set_value(Factorial(3));
    std::cout << "Factorial result was " << taskFuture.get() << std::endl;

    return 0;
}
