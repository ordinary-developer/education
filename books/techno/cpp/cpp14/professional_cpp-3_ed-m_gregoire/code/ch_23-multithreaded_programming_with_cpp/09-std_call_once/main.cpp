#include <mutex>
#include <thread>
#include <iostream>
#include <vector>


std::once_flag gOnceFlag{};
void initializeSharedResources() {
    std::cout << "Shared resources initialized." << std::endl;
}

void processingFunction() {
    std::call_once(gOnceFlag, initializeSharedResources);
    std::cout << "Processing" << std::endl;
}

int main() {
    std::vector<std::thread> threads(3);
    for (auto& t : threads)
        t = std::thread{ processingFunction };
    for (auto& t : threads)
        t.join();

    return 0;
}

