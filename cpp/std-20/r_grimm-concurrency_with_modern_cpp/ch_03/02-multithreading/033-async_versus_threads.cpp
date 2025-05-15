#include <future>
#include <thread>
#include <iostream>


int main() {
	std::cout << '\n';

	int res;

	std::thread t([&] { res = 2000 + 11; });
	t.join();
	std::cout << "res: " << res << '\n';

	auto fut = std::async([] { return 2000 + 11; });
	std::cout << "fut.get(): " << fut.get() << '\n';

	std::cout << '\n';
}
