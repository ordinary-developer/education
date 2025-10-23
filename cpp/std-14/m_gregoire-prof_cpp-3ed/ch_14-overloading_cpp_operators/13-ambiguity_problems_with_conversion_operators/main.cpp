#include "SpreadsheetCell.hpp"

#include <iostream>


auto main() -> int {
    /*
    SpreadsheetCell cell(1.23);
    std::string str = cell;
    std::cout << str << std::endl;
    double d1 = cell;
    std::cout << d1 << std::endl;

    double d2 = cell + 3.3;
*/
    SpreadsheetCell cell2 = 6.6;
    std::string str2 = cell2;
    double d3 = static_cast<double>(cell2);
    // will not compile with overloading the "+" operator 
    // in the SpreadsheetCell class
    // double d4 = static_cast<double>(cell2 + 3.3);

    return 0;
}
