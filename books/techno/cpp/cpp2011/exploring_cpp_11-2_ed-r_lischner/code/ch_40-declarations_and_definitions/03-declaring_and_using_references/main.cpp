#include <iostream>


int main() {
    int answer{ 42 };
    int& ref{ answer };
    ref = 10;
    std::cout << answer << '\n';
    int const& cent{ ref * 10 };
    std::cout << cent << '\n';

    return 0;
}
