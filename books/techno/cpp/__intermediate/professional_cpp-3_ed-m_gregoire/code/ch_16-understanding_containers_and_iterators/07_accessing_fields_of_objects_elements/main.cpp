#include <iostream>
#include <vector>
#include <string>


auto main() -> int {
    std::vector<std::string> stringVector(10, "hello");

    for (auto it = begin(stringVector); it != end(stringVector); ++it) {
        it->append(" there");
    }

    for (auto& str : stringVector) {
        str.append(" there");
    }

    for (auto str : stringVector) {
        std::cout << str << std::endl;
    }

    return 0;
}
