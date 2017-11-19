#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>
#include <memory>

void funcOne();
void funcTwo();

void funcOne() {
    std::string str1;
    auto str2 = std::make_unique<std::string>("hello");
    funcTwo();
}

void funcTwo() {
    std::ifstream istr;
    istr.open("filename");
    throw std::exception();
    istr.close();
}

auto main() -> int {
    try {
        funcOne();
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught!" << std::endl;
        return 1;
    }

    return 0;
}
