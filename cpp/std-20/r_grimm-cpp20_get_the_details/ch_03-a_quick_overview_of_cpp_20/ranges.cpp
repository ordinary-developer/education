#include <iostream>
#include <ranges>
#include <vector>


int main() {
    std::vector<int> const ints{ 0, 1, 2, 3, 4, 5 };

    auto const even = [](int const i) { return 0 == i % 2; };
    auto const square = [](int const i) { return i * i; };

    for (int i : ints | std::views::filter(even) | std::views::transform(square)) {
        std::cout << i << ' ';
    }
}
