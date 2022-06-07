#include <iostream>
#include <thread>

void counter(int id, int iterationNumber) {
    for (int i{0}; i < iterationNumber; ++i) {
        std::cout << "Counter " << id << " has value ";
        std::cout << i << std::endl;
    }
}

int main() { 
    std::thread t1{ counter, 1, 6 };
    std::thread t2{ counter, 2, 4 };
    t1.join();
    t2.join();

    return 0;
}
