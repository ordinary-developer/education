#include <iostream>

int main() {
    volatile int vi(0);
    vi = 10;
    std::cout << vi;
    ++vi;
    --vi;

    return 0;
}
