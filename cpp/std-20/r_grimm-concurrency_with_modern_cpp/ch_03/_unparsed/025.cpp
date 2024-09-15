#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex coutMutex;

class Worker {
public:
    explicit Worker(const std::string & name) : name_{name} {}

    void operator()() {
        for (int i = 1; i <= 3; ++i) {
            std::this_thread::sleep_for(std::chrono::milliseconds{200});

            coutMutex.lock();
            std::cout << name_ << ": " << "Work" << i << " done !!!" << std::endl;
            coutMutex.unlock();
        }
    }

private:
    const std::string name_;
};

int main() {
    std::cout << std::endl;

    std::cout << "Boss: Let's start working." << "\n\n";

    std::thread herb = std::thread{ Worker{"Herb"} };
    std::thread andrei = std::thread{ Worker{"  Andrei"} };
    std::thread scott = std::thread{ Worker{"    Scott"} };
    std::thread bjarne = std::thread{ Worker{"      Bjarne"} };
    std::thread bart = std::thread{ Worker{ "        Bart"}};
    std::thread jenne = std::thread{ Worker{ "          Jenne"} };

    if (herb.joinable())
        herb.join();
    if (andrei.joinable())
        andrei.join();
    if (scott.joinable())
        scott.join();
    if (bjarne.joinable())
        bjarne.join();
    if (bart.joinable())
        bart.join();
    if (jenne.joinable())
        jenee.join();

    std::cout << "\n" << "Boss: Let's go home." << std::endl;

    std::cout << std::endl;
}
