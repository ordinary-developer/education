#include <stdexcept>
#include <future>
#include <iostream>

int calculate() {
    throw std::runtime_error{ "Exception thrown from a thread." };
}

int main() {
    auto future = std::async(std::launch::async, calculate);
    try {
        int result = future.get();
        std::cout << result << std::endl;
    }
    catch (std::exception const& e) { 
        std::cout << "exception: " << e.what() << std::endl;
    }

    return 0;
}
