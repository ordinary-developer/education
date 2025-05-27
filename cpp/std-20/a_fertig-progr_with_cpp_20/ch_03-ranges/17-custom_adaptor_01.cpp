#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

int main() {
	std::string suffix{ "EUR" };
	const std::vector prices{ 3.95, 6.0, 95.4, 10.95, 12.90, 5.50 };

	auto subView = prices
		| std::views::filter([](auto e) { return e < 10.00;  })
		| std::views::transform(
			[suffix](auto i) { return std::to_string(i) + suffix; });

	for (const auto& e : subView) {
		std::cout << e << '\n';
	}
}
