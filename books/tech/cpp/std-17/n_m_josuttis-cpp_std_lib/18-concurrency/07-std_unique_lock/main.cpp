#include <thread>
#include <mutex>
#include <chrono>
#include <iostream>
namespace workspace {
    
bool readyFlag{};
std::mutex readyFlagMutex{};    
    
void thread1() {
    std::this_thread::sleep_for(std::chrono::seconds{ 3 });
    
    std::lock_guard<std::mutex> lock{ readyFlagMutex };
    readyFlag = true;
    
    std::cout << "[producer]: ready flag is written - true\n";
}
    
void thread2() {
    {
        std::unique_lock<std::mutex> lock{ readyFlagMutex };
        while (not readyFlag) {
            lock.unlock();
            std::this_thread::yield();
            std::this_thread::sleep_for(std::chrono::milliseconds{ 100} );
            lock.lock();
        }
    }
    
    std::cout << "[consumer]: ready flag is read - true\n";
}
    
void run() {
    std::thread t1{ thread1 }, t2{ thread2 };
    t1.join(); t2.join();
}
    
} // workspace


int main() {
    workspace::run();
    
    return 0;
}
