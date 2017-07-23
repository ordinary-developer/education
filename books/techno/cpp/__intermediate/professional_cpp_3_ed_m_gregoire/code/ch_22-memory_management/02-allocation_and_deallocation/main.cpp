#include <iostream>

int main() {
    int* ptr1{};
    ptr1 = new int{};
    delete ptr1;

    int* ptr2 = new(std::nothrow) int{};
    if (nullptr != ptr2) {
        std::cout << "ptr2 is not null" << std::endl;
        delete ptr2;
    }
    else
        std::cout << "ptr2 is null" << std::endl;

    return 0;
}
