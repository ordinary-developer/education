#include <thread>
#include <future>
#include <iostream>

int doAsyncWork() {
    std::cout << "asynchrounous calling" << std::endl;

    return 42;
}

int main() {
    auto future = std::async(doAsyncWork);
    future.get();

    return 0;
}
