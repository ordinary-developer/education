#include "DoubleSpreadsheetCell.hpp"

#include <limits>
#include <iostream>
#include <sstream>


DoubleSpreadsheetCell::DoubleSpreadsheetCell() 
    : mValue(std::numeric_limits<double>::quiet_NaN())
{
}

void DoubleSpreadsheetCell::set(double inDouble) {
    mValue = inDouble;
}

void DoubleSpreadsheetCell::set(const std::string& inString) {
    mValue = DoubleSpreadsheetCell::stringToDouble(inString);
}

std::string DoubleSpreadsheetCell::getString() const {
    return DoubleSpreadsheetCell::doubleToString(mValue);
}

std::string DoubleSpreadsheetCell::doubleToString(double inValue) {
    std::ostringstream outputStringStream;
    outputStringStream << inValue;
    return outputStringStream.str();
}

double DoubleSpreadsheetCell::stringToDouble(const std::string& inValue) {
    double temp;
    std::istringstream inputStringStream(inValue);
    inputStringStream >> temp;
    if (inputStringStream.fail() || !inputStringStream.eof()) {
        return 0;
    }
    return temp;
}
