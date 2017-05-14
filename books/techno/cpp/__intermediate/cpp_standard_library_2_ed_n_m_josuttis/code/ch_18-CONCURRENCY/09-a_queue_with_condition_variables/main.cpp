#include <condition_variable>
#include <mutex>
#include <future>
#include <thread>
#include <iostream>
#include <queue>

std::queue<int> queue{};
std::mutex queueMutex{};
std::condition_variable queueConditionVar{};


void provider(int value) {
    for (int i{0}; i < 6; ++i) {
        {
            std::lock_guard<std::mutex> lock{ queueMutex };
            queue.push(value + i);
        }
        queueConditionVar.notify_one();

        std::this_thread::sleep_for(std::chrono::milliseconds{ value });
    }
}

void consumer(int number) {
    while (true) {
        int value{};
        {
            std::unique_lock<std::mutex> lock{ queueMutex };
            queueConditionVar.wait(lock, []{ return !queue.empty(); });
            value = queue.front();
            queue.pop();
        }
        std::cout << "consumer " << number << ": " << value << std::endl;
    }
}

int main() {
    std::future<void> provider1 { std::async(std::launch::async,
                                             provider, 100) };
    std::future<void> provider2 { std::async(std::launch::async,
                                             provider, 300) };
    std::future<void> provider3 { std::async(std::launch::async,
                                             provider, 500) };


    std::future<void> consumer1 { std::async(std::launch::async,
                                             consumer, 1) };
    std::future<void> consumer2 { std::async(std::launch::async,
                                             consumer, 2) };

    return 0;
}

