#include <ctime>
#include <chrono>
#include <iostream>


int main() {
    auto currentTimePoint = std::chrono::system_clock::now();
    auto currentTime = 
        std::chrono::system_clock::to_time_t(currentTimePoint);
    auto timeText = ctime(&currentTime);

    std::cout << timeText << std::endl;

    return 0;
}
