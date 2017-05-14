#include <iostream>
#include <unordered_map>
#include <string>


auto main() -> int {
    std::unordered_map<int, std::string> m = {
        {1, "Item 1"},
        {2, "Item 2"},
        {3, "Item 3"},
        {4, "Item 4"},
    };

    for (const auto& p : m) {
        std::cout << p.first << " = " << p.second << std::endl;
    }

    return 0;
}

