#include <iostream>
#include <string>

namespace {
    const char* const STRING{ "this is a string" };
    char* EDIT_STRING{ "Attempt to Edit" };
}

int main() {
    std::cout << STRING << std::endl;

    std::cout << EDIT_STRING << std::endl;
    // here a runtime error will be
    EDIT_STRING[0] = 'a';
    std::cout << EDIT_STRING << std::endl;

    return 0;
}
