#include <future>
#include <iostream>

int calculate() { return 123; }

int main() {
    auto future = std::async(calculate);
    int result = future.get();
    std::cout << result << std::endl;

    return 0;
}
