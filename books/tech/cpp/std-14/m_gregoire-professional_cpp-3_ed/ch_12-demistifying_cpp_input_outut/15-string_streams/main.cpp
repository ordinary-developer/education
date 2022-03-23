#include <iostream>
#include <sstream>

auto main() -> int {
    std::cout << "Enter tokens. Ctrl+D (Unix) or Ctrl+Z (Windows) to end." 
              << std::endl;
    std::ostringstream outStream;

    while(std::cin) {
        std::string nextToken;

        std::cout << "Next token: ";
        std::cin >> nextToken;
        if ("done" == nextToken) {
            break;
        }
        outStream << nextToken << "\t";
    }

    std::cout << "The end result is: " << outStream.str();

    return 0;
}
