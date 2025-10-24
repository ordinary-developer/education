#include <mutex>
#include <string>
#include <iostream>
#include <future>

std::mutex printMutex{};

void print(std::string const& str) {
    std::lock_guard<std::mutex> lock{ printMutex };
    for (char c : str) 
        std::cout.put(c);

    std::cout << std::endl;
}

int main() {
    std::future<void> f1{ std::async(std::launch::async,
                                     print,
                                     "Hello from the first thread") };
    std::future<void> f2{ std::async(std::launch::async,
                                     print,
                                     "Hello from the second thread") };
    print("Hello from the main thread");

    return 0;
}
