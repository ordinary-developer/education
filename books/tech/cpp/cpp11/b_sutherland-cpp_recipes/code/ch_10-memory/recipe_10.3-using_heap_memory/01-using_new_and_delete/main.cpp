#include <iostream>

int main() {
    int* pInt{ new int };
    *pInt = 100;

    std::cout << std::hex << "The address at pInt is " << pInt << std::endl;
    std::cout << std::dec << "The value at pInt is " << *pInt << std::endl;

    delete pInt;
    pInt = nullptr;

    return 0;
}
