#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>


std::mutex mutex_;
std::condition_variable condVar;

bool dataReady{false};

void doTheWork() {
    std::cout << "Processing shared data." << std::endl;
}

void waitingForWork() {
    std::cout << "Worker: Waiting for work." << std::endl;
    std::unique_lock<std::mutex> lock{mutex_};
    condVar.wait(lock, [] { return dataReady; });
    doTheWork();
    std::cout << "Work done." << std::endl;
}

void setDataReady() {
    {
        std::lock_guard<std::mutex> lock{mutex_};
        dataReady = true;
    }
    std::cout << "Sender: Data is ready." << std::endl;
    condVar.notify_one();
}

int main() {
    std::cout << std::endl;

    std::thread t1{ waitingForWork };
    std::thread t2{ setDataReady };;;;

    t1.join();
    t2.join();

    std::cout << std::endl;
}
