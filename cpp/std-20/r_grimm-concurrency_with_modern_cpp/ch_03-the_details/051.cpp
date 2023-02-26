#include <algorithm>
#include <execution>
#include <iostream>
#include <mutex>
#include <string>
#include <vector>

std::mutex mut;

int main() {
    std::vector<int> v = { 1, 2, 3 };
    int sum = 0;    

    std::for_each(std::execution::par, std::begin(v), std::end(v), [&sum](int i) {
        std::lock_guard<std::mutex> lock{mut};
        sum += i + i;
    });

    std::cout << sum << std::endl;
}
