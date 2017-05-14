#include "SpreadsheetCell.hpp"
#include "StringSpreadsheetCell.hpp"
#include "DoubleSpreadsheetCell.hpp"

#include <vector>
#include <memory>
#include <iostream>


auto main() -> int {
    SpreadsheetCell* ptr = nullptr;

    std::vector<std::unique_ptr<SpreadsheetCell>> cellArray;
    cellArray.push_back(std::make_unique<StringSpreadsheetCell>());
    cellArray.push_back(std::make_unique<StringSpreadsheetCell>());
    cellArray.push_back(std::make_unique<DoubleSpreadsheetCell>());
    cellArray[0]->set("hello");
    cellArray[1]->set("10");
    cellArray[2]->set("18");

    std::cout << "Vector values are [" << cellArray[0]->getString() << ","
                                       << cellArray[1]->getString() << ","
                                       << cellArray[2]->getString() << "]"
                                       << std::endl;

    return 0;
}
