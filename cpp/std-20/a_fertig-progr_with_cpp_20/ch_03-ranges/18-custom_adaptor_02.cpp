#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>


auto addCurrency(const std::string& suffix) {
	return std::views::transform(
		[suffix](auto i) { return std::to_string(i) + suffix; });
}

int main() {
	const std::vector prices{ 3.95, 6.0, 95.4, 10.95, 12.90, 5.50 };

	auto subView = prices
		| std::views::filter([](auto e) { return e < 10.0; })
		| addCurrency("EUR");

	for (const auto& e : subView) {
		std::cout << e << '\n';
	}

}
