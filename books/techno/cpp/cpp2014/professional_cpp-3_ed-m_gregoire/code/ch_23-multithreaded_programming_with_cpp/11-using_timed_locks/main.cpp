#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>

class Counter {
    public:
        Counter(int id, int iterationCount)
            : id_{id}, iterationCount_{iterationCount} { }

        void operator()() const {
            for (int i{0}; i < iterationCount_; ++i) {
                std::unique_lock<std::timed_mutex> 
                    lock{ timedMutex_,
                            std::chrono::milliseconds{200} };
                if (lock) {
                    std::cout << "Counter " << id_ << " has value " << i
                              << std::endl;
                }
                else { /* Lock not acquired in 200 ms*/ }
            }
        }
    private:
        static std::timed_mutex timedMutex_;
        int id_;
        int iterationCount_;
};
std::timed_mutex Counter::timedMutex_{};

int main() {
    std::vector<std::thread> threads(10);
    int i{0};

    for (auto& thread: threads) {
        thread = std::thread{ Counter{i, i} };
        ++i;
    }

    for (auto& thread: threads)
        thread.join();

    return 0;
}
