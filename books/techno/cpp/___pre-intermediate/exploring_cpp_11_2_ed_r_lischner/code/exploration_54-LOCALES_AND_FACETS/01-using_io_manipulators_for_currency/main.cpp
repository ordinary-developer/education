#include <iomanip>
#include <iostream>
#include <iterator>
#include <locale>
#include <string>


int main() {
    std::locale native{""};
    std::cin.imbue(native);
    std::cout.imbue(native);

    std::cin >> std::noshowbase;
    std::cout << std::showbase;

    std::string digits{};
    while (std::cin >> std::get_money(digits))
        std::cout << std::put_money(digits) << '\n';

    if (not std::cin.eof())
        std::cout << "Invalid input.\n";

    return 0;
}
