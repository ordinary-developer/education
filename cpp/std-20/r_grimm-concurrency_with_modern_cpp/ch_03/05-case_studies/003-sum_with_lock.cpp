#include <chrono>
#include <iostream>
#include <mutex>
#include <numeric>
#include <random>
#include <vector>

constexpr long long size = 100'000'000;

std::mutex gMutex;


int main() {
	std::cout << '\n';

	std::vector<int> randValues;
	randValues.reserve(size);

	// random values
	std::random_device seed;
	std::mt19937 engine(seed());
	std::uniform_int_distribution<> uniformDist(1, 10);
	for (long long i = 0; i < size; ++i) {
		randValues.push_back(uniformDist(engine));
	}

	const auto sta = std::chrono::steady_clock::now();

	unsigned long long sum = {};
	for (auto i : randValues) {
		std::lock_guard<std::mutex> _(gMutex);
		sum += i;
	}

	const std::chrono::duration<double> dur =
		std::chrono::steady_clock::now() - sta;

	std::cout << "Time for addition " << dur.count()
		<< " seconds" << '\n';

	std::cout << "Result: " << sum << '\n';
}
