#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <exception>


void readIntegerFile(const std::string& fileName, std::vector<int>& dest) {
    std::ifstream istr;
    int temp;

    istr.open(fileName.c_str());
    if (istr.fail()) {
        throw "Unable to open file";
    }

    while (istr >> temp) {
        dest.push_back(temp);
    }
}

auto main() -> int {
    std::vector<int> myInts;
    const std::string fileName = "IntegerFile.txt";

    try {
        readIntegerFile(fileName, myInts);
    }
    catch (const char* e) {
        std::cerr << e << std::endl;
        return 1;
    }

    for (const auto element: myInts) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
