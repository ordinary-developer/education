#include <algorithm>
#include <iostream>

int main() {
    int a1{ 1 }, b1{ 2 }, c1{ 3 };
    int smallest1{ std::min({ a1, b1, c1 }) };
    std::cout << smallest1 << std::endl;

    int a2{ 1 }, b2{ 2 }, c2{ 3 };
    std::vector<int> tmp{ a2, b2, c2 };
    int smallest2{ *std::min_element(tmp.begin(), tmp.end()) };
    std::cout << smallest2 << std::endl;

    return 0;
}
