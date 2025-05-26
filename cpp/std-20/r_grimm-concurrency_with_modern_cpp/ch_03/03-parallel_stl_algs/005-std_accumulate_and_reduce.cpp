#include <algorithm>
#include <execution>
#include <iostream>
#include <numeric>
#include <vector>


int main() {
	std::vector<int> v{ 1, 2, 3, 4 };

	const int value1 = std::accumulate(v.begin(), v.end(), 1, [](int a, int b) { return a * b; });
	std::cout << value1 << std::endl;

	const int value2 = std::reduce(std::execution::par, v.begin(), v.end(), 1, [](int a, int b) { return a * b;  });
	std::cout << value2 << std::endl;
}
