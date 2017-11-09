#include <iostream>
#include <string>

int main() {
    std::cout << "What is your name? ";
    std::string name{ };
    std::cin >> name;

    std::cout << "Hello, " << name << ", how are you? ";
    std::string response{ };
    std::cin >> response;
    
    std::cout << "Good-bye, " << name << ". I'm glad you feel "
              << response << "\n";

    return 0;
}
