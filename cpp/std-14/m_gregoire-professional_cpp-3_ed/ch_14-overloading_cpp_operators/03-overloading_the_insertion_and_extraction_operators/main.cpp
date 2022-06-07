#include "SpreadsheetCell.hpp"

#include <iostream>


auto main() -> int {
    int number = 0;
    std::cout << "The number is " << number << std::endl;
    std::string str;
    std::cin >> number >> str;
    std::cout << number << std::endl;
    std::cout << str << std::endl;

    SpreadsheetCell myCell, anotherCell, aThirdCell;
    std::cin >> myCell >> anotherCell >> aThirdCell;
    std::cout << myCell << " " << anotherCell << " " << aThirdCell << std::endl;

    operator >> (operator >> (operator >> (std::cin, myCell), anotherCell), aThirdCell);
    std::cout << myCell << " " << anotherCell << " " << aThirdCell << std::endl;

    return 0;
}
