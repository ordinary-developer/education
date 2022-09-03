#include <iostream>
#include <thread>
#include <utility>


class ScopedThread {
    std::thread t_;
public:
    explicit ScopedThread(std::thread t) : t_{ std::move(t) } {
        if (not t_.joinable())
            throw std::logic_error("no thread");
    }

    ~ScopedThread() { t_.join(); }

    ScopedThread(ScopedThread &) = delete;
    ScopedThread & operator = (ScopedThread const &) = delete;
};


int main() {
    ScopedThread {
        std::thread{ [] { std::cout << std::this_thread::get_id() << std::endl; } } 
    };
}
