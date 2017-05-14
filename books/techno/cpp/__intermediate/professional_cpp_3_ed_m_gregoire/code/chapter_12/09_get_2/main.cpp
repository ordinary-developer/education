#include <iostream>
#include <string>

std::string readName(std::istream& inStream) {
    std::string name;
    char next;
    while (inStream.get(next)) {
        name += next;
    }
    return name;
}

auto main() -> int {
    std::cout << "Reading a name from cin. You can usually close cin "
              << "with Ctrl-D (unix) or Ctrl-Z (Windows)" << std::endl;
    std::string theName = readName(std::cin);
    std::cout << "The name is \"" << theName << "\"" << std::endl;

    return 0;
}
