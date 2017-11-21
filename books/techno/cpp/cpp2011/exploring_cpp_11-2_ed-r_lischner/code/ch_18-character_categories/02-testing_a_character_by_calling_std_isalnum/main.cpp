#include <iostream>
#include <locale>
#include <map>
#include <string>


int main() {
    typedef std::map<std::string, int> count_map;
    count_map counts{};

    std::string word{};
    while (std::cin >> word) {
        std::string copy{};
        for (char ch : word)
            if (std::isalnum(ch, std::locale{ "" }))
                copy.push_back(ch);

        if (not copy.empty())
            ++counts[copy];
    }

    for (auto pair : counts)
        std::cout << pair.first << '\t' << pair.second << '\n';

    return 0;
}
