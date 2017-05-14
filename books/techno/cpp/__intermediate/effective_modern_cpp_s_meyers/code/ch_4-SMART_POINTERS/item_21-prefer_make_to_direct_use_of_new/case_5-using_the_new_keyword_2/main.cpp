#include <memory>
#include <iostream>
#include <vector>

int main() {
    // will create a vector of size 10 with all values set to 20
    auto upv = std::make_unique<std::vector<int>>(10, 20);
    auto spw = std::make_shared<std::vector<int>>(10, 20);
    std::cout << upv->size() << std::endl;
    std::cout << spw->size() << std::endl;

    // to create using initializer list
    auto initList = { 10, 20 };
    auto spv = std::make_shared<std::vector<int>>(initList);
    std::cout << spv->size() << std::endl;

    return 0;
}
