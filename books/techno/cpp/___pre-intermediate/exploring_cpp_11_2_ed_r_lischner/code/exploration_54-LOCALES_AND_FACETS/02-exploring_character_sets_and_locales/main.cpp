#include <iomanip>
#include <iostream>
#include <locale>
#include <ostream>
#include <string>


#include "ioflags.hpp"

void print(int c, std::string const& name, std::locale loc) {
    std::cout << "\\x" << std::setw(2) << (c & 0xff) 
              << " is " << name << " in " << loc.name() << '\n';
}

void test(char c, std::locale loc) {
    ioflags save{ std::cout };
    std::cout << std::hex << std::setfill('0');
    if (std::isalnum(c, loc)) 
        print(c, "alphanumeric", loc);
    else if (std::iscntrl(c, loc))
        print(c, "control", loc);
    else if (std::ispunct(c, loc))
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
