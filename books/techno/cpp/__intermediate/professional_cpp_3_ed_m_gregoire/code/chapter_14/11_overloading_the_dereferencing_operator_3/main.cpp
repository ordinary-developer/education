#include "Pointer.hpp"
#include "SpreadsheetCell.hpp"

#include <iostream>

auto main() -> int {
    SpreadsheetCell myCell1;
    double (SpreadsheetCell::*methodPtr) () const = &SpreadsheetCell::getValue;
    std::cout << (myCell1.*methodPtr)() << std::endl;

    SpreadsheetCell* myCell2 = new SpreadsheetCell();
    // we already have the declaration
    // double (SpreadsheetCell::*methodPtr)() const = &SpreadsheetCell::getValue;
    std::cout << (myCell2->*methodPtr)() << std::endl;

    return 0;
}
