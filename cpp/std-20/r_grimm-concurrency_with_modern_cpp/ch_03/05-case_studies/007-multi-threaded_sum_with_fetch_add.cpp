#include <atomic>
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

std::mutex gMutex;

void sumUp(std::atomic<unsigned long long>& sum, const std::vector<int>& val,
	unsigned long long beg, unsigned long long end)
{
	for (auto it = beg; it < end; ++it) {
		sum.fetch_add(val[it]);
	}
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

	std::atomic<unsigned long long> sum = 0;

	const auto start = std::chrono::steady_clock::now();

	std::thread t1(sumUp, std::ref(sum), std::ref(randValues), 0, first);
	std::thread t2(sumUp, std::ref(sum), std::ref(randValues), first, second);
	std::thread t3(sumUp, std::ref(sum), std::ref(randValues), second, third);
	std::thread t4(sumUp, std::ref(sum), std::ref(randValues), third, fourth);

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	std::chrono::duration<double> duration = std::chrono::steady_clock::now() - start;

	std::cout << "Time for addition " << duration.count()
		<< " seconds" << '\n';
	std::cout << "Result: " << sum << '\n';
	std::cout << '\n';
}
