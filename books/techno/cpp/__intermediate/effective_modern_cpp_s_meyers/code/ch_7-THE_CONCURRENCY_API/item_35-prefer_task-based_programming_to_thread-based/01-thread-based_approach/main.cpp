#include <thread>
#include <iostream>

int doAsyncWork() { 
    std::cout << "asynchronous calling" << std::endl;

    return 42;
}


int main() {
    std::thread t(doAsyncWork);
    t.join();

    return 0;
}


