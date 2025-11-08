#include <algorithm>
#include <iostream>
#include <vector>

bool is_odd(int num)
{
	return 0 != (num % 2);
}

void stl() {
	std::vector<int> numbers{ 2, 3, 4, 5, 6 };

	std::vector<int> oddNumbers{};
	std::copy_if(begin(numbers),
				end(numbers),
				std::back_inserter(oddNumbers),
				is_odd);

	std::vector<int> results{};
	std::transform(begin(oddNumbers),
					end(oddNumbers),
					back_inserter(results),
					[](int n) { return n * 2; });

	for (int n : results) { std::cout << n << ' '; }
}

int main() {
	stl();
}
