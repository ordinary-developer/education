#include <iostream>

struct rational {
    int numerator;
    int denominator;
};


int main() {
    rational pi{};
    pi.numerator = 355;
    pi.denominator = 113;
    std::cout << "pi is approximately " << pi.numerator << "/"
              << pi.denominator << '\n';

    return 0;
}
