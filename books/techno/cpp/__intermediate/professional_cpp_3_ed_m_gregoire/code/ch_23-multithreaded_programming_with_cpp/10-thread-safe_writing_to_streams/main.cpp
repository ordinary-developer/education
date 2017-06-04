#include <thread>
#include <mutex>
#include <iostream>
#include <vector>

class Counter {
    public:
        Counter(int id, int iterationCount)
            : id_{id}, iterationCount_{iterationCount} { }

        void operator()() const {
            for (int i{0}; i < iterationCount_; ++i) {
                std::lock_guard<std::mutex> lock{mutex_};
                std::cout << "Counter " << id_ << " has value " << i
                          << std::endl;
            }
        }

    private:
        static std::mutex mutex_;

        int id_;
        int iterationCount_;
};
std::mutex Counter::mutex_{};

int main() {
    std::vector<std::thread> threads(10);
    int i{0};

    for (auto& thread : threads) {
        thread = std::thread{ Counter{i, i} }; 
        ++i;
    }

    for (auto& thread : threads)
        thread.join();

    return 0;
}
