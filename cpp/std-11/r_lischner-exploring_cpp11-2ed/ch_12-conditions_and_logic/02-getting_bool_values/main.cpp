#include <iostream>


int main() {
    bool a{ true }, b{ false };
    std::cin >> std::boolalpha >> a >> std::noboolalpha >> b;
    std::cout << std::boolalpha << a << ' ' << std::noboolalpha << b;

    return 0;
}
