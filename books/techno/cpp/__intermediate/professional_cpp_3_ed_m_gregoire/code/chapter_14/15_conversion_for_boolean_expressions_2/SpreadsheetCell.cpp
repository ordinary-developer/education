#include "SpreadsheetCell.hpp"

#include <iostream>
#include <sstream>


SpreadsheetCell::SpreadsheetCell() 
    : mValue(0) 
{
}

void SpreadsheetCell::set(double inValue) {
    mValue = inValue;
    mString = SpreadsheetCell::doubleToString(mValue);
}

void SpreadsheetCell::set(const std::string& inString) {
    mValue = SpreadsheetCell::stringToDouble(inString);
    mString = inString;
}

std::string SpreadsheetCell::doubleToString(double inValue) {
    std::ostringstream ostr;

    ostr << inValue;
    return ostr.str();
}

double SpreadsheetCell::stringToDouble(const std::string& inString) {
    double temp;

    std::istringstream istr(inString);
    istr >> temp;
    if (istr.fail() || !istr.eof()) {
        return 0;
    }

    return temp;
}

SpreadsheetCell::SpreadsheetCell(double initialValue) {
    set(initialValue);
}

SpreadsheetCell::SpreadsheetCell(const std::string& initialValue) {
    set(initialValue);
}

SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell& src) {
    mValue = src.mValue;
    mString = src.mString;
    mNumAccess = src.mNumAccess;
} 

SpreadsheetCell& SpreadsheetCell::operator=(const SpreadsheetCell& rhs) {
    if (&rhs == this) {
        return *this;
    }
    mValue = rhs.mValue;
    mString = rhs.mString;
    mNumAccess = rhs.mNumAccess;
    return *this;
}

SpreadsheetCell::operator std::string() const {
    return mString;
}

SpreadsheetCell::operator double() const {
    return mValue;
}
