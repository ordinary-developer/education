#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>


std::mutex coutMutex;

class Worker {
    public:
        Worker(std::string n) : name(n) {};

        void operator () () {
            for (int i = 1; i <= 3; ++i) {
                std::this_thread::sleep_for(std::chrono::milliseconds(200));

                coutMutex.lock();
                std::cout << name << ": " << "Work " << i << " done !!!" << '\n';
                coutMutex.unlock();
            }
        }

    private:
        std::string name;
};


int main() {
    std::cout << '\n';

    std::cout << "Boss: Let's start working." << "\n\n";

    std::thread herb = std::thread(Worker("Herb"));
    std::thread andrei = std::thread(Worker(" Andrei"));
    std::thread scott = std::thread(Worker("  Scott"));
    std::thread bjarne = std::thread(Worker("   Bjarne"));
    std::thread bart = std::thread(Worker("    Bart"));
    std::thread jenne = std::thread(Worker("     Jenne"));

    herb.join();
    andrei.join();
    scott.join();
    bjarne.join();
    bart.join();
    jenne.join();

    std::cout << "\n" << "Boss: Let's go home." << '\n';

    std::cout << '\n';
}
