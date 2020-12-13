#include <iostream>
#include <map>
#include <string>


int main() {
    std::map<std::string, int> counts{};

    std::string word{};
    while (std::cin >> word)
        ++counts[word];

    for (auto element : counts)
        std::cout << element.first << '\t' << element.second << '\n';

    return 0;
}
