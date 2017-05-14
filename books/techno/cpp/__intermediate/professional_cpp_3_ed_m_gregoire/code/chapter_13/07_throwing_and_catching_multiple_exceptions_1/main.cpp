#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

void readIntegerFile(const std::string& fileName, std::vector<int>& dest) {
    std::ifstream istr;
    int temp;

    istr.open(fileName.c_str());
    if (istr.fail()) {
        throw std::runtime_error("Unable to open the file.");
    }

    while (istr >> temp) {
        dest.push_back(temp);
    }

    if (!istr.eof()) {
        throw std::runtime_error("Error reading the file.");
    }
}

auto main() -> int {
    std::vector<int> myInts;
    const std::string fileName = "IntegerFile.txt";

    try {
        readIntegerFile(fileName, myInts);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    for (const auto element: myInts) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
