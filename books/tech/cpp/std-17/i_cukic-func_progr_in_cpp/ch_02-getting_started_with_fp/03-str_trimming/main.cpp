#include <algorithm>
#include <memory>
#include <string>
#include <cassert>
#include <cctype>
namespace test {

bool isNotSpace(const char ch) {
    return not std::isspace(static_cast<unsigned char>(ch));
}

std::string trimLeft(std::string s) {
    s.erase(std::begin(s), 
        std::find_if(std::begin(s), std::end(s), isNotSpace));

    return s;
}

std::string trimRight(std::string s) {
    s.erase(std::find_if(std::rbegin(s), std::rend(s), isNotSpace).base(),
        std::end(s));

    return s;
}

std::string trim(std::string s) {
    return trimLeft(trimRight(std::move(s)));
}

void run() {
    assert("abc" == trimLeft("   abc"));
    assert("abc" == trimRight("abc   "));
    assert("abc" == trim("   abc   "));
}

} // test


#include <iostream>
int main() {
    std::cout << "test => [ok]" << std::endl; test::run(); std::cout << std::endl;

    return 0;
}
