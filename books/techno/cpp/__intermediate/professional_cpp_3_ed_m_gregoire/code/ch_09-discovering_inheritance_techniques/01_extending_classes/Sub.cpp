#include "Sub.hpp"

#include <iostream>


Sub::Sub() {
    //do nothing here
}

void Sub::someMethod() {
    std::cout << "This is Sub's version of someMethod()." << std::endl;
}

void Sub::someOtherMethod() {
    std::cout << "someOhterMethod() calling" << std::endl;
    std::cout << " I can access base class data member mProtectedInt." 
              << std::endl;
    std::cout << "Its value is " << mProtectedInt << std::endl;
    // this string will not compile
    // std::cout << "The value of mPrivateInt is " << mPrivateInt << std::endl;
}
