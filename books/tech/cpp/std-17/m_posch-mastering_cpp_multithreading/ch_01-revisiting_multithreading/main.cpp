#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <random>

std::mutex valuesMutex{};
std::mutex coutMutex{};
std::vector<int> values{};

int generateRandomIntNumber(int const min, int const max) {
    static thread_local std::mt19937 generator{
        std::hash<std::thread::id>{}(std::this_thread::get_id())};
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
    return 42;
}

void threadFunction(int threadID) {
    coutMutex.lock();
    std::cout << "Starting thread " << threadID << ".\n";
    coutMutex.unlock();

    valuesMutex.lock();
    int value = values[0];
    valuesMutex.unlock();

    int randomValue = generateRandomIntNumber(0, 10);
    value += randomValue;

    coutMutex.lock();
    std::cout << "Thread " << threadID << " adding " << randomValue 
              << ". New value: " << value << ".\n";
    coutMutex.unlock();

    valuesMutex.lock();
    values.push_back(value);
    valuesMutex.unlock();
}

int main() {
    values.push_back(42);

    std::thread thread1(threadFunction, 1);
    std::thread thread2(threadFunction, 2);
    std::thread thread3(threadFunction, 3);
    std::thread thread4(threadFunction, 4);

    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();

    std::cout << "Input: " << values[0] 
              << ", Result 1: " << values[1]
              << ", Result 2: " << values[2]
              << ", Result 3: " << values[3] << "\n";

    return 1;
}
