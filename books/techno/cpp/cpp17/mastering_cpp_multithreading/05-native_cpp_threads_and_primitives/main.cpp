#include <thread>
#include <iostream>
namespace example01 {

void worker() {
    std::cout << "working" << std::endl;
}

void run() {
    std::thread t(worker);
    t.join();
}
}

int main() {
    example01::run();

    return 0;
}
