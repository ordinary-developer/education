#include <thread>
#include <iostream>

int main() {
    int id{1};
    int iterationCount{5};
    std::thread t1([id, iterationCount] {
        for (int i{0}; i < iterationCount; ++i) {
            std::cout << "Counter " << id << " has value ";
            std::cout << i << std::endl;
        }
    });
    t1.join();

    return 0;
}
