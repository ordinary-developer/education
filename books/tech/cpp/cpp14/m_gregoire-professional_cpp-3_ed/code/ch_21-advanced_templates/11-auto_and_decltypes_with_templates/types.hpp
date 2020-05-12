#pragma once

#include <string>

class MyString;

class MyInt {
    public:
        MyInt(int i) : value_{i} { }

        MyInt operator+(MyString const& rhs) const;

        int getInt() const { return value_; }

    private:
        int value_;
};

class MyString {
    public:
        MyString(std::string const& str) : string_{ str } { }

        MyString operator+(MyInt const& rhs) const;

        std::string const& getString() const { return string_; }

    private:
        std::string string_;
};
