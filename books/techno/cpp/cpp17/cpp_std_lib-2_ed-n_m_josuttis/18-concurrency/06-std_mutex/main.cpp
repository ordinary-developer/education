#include <future>
#include <mutex>
#include <string>
#include <iostream>
namespace workspace {
    
std::mutex printMutex{};
    
void print(std::string const& s) {
    std::lock_guard<std::mutex> lock{ printMutex };
    for (char c : s) 
        std::cout.put(c);
    std::cout << std::endl; 
}
    
void run() {
    auto f1 = std::async(std::launch::async,
        print, "Hello from the first thread");
    auto f2 = std::async(std::launch::async,
        print, "Hello from the second thread");
    print("Hello from the main thread");
}
} // workspace


int main() {
    workspace::run();
    
    return 0;
}
