#include <chrono>
#include <iostream>

constexpr auto tenMill = 1'000'000;

class MySingleton {
public:
    static MySingleton & getInstance() {
        static MySingleton instance;
        volatile int dummy{};
        return instance;
    }

private:
    MySingleton() = default;
    ~MySingleton() = default;
    MySingleton(const MySingleton &) = delete;
    MySingleton & operator = (const MySingleton &) = delete;
};

int main() {
    constexpr auto fourtyMill = 4 * tenMill;

    const auto begin = std::chrono::system_clock::now();
    for (std::size_t i = 0; i < fourtyMill; ++i) {
        MySingleton::getInstance();
    }
    const auto end = std::chrono::system_clock::now() - begin;

    std::cout << std::chrono::duration<double>(end).count() << std::endl;
}
