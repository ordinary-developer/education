#include <ctime>
#include <chrono>
#include <iostream>
#include <thread>

using namespace std::literals;

int main() {
    auto startTimePoint = std::chrono::system_clock::now();
    std::this_thread::sleep_for(5s);
    auto endTimePoint = std::chrono::system_clock::now();
    auto timeTaken = 
        std::chrono::duration_cast<std::chrono::milliseconds>(
                endTimePoint - startTimePoint);
    std::cout << "Time Taken: " << timeTaken.count() << std::endl;

    return 0;
}

