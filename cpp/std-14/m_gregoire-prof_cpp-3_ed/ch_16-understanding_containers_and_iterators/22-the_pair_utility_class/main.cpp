#include <utility>
#include <string>
#include <iostream>


auto main() -> int {
    std::pair<std::string, int> myPair("hello", 5);

    std::pair<std::string, int> myOtherPair;
    myOtherPair.first = "hello";
    myOtherPair.second = 6;

    std::pair<std::string, int> myThirdPair(myOtherPair);            

    if (myPair < myOtherPair) {
        std::cout << "myPair is less than myOtherPair" << std::endl;
    }
    else {
        std::cout << "myPair is greater than or equal to myOtherPair" << std::endl;
    }

    if (myOtherPair == myThirdPair) {
        std::cout << "myOtherPair is equal to myThirdPair" << std::endl;
    }
    else {
        std::cout << "myOtherPair is not equal to myThirdPair" << std::endl;
    }

    std::pair<int, int> aPair = std::make_pair(5, 10);
    auto aSecondPair = std::make_pair(5, 10);

    return 0;
}
