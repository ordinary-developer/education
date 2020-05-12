#include "StringSpreadsheetCell.hpp"

StringSpreadsheetCell::StringSpreadsheetCell() 
    : mValue("#NOVALUE") { }

void StringSpreadsheetCell::set(const std::string& inString) {
    mValue = inString;
}

std::string StringSpreadsheetCell::getString() const {
    return mValue;
}
