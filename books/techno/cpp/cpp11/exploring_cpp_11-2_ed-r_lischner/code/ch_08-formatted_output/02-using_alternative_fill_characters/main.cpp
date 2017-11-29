#include <iomanip>
#include <iostream>

int main() {
    int day{ 14 };
    int month{ 3 };
    int year{ 2006 };
    int dollars{ 42 };
    int cents{ 7 };

    std::cout << "Date: "
              << std::setfill('0') << std::setw(2) << month << '/'
              << std::setw(2) << day << '/'
              << std::setw(2) << year << '\n';

    std::cout << "Pay to the order of: CASH\n";
    std::cout << "The amount of $" 
              << std::setfill('*') << std::setw(8) << dollars << '.'
              << std::setfill('0') << std::setw(2) << cents << '\n';
}
