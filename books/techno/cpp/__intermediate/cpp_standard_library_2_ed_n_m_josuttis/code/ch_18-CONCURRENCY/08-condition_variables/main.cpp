#include <mutex>
#include <condition_variable>
#include <iostream>
#include <future>
#include <exception>


bool readyFlag{};
std::mutex readyMutex{};
std::condition_variable readyConditionVar{};

void thread1() {
    std::cout << "<return>" << std::endl;
    std::cin.get();

    {
        std::lock_guard<std::mutex> lock{ readyMutex };
        readyFlag = true;
    }
    readyConditionVar.notify_one();
}

void thread2() {
    {
        std::unique_lock<std::mutex> lock{ readyMutex };
        readyConditionVar.wait(lock, []{ return readyFlag; });
    }
    std::cout << "done" << std::endl;
}


int main() {
    try {
        std::future<void> f1 { std::async(std::launch::async, thread1) };
        std::future<void> f2 { std::async(std::launch::async, thread2) };
    }
    catch (std::exception const& e) { std::cout << e.what() << std::endl; }

    return 0;
}
