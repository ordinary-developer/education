#include <fstream>
#include <iostream>
#include <vector>
#include <string>

void readIntegerFile(const std::string& fileName, std::vector<int>& dest) {
    std::ifstream istr;
    int temp;

    istr.open(fileName.c_str());

    while (istr >> temp) {
        dest.push_back(temp);
    }
}

auto main() -> int {
    std::vector<int> myInts;
    const std::string fileName = "IntegerFile.txt";

    readIntegerFile(fileName, myInts);

    for (const auto element: myInts) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
