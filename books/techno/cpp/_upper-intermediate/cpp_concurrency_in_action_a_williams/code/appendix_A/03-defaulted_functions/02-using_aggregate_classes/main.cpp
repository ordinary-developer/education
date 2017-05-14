struct aggregate {
    aggregate() = default;
    aggregate(aggregate const&) = default;

    int a;
    double b;
};

#include <iostream>
int main() {
    aggregate x1 = { 42, 3.141 };
    std::cout << x1.a << std::endl;
    std::cout << x1.b << std::endl;

    aggregate x2{ 42, 3.141 };
    std::cout << x2.a << std::endl;
    std::cout << x2.b << std::endl;

    return 0;
}
