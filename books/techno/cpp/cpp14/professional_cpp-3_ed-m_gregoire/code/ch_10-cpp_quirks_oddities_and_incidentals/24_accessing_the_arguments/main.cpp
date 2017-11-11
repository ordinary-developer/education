#include <cstdio>
#include <cstdarg>
#include <iostream>

void printInts(int num, ...) {
    int temp;
    va_list ap;
    va_start(ap, num);
    for (int i = 0; i < num; ++i) {
        temp = va_arg(ap, int);
        std::cout << temp << " ";
    }
    va_end(ap);
    std::cout << std::endl;
}

auto main() -> int {
    printInts(5, 5, 4, 3, 2, 1);

    return 0;
}
