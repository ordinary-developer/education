#include <algorithm>
#include <execution>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> v{ 1, 2, 3, 4 };
    
    const auto val1 = std::accumulate(v.begin(), v.end(), 1, [](int a, int b) { return a * b; });
    std::cout << val1 << std::endl;

    const auto val2 = std::reduce(std::execution::par, std::begin(v), std::end(v), 1,
        [](int a, int b) { return a * b; });
    std::cout << val2 << std::endl;
}
