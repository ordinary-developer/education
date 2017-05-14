#include <iostream>

unsigned int counter{ 0 };

void IncreaseCounter() {
    counter += 10;
    std::cout << "counter is " << counter << std::endl;
}

int main(int argc, char* argv[]) {
    counter += 5;
    std::cout << "counter is " << counter << std::endl;
    IncreaseCounter();

    return 0;
}
