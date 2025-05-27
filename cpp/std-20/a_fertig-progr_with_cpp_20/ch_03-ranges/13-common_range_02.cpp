#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>

int main() {
	auto v = std::vector{ 3, 5, 6, 7, 9 };

	auto rng = v |
		std::views::take_while([](int x) { return x > 5; })
		| std::views::common;

	auto res = std::accumulate(rng.begin(), rng.end(), 0);
	std::cout << res << '\n';
}
