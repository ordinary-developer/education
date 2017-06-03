#include "SpreadsheetCell.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>


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

// [ARITHMETIC OPERATORS]
SpreadsheetCell SpreadsheetCell::operator-() const {
    SpreadsheetCell newCell(*this);
    newCell.set(-mValue);
    return newCell;
}

SpreadsheetCell& SpreadsheetCell::operator++() {
    set(mValue + 1);
    return *this;
}

SpreadsheetCell SpreadsheetCell::operator++(int) {
    SpreadsheetCell oldCell(*this);
    set(mValue + 1);
    return oldCell;
}

SpreadsheetCell& SpreadsheetCell::operator--() {
    set(mValue - 1);
    return *this;
}

SpreadsheetCell SpreadsheetCell::operator--(int) {
    SpreadsheetCell oldCell(*this);
    set(mValue - 1);
    return oldCell;
}

// other operators
SpreadsheetCell& SpreadsheetCell::operator += (const SpreadsheetCell& rhs) {
    set(mValue + rhs.mValue);
    return *this;
}

SpreadsheetCell& SpreadsheetCell::operator -= (const SpreadsheetCell& rhs) {
    set(mValue - rhs.mValue);
    return *this;
}

SpreadsheetCell& SpreadsheetCell::operator *= (const SpreadsheetCell& rhs) {
    set(mValue * rhs.mValue);
    return *this;
}

SpreadsheetCell& SpreadsheetCell::operator /= (const SpreadsheetCell& rhs) {
    if (0 == rhs.mValue) {
        throw new std::invalid_argument("Divide by zero");
    }
    set(mValue / rhs.mValue);
    return *this;
}
//friend functions
SpreadsheetCell operator + (const SpreadsheetCell& lhs, const SpreadsheetCell& rhs) {
    SpreadsheetCell newCell;
    newCell.set(lhs.mValue + rhs.mValue);
    return newCell;
}

SpreadsheetCell operator - (const SpreadsheetCell& lhs, const SpreadsheetCell& rhs) {
    SpreadsheetCell newCell;
    newCell.set(lhs.mValue - rhs.mValue);
    return newCell;
}

SpreadsheetCell operator * (const SpreadsheetCell& lhs, const SpreadsheetCell& rhs) {
    SpreadsheetCell newCell;
    newCell.set(lhs.mValue * rhs.mValue);
    return newCell;
}

SpreadsheetCell operator / (const SpreadsheetCell& lhs, const SpreadsheetCell& rhs) {
    if (0 == rhs.mValue) {
        throw std::invalid_argument("Divide by zero.");
    }
    SpreadsheetCell newCell;
    newCell.set(lhs.mValue / rhs.mValue);
    return newCell;
}
