#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex gMut;

class Sleeper {
    public:
        explicit Sleeper(int & i) : i_{i} {}

        void operator () (int k) {
            for (unsigned int j = 0; j <= 5; ++j) {
                std::this_thread::sleep_for(std::chrono::milliseconds{100});

                {
                    std::lock_guard<std::mutex> _{gMut};
                    i_ += k;
                }
            }

            std::cout << std::this_thread::get_id() << std::endl;
        }

    private:
        int & i_;
};

int main() {
    std::cout << std::endl;

    int valSleeper = 1000;
    std::thread t{Sleeper(valSleeper), 5};
    if (t.joinable())
        t.join();

    std::cout << "valSleeper = " << valSleeper << std::endl;
}
