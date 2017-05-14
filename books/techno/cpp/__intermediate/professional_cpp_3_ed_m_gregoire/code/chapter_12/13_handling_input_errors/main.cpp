#include <iostream>
#include <string>

auto main() -> int {
    std::cout << "Enter numbers on separte lines to add. "
              << "Use Ctrl+D to finish (Ctrl+Z in Windows). " << std::endl;
    int sum = 0;

    if (!std::cin.good()) {
        std::cerr << "Standard input is in a bad state!" << std::endl;
        return 1;
    }

    int number;
    while (!std::cin.bad()) {
        std::cin >> number;
        if (std::cin.good()) {
            sum += number;
        }
        else if (std::cin.eof()) {
            break;
        }
        else if (std::cin.fail()) {
            std::cin.clear();
            std::string badToken;
            std::cin >> badToken;
            std::cerr << "WARNING: Bad input encountered: " << badToken << std::endl;
        }
    }

    std::cout << "The sum is " << sum << std::endl;

    return 0;
}
