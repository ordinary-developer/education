#include <random>
#include <iostream>
namespace example1 {
void run() {
    std::random_device random{};
    std::cout << "Entropy: " << random.entropy() << std::endl;
    std::cout << "Min value: " << random.min() << ", "
              << "Max value: " << random.max() << std::endl;
    std::cout << "Random number: " << random() << std::endl;
}

}


int main() {
    example1::run();

    return 0;
}

