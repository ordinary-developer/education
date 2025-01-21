#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>


std::mutex gMutex;
std::condition_variable gCondVar;

bool gDataReady{false};

void doTheWork() {
    std::cout << "[ .... ] processing shared data" << std::endl;
}

void waitingForWork() {
    std::cout << "[ .... ] worker: waiting for work" << std::endl;

    std::unique_lock<std::mutex> lock(gMutex);
    while (not []{ return gDataReady; }()) {
        gCondVar.wait(lock);
    }

    doTheWork();
    std::cout << "[  ok  ] worker: work done" << std::endl;
}

void setDataReady() {
    {
        std::lock_guard<std::mutex> _(gMutex);
        gDataReady = true;
    }
    std::cout << "[  ok  ] sender: data is ready" << std::endl;
    gCondVar.notify_one();
}


int main() {
    std::thread t1(waitingForWork);
    std::thread t2(setDataReady);
    t1.join();
    t2.join();
}
