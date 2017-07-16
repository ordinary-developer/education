#include "types.hpp"

#include <string>

MyInt MyInt::operator+(MyString const& rhs) const {
    return MyInt(value_ + std::stoi(rhs.getString()));
}

MyString MyString::operator+(MyInt const& rhs) const {
    std::string str{ string_ };
    str.append(std::to_string(rhs.getInt()));
    return str;
}

