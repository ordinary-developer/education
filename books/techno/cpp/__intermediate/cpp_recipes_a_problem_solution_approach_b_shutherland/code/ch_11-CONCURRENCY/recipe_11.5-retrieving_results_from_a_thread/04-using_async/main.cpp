#include <future>
#include <iostream>

long long Factorial(unsigned int value) {
    std::cout << "ThreadTask thread: " << std::this_thread::get_id() << std::endl;
    return (value == 1 ? 1 : value * Factorial(value - 1));
}

int main() {
    std::cout << "main thread: " << std::this_thread::get_id() << std::endl;

    auto taskFuture1 = std::async(Factorial, 3);
    std::cout << "Factorial result was " << taskFuture1.get() << std::endl;

    auto taskFuture2 = std::async(std::launch::async, Factorial, 3);
    std::cout << "Factorial result was " << taskFuture2.get() << std::endl;
    
    auto taskFuture3 = std::async(std::launch::deferred, Factorial, 3);
    std::cout << "Factorial result was " << taskFuture3.get() << std::endl;

    auto taskFuture4 = std::async(std::launch::async | std::launch::deferred, 
                                  Factorial, 3);
    std::cout << "Factorial result was " << taskFuture4.get() << std::endl;

    return 0;
}
