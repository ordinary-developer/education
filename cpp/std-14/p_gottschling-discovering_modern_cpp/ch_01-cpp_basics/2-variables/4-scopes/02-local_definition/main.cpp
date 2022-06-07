#include <iostream>

int main() {
    const double pi1 = 3.1415926;
    std::cout << "pi1 is " << pi1 << ".\n";

    { 
        const double pi2 = 3.1415926;
    }
    // here an error will be
    // std::cout << "pi2 is " << pi2 << ".\n";

    return 0;
}
