#include <algorithm>
#include <atomic>
#include <execution>
#include <iostream>
#include <mutex>
#include <vector>


std::mutex m;

int main() {
	{
		std::vector<int> v  { 1, 2, 3 };
		int sum = 0;

		std::for_each(std::execution::par, v.begin(), v.end(), [&sum](int i) {
			std::lock_guard<std::mutex> lock(m);
			sum += i + i;
			});
	}

	{
		std::vector<int> v = { 1, 2, 3 };
		std::atomic<int> sum = 0;

		std::for_each(std::execution::par_unseq, v.begin(), v.end(), [&sum](int i) {
			sum += i + i;
		});
	}

	{
		std::vector<int> v = { 1, 2, 3 };
		std::atomic<int> sum = 0;

		std::for_each(std::execution::par_unseq, v.begin(), v.end(), [&sum](int i) {
			sum.fetch_add(i + i, std::memory_order_relaxed);
		});
	}
}
