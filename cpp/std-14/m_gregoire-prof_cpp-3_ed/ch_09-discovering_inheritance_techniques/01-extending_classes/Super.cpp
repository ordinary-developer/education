#include "Super.hpp"

#include <iostream>


Super::Super() {
    // do nothing here
    mProtectedInt = 0;
    mPrivateInt = 0;
}

void Super::someMethod() {
    std::cout << "This is Super's version of someMethod()." << std::endl;
    // do nothing here
}


