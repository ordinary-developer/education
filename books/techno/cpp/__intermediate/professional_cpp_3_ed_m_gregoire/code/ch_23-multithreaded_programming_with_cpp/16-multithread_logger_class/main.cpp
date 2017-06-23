#include "logger.hpp"

#include <string>
#include <sstream>
#include <vector>
#include <thread>

void logSomeMessages(int id, Logger& logger) {
    for (int i{0}; i < 10; ++i) {
        std::stringstream ss{};
        ss << "Log entry " << i << " from thread " << id;
        logger.log(ss.str());
    }
}

int main() {
    Logger logger{};
    std::vector<std::thread> threads{};
    for (int i{0}; i < 10; ++i) 
        threads.emplace_back(logSomeMessages, i, std::ref(logger));

    for (auto& t : threads) 
        t.join();

    return 0;
}
