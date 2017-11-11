#include <iostream>
#include <memory>


auto main() -> int {
    double pi = 3.1415;
    auto myLambda = [myCapture = "Pi: ", pi] { 
        std::cout << myCapture << pi << std::endl; 
    };
    myLambda();

    auto myPtr = std::make_unique<double>(3.1415);
    auto myLambda2 = [p = std::move(myPtr)] () { 
        std::cout << *p << std::endl; 
    };
    myLambda2();

    auto myPtr2 = std::make_unique<double>(3.1415);
    auto myLambda3 = [myPtr2 = std::move(myPtr2)] () {
        std::cout << *myPtr2 << std::endl; 
    };

    return 0;
}
