#include <iostream>
#include <limits>


auto main() -> int {
    std::cout << "int: " << std::endl;
    std::cout << "Max int value: " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "Min int value: " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "Lowest int value: " << std::numeric_limits<int>::lowest() << std::endl;

    std::cout << std::endl << "double: " << std::endl;
    std::cout << "Max double value: " << std::numeric_limits<double>::max() << std::endl;
    std::cout << "Min double value: " << std::numeric_limits<double>::min() << std::endl;
    std::cout << "Lowest double value: " << std::numeric_limits<double>::lowest() << std::endl;

    return 0;
}
