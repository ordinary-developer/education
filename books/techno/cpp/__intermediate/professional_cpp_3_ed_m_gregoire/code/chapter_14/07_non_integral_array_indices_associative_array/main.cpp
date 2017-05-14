#include "AssociativeArray.hpp"

#include <iostream>


auto main() -> int {
    AssociativeArray<int> myArray;
    myArray["Key 1"] = 11;
    myArray["Key 2"] = 22;
    myArray["Key 3"] = 33;

    try {
        std::cout << myArray["Key 1"] << std::endl;
        std::cout << myArray["Key 2"] << std::endl;

        const AssociativeArray<int>& c = myArray;
        std::cout << c["Key 3"] << std::endl;
        std::cout << c["Key 4"] << std::endl;
    }
    catch (const std::invalid_argument& ex) {
        std::cout << "Caught exception: " << ex.what() << std::endl;
    }

    return 0;
}
