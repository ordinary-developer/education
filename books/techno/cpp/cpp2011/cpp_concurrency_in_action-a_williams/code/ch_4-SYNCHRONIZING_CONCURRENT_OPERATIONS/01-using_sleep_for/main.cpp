#include <thread>
#include <mutex>
#include <chrono>
#include <iostream>


bool flag = false;
std::mutex m;

void wait_for_flag() {
    std::unique_lock<std::mutex> lk(m);
    while(!flag) {
        lk.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        lk.lock();
    }
}


int main() {
    std::cout << "[...] - starting a thread" << std::endl;
    std::thread anotherThread(wait_for_flag);
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    flag = true;
    anotherThread.join();
    std::cout << "[OK] - ending the thread" << std::endl;

    return 0;
}
