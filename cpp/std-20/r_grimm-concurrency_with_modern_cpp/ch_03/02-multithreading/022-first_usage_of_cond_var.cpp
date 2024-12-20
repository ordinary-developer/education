#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>


std::mutex mutex;
std::condition_variable condVar;

bool dataReady{false};

void doTheWork() {
    std::cout << "Processing shared data." << '\n';
}

void waitingForWork() {
    std::cout << "Worker: Waiting for work." << '\n';
    std::unique_lock<std::mutex> lock(mutex);
    condVar.wait(lock, []{ return dataReady; });

    doTheWork();
    std::cout << "Work done." << '\n';
}

void setDataReady() {
    {
        std::lock_guard<std::mutex> lock(mutex);
        dataReady = true;
    }
    std::cout << "Sender: Data is ready." << '\n';
    condVar.notify_one();
}


int main() {
    std::cout << '\n';

    std::thread t1(waitingForWork);
    std::thread t2(setDataReady);
    t1.join();
    t2.join();

    std::cout << '\n';
}
