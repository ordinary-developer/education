#include <algorithm>
#include <atomic>
#include <execution>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<int> v = { 1, 2, 3 };
    std::atomic<int> sum = 0;    

    std::for_each(std::execution::par, std::begin(v), std::end(v), [&sum](int i) {
        sum += i + i;
    });

    std::cout << sum << std::endl;
}
