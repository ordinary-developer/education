#include <iomanip>
#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> counts{};

    std::string word{};
    while (std::cin >> word)
        ++counts[word];

    std::string::size_type longest{};
    for (auto element : counts)
        if (element.first.size() > longest)
            longest = element.first.size();

    const int count_size{ 10 };
    for (auto element : counts)
        std::cout << std::setw(longest) << std::left
                  << element.first << std::setw(count_size)
                  << std::right << element.second << '\n';

    return 0;
}
