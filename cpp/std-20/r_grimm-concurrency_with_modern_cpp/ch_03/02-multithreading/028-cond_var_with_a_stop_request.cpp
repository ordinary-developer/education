#include <iostream>
#include <condition_variable>
#include <chrono>
#include <mutex>
#include <thread>

using namespace std::literals;


std::mutex gMut;
std::condition_variable_any gCondVar;

bool gDataReady;

void receiver(std::stop_token stopToken) {
    std::cout << "[ .... ] receiver: waiting" << std::endl;

    std::unique_lock<std::mutex> lock(gMut);
    bool ret = gCondVar.wait(lock, stopToken, []{ return gDataReady; });
    std::cout << "[ .... ] receiver: " << (ret ? "a notification has been received"
                                               : "a stop request has been received")
                                       << std::endl;
}

void sender() {
    std::this_thread::sleep_for(5ms);
    {
        std::lock_guard<std::mutex> _(gMut);
        gDataReady = true;
        std::cout << "[ .... ] sender: has been sending a notification" << std::endl;
    }
    gCondVar.notify_one();
}


int main() {
    std::jthread t1(receiver);
    std::jthread t2(sender);

    t1.request_stop();

    t1.join();
    t2.join();

    std::cout << std::endl;
}
