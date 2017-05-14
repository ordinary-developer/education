#include <iostream>
#include <string>


#define DEBUG_STRING_LITERALS !NDEBUG

namespace {
#if DEBUG_STRING_LITERALS
    using StringLiteral = std::string;
#endif

#if DEBUG_STRING_LITERALS
    StringLiteral STRING{ "This is a String!" };
#endif
}


int main() {
#if DEBUG_STRING_LITERALS
    std::cout << STRING << std::endl;
#endif

    return 0;
}
