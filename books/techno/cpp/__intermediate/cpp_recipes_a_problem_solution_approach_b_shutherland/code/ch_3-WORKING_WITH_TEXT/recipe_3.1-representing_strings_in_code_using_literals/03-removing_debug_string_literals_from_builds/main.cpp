#include <iostream>
#include <string>


#define DEBUG_STRING_LITERALS !NDEBUG

namespace {
#if DEBUG_STRING_LITERALS
    using StringLiteral = std::string;
#endif

    StringLiteral STRING{ "This is a String!" };
}


int main() {
    std::cout << STRING << std::endl;

    return 0;
}
