#include <iostream>

void printNum(const int num) {
    if (num > 100)
        return;

    std::cout << num << std::endl;
    printNum(num + 1);
}

int main() {
    printNum(1);
}
