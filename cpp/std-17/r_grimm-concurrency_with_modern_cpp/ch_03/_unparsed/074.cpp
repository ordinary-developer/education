#include <atomic>
#include <chrono>
#include <iostream>
#include <future>
#include <mutex>
#include <thread>

constexpr auto tenMill = 1'000'000;

class MySingleton {
public:
    static MySingleton * getInstance() {
        MySingleton * sin = instance.load();
        if (not sin) {
            std::lock_guard<std::mutex> _{myMutex};
            sin = instance.load(std::memory_order_relaxed);
            if (not sin) {
                sin = new MySingleton{};
                instance.store(sin);
            }
        }

        volatile int dummy{};
        return sin;
    }

private:
    MySingleton() = default;
    ~MySingleton() = default;
    MySingleton(const MySingleton &) = delete;
    MySingleton & operator = (const MySingleton &) = delete;

    static std::atomic<MySingleton*> instance;
    static std::mutex myMutex;    
};

std::atomic<MySingleton*> MySingleton::instance{};
std::mutex MySingleton::myMutex;

std::chrono::duration<double> getTime() {
    auto begin = std::chrono::system_clock::now();
    for (std::size_t i = 0; i < tenMill; ++i) {
        MySingleton::getInstance();
    }
    return std::chrono::system_clock::now() - begin;
}

int main() {
    auto fut1 = std::async(std::launch::async, getTime);
    auto fut2 = std::async(std::launch::async, getTime);
    auto fut3 = std::async(std::launch::async, getTime);
    auto fut4 = std::async(std::launch::async, getTime);

    const auto total = fut1.get() + fut2.get() + fut3.get() + fut4.get();

    std::cout << total.count() << std::endl;
}
