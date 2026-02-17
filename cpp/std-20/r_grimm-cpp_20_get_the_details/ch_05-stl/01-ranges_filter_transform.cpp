#include <iostream>
#include <ranges>
#include <vector>


int main() {
    std::vector<int> const numbers = { 1, 2, 3, 4, 5, 6 };

    auto results = numbers
        | std::views::filter([](int const n) { return 0 == n % 2; })
        | std::views::transform([](int const n) { return n * 2; });

    for (auto const& v : results)
        std::cout << v << " ";
}
