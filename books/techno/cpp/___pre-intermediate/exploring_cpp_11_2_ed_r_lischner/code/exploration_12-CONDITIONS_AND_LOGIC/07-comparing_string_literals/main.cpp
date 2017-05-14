#include <string>
#include <iostream>


int main() {
    if ("help" > "hello")
        std::cout << "very bad\n";
    if (std::string("help") > "help")
        std::cout << "this works\n";
    if ("help" > std::string("hello"))
        std::cout << "this also works\n";
    if (std::string("help") > std::string("hello"))
        std::cout << "and this works\n";

    return 0;
}
