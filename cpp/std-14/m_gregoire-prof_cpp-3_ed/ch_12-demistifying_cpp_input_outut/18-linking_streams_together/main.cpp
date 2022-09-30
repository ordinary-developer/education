#include <iostream>
#include <fstream>
#include <string>

auto main() -> int {
    std::ifstream inFile("input.txt"); // input.txt must exist
    std::ofstream outFile("output.txt");
    inFile.tie(&outFile);
    outFile << "Hello there!";
    std::string nextToken;
    inFile >> nextToken;

    return 0;
}
