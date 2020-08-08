#include <iostream>
#include <thread>


void ThreadTask() {
    for (unsigned int i{ 0 }; i < 20; ++i) 
        std::cout << "Output from thread" << std::endl;
}

int main() {
    unsigned int const numberOfProcessors = 
        { std::thread::hardware_concurrency() };
    std::cout << "This system can run " << numberOfProcessors 
              << " concurrent tasks" << std::endl;

    if (numberOfProcessors > 1) {
        std::thread myThread{ ThreadTask };
        std::cout << "Output from main" << std::endl;
        myThread.detach();
    }
    else
        std::cout << "CPU does not have multiple cores" << std::endl;

    return 0;
}
