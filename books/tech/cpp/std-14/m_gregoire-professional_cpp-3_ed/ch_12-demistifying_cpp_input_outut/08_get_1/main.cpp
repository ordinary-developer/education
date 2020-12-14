#include <iostream>
#include <string>


std::string readName(std::istream& inStream) {
    std::string name;
    while (!inStream.fail()) {
        int next = inStream.get();
        if (std::char_traits<char>::eof() == next) {
            break;
        }
        name += static_cast<char>(next);
    }
    return name;
}

auto main() -> int {
    std::cout << "Reading a name from cin. You can usually close cin "
              << "with Ctrl-D or Ctrl-Z" << std::endl;
    std::string theName = readName(std::cin);
    std::cout << "The name is \"" << theName << "\"" << std::endl;

    return 0;
}
