#include <iostream>
#include <vector>


std::vector<int> getNumbers(int begin, int end, int inc = 1) {
	std::vector<int> numbers;

	return numbers;
}


int main() {
	std::cout << '\n';

	const auto numbers = getNumbers(-10, 11);
	for (auto n : numbers) {
		std::cout << n << " ";
	}
	std::cout << "\n\n";

	for (auto n : getNumbers(0, 101, 5)) {
		std::cout << n << " ";
	}
	std::cout << "\n\n";
}
