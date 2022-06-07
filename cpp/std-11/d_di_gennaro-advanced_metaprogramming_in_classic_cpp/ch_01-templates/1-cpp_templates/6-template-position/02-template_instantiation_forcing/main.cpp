#include <iostream>

#include "sq.h"


int main() {
    // now can be compiled
    double x = sq(3.14);
    std::cout << x << std::endl;

    // but the next string will be not compiled (will not be linked)
    // int y = sq(3);
    
    return 0;
}
