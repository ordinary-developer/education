#include <future>
#include <iostream>
#include <thread>
#include <utility>


std::mutex coutMutex;

struct Div {
	void operator()(std::promise<int>&& intPromise, int a, int b) {
		intPromise.set_value(a / b);
	}
};

struct Requestor {
	void operator() (std::shared_future<int> shaFut) {
		std::lock_guard<std::mutex> coutGuard(coutMutex);
		std::cout << "threadId(" << std::this_thread::get_id() << "): ";
		std::cout << "20/10 = " << shaFut.get() << '\n';
	}
};


int main() {
	std::cout << '\n';

	std::promise<int> divPromise;

	std::shared_future<int> divResult = divPromise.get_future();

	Div div;
	std::thread divThread(div, std::move(divPromise), 20, 10);

	Requestor req;
	std::thread sharedThread1(req, divResult);
	std::thread sharedThread2(req, divResult);
	std::thread sharedThread3(req, divResult);
	std::thread sharedThread4(req, divResult);
	std::thread sharedThread5(req, divResult);

	divThread.join();

	sharedThread1.join();
	sharedThread2.join();
	sharedThread3.join();
	sharedThread4.join();
	sharedThread5.join();

	std::cout << '\n';
}
