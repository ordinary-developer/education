#include <vector>
#include <algorithm>
#include <execution>

int main() {
    std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    std::sort(v.begin(), v.end());

    std::sort(std::execution::seq, v.begin(), v.end());

    std::sort(std::execution::par, v.begin(), v.end());

    std::sort(std::execution::par_unseq, v.begin(), v.end());
}