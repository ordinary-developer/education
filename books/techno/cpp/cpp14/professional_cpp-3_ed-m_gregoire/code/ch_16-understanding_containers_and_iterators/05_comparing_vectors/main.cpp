#include <vector>
#include <iostream>


auto main() -> int {
    std::vector<int> vectorOne(10);
    std::vector<int> vectorTwo(10);

    if (vectorOne == vectorTwo) {
        std::cout << "equal!" << std::endl;
    }
    else {
        std::cout << "not equal!" << std::endl;
    }

    vectorOne[3] = 50;
    if (vectorOne < vectorTwo) {
        std::cout << "vectorOne is less than vectorTwo" << std::endl;
    }
    else {
        std::cout << "vectorOne is not less than vectorTwo" << std::endl;
    }

    return 0;
}
