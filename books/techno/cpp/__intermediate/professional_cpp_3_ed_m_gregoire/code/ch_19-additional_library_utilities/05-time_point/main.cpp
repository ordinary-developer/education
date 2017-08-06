#include <iostream>
#include <chrono>
#include <ratio>

int main() {
    std::chrono::time_point<std::chrono::steady_clock> tp1{};
    tp1 += std::chrono::minutes{10};
    auto d1 = tp1.time_since_epoch();
    std::chrono::duration<double> d2{d1};
    std::cout << d2.count() << " seconds" << std::endl;

    return 0;
}
