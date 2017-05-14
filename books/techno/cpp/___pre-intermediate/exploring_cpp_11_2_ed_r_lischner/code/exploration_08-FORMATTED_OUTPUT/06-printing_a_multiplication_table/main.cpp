#include <iomanip>
#include <iostream>


int main() {
    int const low{ 1 };
    int const high{ 10 };
    int const colwidth{ 4 };

    std::cout << std::right;
    std::cout << std::setw(colwidth) << '*' << '|';
    for (int i{ low }; i <= high; ++i) 
        std::cout << std::setw(colwidth) << i;
    std::cout << '\n';

    std::cout << std::setfill('-') 
              << std::setw(colwidth) << ""
              << '+'
              << std::setw((high - low + 1) * colwidth) << ""
              << '\n';

    std::cout << std::setfill(' ');
    
    for (int row{ low }; row <= high; ++row) {
        std::cout << std::setw(colwidth) << row << '|';
        for (int col{ low }; col <= high; ++col)
            std::cout << std::setw(colwidth) << row * col;
        std::cout << '\n';
    }

    return 0;

}
