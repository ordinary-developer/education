#include <chrono>
#include <future>
#include <iostream>
#include <thread>


int main() {
	std::cout << '\n';

	std::async(std::launch::async, [] {
		std::this_thread::sleep_for(std::chrono::seconds(2));
		std::cout << "first thread" << '\n';
	});

	std::async(std::launch::async, [] {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "second thread" << '\n';
	});

	std::cout << "main thread" << '\n';

	std::cout << '\n';
}
