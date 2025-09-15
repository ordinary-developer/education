#include <chrono>
#include <future>
#include <iostream>
#include <random>
#include <thread>
#include <utility>
#include <vector>


constexpr long long size = 100'000'000;

constexpr long long first = 25'000'000;
constexpr long long second = 50'000'000;
constexpr long long third = 75'000'000;
constexpr long long fourth = 100'000'000;

void sumUp(std::promise<unsigned long long>&& prom, const std::vector<int>& val,
	unsigned long long beg, unsigned long long end)
{
	unsigned long long sum = {};
	for (auto i = beg; i < end; ++i) {
		sum += val[i];
	}
	prom.set_value(sum);
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

	std::promise<unsigned long long> prom1;
	std::promise<unsigned long long> prom2;
	std::promise<unsigned long long> prom3;
	std::promise<unsigned long long> prom4;

	auto fut1 = prom1.get_future();
	auto fut2 = prom2.get_future();
	auto fut3 = prom3.get_future();
	auto fut4 = prom4.get_future();

	const auto start = std::chrono::system_clock::now();

	std::thread t1(sumUp, std::move(prom1), std::ref(randValues), 0, first);
	std::thread t2(sumUp, std::move(prom2), std::ref(randValues), first, second);
	std::thread t3(sumUp, std::move(prom3), std::ref(randValues), second, third);
	std::thread t4(sumUp, std::move(prom4), std::ref(randValues), third, fourth);

	auto sum = fut1.get() + fut2.get() + fut3.get() + fut4.get();

	std::chrono::duration<double> dur = std::chrono::system_clock::now() - start;
	std::cout << "Time for addition " << dur.count()
		<< " seconds" << '\n';
	std::cout << "Result: " << sum << '\n';

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	std::cout << '\n';
}
