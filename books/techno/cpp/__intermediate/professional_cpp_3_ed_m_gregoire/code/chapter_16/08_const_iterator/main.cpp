#include <vector>
#include <iostream>
#include <string>

auto main() -> int {
    std::vector<std::string> stringVector(10, "hello");

    for (std::vector<std::string>::const_iterator it = begin(stringVector);
            it != end(stringVector); ++it) 
    {
        std::cout << *it << std::endl;
    }

    for (const auto& element : stringVector) {
        std::cout << element << std::endl;
    }

    return 0;
}
