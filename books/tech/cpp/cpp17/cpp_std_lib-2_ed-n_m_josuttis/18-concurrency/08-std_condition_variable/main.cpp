#include <condition_variable>
#include <mutex>
#include <future>
#include <iostream>
namespace workspace {

bool readyFlag{};
std::mutex readyMutex{};
std::condition_variable readyCondVar{};
    
void thread1() {
    // do something thread2 need as prepartion
    std::cout << "<return>" << std::endl;
    std::cin.get();
    
    // signal that thread1 has prepared a condition
    {
        std::lock_guard<std::mutex> lock{ readyMutex };
        readyFlag = true;
    } // release lock
    readyCondVar.notify_one();
}
    
void thread2() {
    // wait until thread1 is ready (readyFlag is true)
    {
        std::unique_lock<std::mutex> lock{ readyMutex };
        readyCondVar.wait(lock, []{ return readyFlag; });
    } // release lock
    
    // do whatever shall happen after thread1 has preparerd things
    std::cout << "done" << std::endl;
}

void run() {
    auto f1 = std::async(std::launch::async, thread1);    
    auto f2 = std::async(std::launch::async, thread2);    
}
} // workspace

int main() {
    workspace::run();
    
    
    return 0;
}
