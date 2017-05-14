#include "Pointer.hpp"
#include "SpreadsheetCell.hpp"

#include <iostream>

auto main() -> int {
    Pointer<int> smartInt(new int);
    *smartInt = 5;
    std::cout << *smartInt << std::endl;

    Pointer<SpreadsheetCell> smartCell(new SpreadsheetCell);
    smartCell->set(5);
    std::cout << smartCell->getValue() << std::endl;

    return 0;
}
