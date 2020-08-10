#include <iostream>
#include <memory>
#include <string>
#include <cctype>


bool is_not_space(char const ch) {
    return not std::isspace(static_cast<unsigned char>(ch));
}

std::string trim_left(std::string str) {
    str.erase(str.begin(), 
          std::find_if(str.begin(), str.end(), is_not_space));
    return str;
}

std::string trim_right(std::string str) {
    str.erase(
        std::find_if(str.rbegin(), str.rend(), is_not_space).base(),
        str.end());
    return str;
}

std::string trim(std::string str) {
    return trim_left(trim_right(std::move(str)));
}


int main() {
    std::cout << "[" << trim("   abc   ") << "]" << std::endl;

    return 0;
}
