#include <chrono>
#include <iostream>
#include <future>
#include <mutex>

constexpr auto tenMill = 1'000'000;

std::mutex gMut{};

class MySingleton {
public:
    static MySingleton & getInstance() {
        std::lock_guard<std::mutex> _{gMut};
        if (not instance) {
            instance = new MySingleton{};
        }
        volatile int dummy{};
        return *instance;
    }

private:
    MySingleton() = default;
    ~MySingleton() = default;
    MySingleton(const MySingleton &) = delete;
    MySingleton & operator = (const MySingleton &) = delete;

    static MySingleton * instance;
};

MySingleton * MySingleton::instance = nullptr;

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
