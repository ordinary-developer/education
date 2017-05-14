#include <iomanip>
#include <iostream>
#include <locale>
#include <string>


#include "ioflags.hpp"

void print(int c, std::string const& name, std::locale loc) {
    std::cout << "\\x" << std::setw(2) << (c & 0xff) 
              << " is " << name << " in " << loc.name() << '\n';
}

void test(char c, std::locale loc) {
    ioflags save{ std::cout };
    std::ctype<char> const& ctype{ std::use_facet<std::ctype<char>>(loc) };

    std::cout << std::hex << std::setfill('0');
    if (ctype.is(std::ctype_base::alnum, c))
        print(c, "alphanumeric", loc);
    else if (ctype.is(std::ctype_base::cntrl, c))
        print(c, "control", loc);
    else if (ctype.is(std::ctype_base::punct, c))
        print(c, "puntuation", loc);
    else
        print(c, "none of the above", loc);
}

int main() {
    char c{ '\xd7' };

    // here runtime error will be
    //test(c, std::locale{ "en_US.iso88591" });
    //test(c, std::locale{ "ru_RU.iso88595" });
    //test(c, std::locale{ "el_GR.iso88597" });
    //test(c, std::locale{ "he_IL.iso88598" });
    test(c, std::locale{});
    test(c, std::locale{ "" });

    return 0;
}
