#include <iostream>
#include <ctime>

int getRandom(int min, int max) {
    return (rand() % static_cast<int>(max + 1 - min)) + min;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    std::cout << rand() << std::endl;

    std::cout << getRandom(5, 10) << std::endl;

    return 0;
}

