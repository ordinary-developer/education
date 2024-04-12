#include <chrono>
#include <iostream>

void do_something() {
    for (unsigned int i = 0; i < 10; ++i) {
        std::cout << "some text" << std::endl;
    }
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    do_something();
    auto stop = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed_seconds = stop - start;
    std::cout << "do_something() took " 
              << elapsed_seconds.count()
              << " seconds" 
              << std::endl;

    return 0;
}
