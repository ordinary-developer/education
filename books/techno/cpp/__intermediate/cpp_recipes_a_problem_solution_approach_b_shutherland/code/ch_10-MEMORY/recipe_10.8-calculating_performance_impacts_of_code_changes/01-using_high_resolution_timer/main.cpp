#include <chrono>
#include <iostream>


void RunTest(unsigned int numberIterations) {
    auto start = std::chrono::high_resolution_clock::now();

    for (unsigned int i{ 0 }; i < numberIterations; ++i) 
        unsigned int squared{ i * i * i };

    auto end = std::chrono::high_resolution_clock::now();
    auto difference = end - start;

    std::cout
        << "Time taken: "
        << std::chrono::duration_cast<std::chrono::microseconds>(difference).count()
        << " microseconds!" << std::endl;
}

int main() {
    RunTest(10000000);
    RunTest(100000000);
    RunTest(1000000000);

    return 0;
}
