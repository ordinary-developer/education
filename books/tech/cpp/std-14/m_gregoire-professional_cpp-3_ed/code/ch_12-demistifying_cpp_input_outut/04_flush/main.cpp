#include <iostream>


auto main() -> int {
    std::cout << "abc";
    std::cout.flush();
    std::cout << "def";
    std::cout << std::endl;

    return 0;
}
