#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>


bool is_odd(int num) {
	return 0 != (num % 2);
}

void ranges() {
	std::vector<int> numbers{ 2, 3, 4, 5, 6 };

	auto filter = std::views::filter(numbers, is_odd);

	auto transform =
		std::views::transform([](int n) { return n * 2; });

	auto results = transform(filter);

	for (int n : results) {
		std::cout << n << ' ';
	}

	std::cout << '\n';
}


int main() {
	ranges();
}
