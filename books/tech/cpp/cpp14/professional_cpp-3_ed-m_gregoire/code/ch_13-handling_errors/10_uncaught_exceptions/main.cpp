#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <exception>


void readIntegerFile(const std::string& fileName, std::vector<int>& dest) {
    std::ifstream istr;
    int temp;

    istr.open(fileName.c_str());
    if (istr.fail()) {
        throw std::invalid_argument("Unable to open the file.");
    }

    while (istr >> temp) {
        dest.push_back(temp);
    }

    if (!istr.eof()) {
        throw std::runtime_error("Error reading the file.");
    }
}

void myTerminate() {
    std::cout << "Uncaught exception!" << std::endl;
    exit(1);
}

auto main() -> int {
    std::vector<int> myInts;
    const std::string fileName = "IntegerFile.txt";

    std::set_terminate(myTerminate);

    readIntegerFile(fileName, myInts);

    for (const auto element: myInts) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
