#include <chrono>
#include <iostream>
#include <mutex>
#include <random>
#include <thread>
#include <utility>
#include <vector>


constexpr long long size = 100'000'000;

constexpr long long first = 25'000'000;
constexpr long long second = 50'000'000;
constexpr long long third = 75'000'000;
constexpr long long fourth = 100'000'000;

std::mutex myMutex;

void sumUp(unsigned long long& sum, const std::vector<int>& val,
	unsigned long long beg, unsigned long long end)
{
	unsigned long long tmpSum{};

	for (auto i = beg; i < end; ++i) {
		tmpSum += val[i];
	}

	std::lock_guard<std::mutex> lockGuard(myMutex);
	sum += tmpSum;
}


int main() {
	std::cout << '\n';

	std::vector<int> randValues;
	randValues.reserve(size);

	std::mt19937 engine;
	std::uniform_int_distribution<> uniformDist(1, 10);
	for (long long i = 0; i < size; ++i) {
		randValues.push_back(uniformDist(engine));
	}

	unsigned long long sum{};
	const auto start = std::chrono::system_clock::now();

	std::thread t1(sumUp, std::ref(sum), std::ref(randValues), 0, first);
	std::thread t2(sumUp, std::ref(sum), std::ref(randValues), first, second);
	std::thread t3(sumUp, std::ref(sum), std::ref(randValues), second, third);
	std::thread t4(sumUp, std::ref(sum), std::ref(randValues), third, fourth);

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	const std::chrono::duration<double> dur =
		std::chrono::system_clock::now() - start;

	std::cout << "Time for addition " << dur.count()
		<< " seconds" << '\n';
	std::cout << "Result: " << sum << '\n';

	std::cout << '\n';
}
