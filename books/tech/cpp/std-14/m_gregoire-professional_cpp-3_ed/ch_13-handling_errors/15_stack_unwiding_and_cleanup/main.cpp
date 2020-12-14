#include <fstream>
#include <iostream>
#include <stdexcept>


void funcOne();
void funcTwo();

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

void funcOne() {
    std::string str1;
    std::string* str2 = new std::string();
    funcTwo();
    delete str2;
}

void funcTwo() {
    std::ifstream istr;
    istr.open("filename");
    throw std::exception();
    istr.close();
}
