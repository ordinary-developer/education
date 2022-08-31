#include <iostream>


int max(const int a, const int b) { return a > b ? a : b; }


int main() {
    std::cout << "The maxium of 11 and 22 is: " << max(11, 22);
}
