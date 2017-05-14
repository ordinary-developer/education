#include <iostream>
#include <thread>


int main() {
    unsigned int const numberOfProcessors =
        std::thread::hardware_concurrency();

    std::cout << "This system can run " << numberOfProcessors
              << " concurrent tasks" << std::endl;

    return 0;
}
