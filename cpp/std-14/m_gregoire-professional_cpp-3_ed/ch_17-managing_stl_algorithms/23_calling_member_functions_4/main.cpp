#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

void findEmptyString(const std::vector<std::string*>& strings) {
    auto endIterator = end(strings);

    auto iterator = find_if(begin(strings), end(strings),
                            [](const std::string* str) {
                                 return str->empty();
                            });

    if (endIterator == iterator) {
        std::cout << "No empty strings!" << std::endl;
    }
    else {
        std::cout << "Empty string at position: "
                  << static_cast<int>(iterator - begin(strings))
                  << std::endl;
    }
}

auto main() -> int {
    std::vector<std::string*> strings;

    std::string one = "blah";
    std::string two = "";
    strings.push_back(&one);
    strings.push_back(&one);
    strings.push_back(&two);
    strings.push_back(&one);

    findEmptyString(strings);

    return 0;
}

