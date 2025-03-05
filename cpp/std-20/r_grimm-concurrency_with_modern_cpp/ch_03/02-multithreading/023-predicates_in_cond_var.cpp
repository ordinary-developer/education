#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>


std::mutex gMutex;
std::condition_variable gCondVar;

bool gDataReady{ false };


void doTheWork() {
	std::cout << "Processing shared data." << '\n';
}

void waitingForWork() {
	std::cout << "Worker: Waiting for work." << '\n';
	std::unique_lock<std::mutex> lock(gMutex);
	while (not [] { return gDataReady; }()) {
		gCondVar.wait(lock);
	}
	doTheWork();
	std::cout << "Worker: Work done." << '\n';
}

void setDataReady() {
	{
		std::lock_guard<std::mutex> _(gMutex);
		gDataReady = true;
	}
	std::cout << "Sender: Data is ready." << '\n';
	gCondVar.notify_one();
}


int main() {
	std::thread t1(waitingForWork);
	std::thread t2(setDataReady);
	t1.join();
	t2.join();

	std::cout << '\n';
}
