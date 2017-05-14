#include <iomanip>
#include <iostream>
#include <map>
#include <string>


int main() {
    typedef std::map<std::string, int> count_map;
    typedef std::string::size_type str_size;

    count_map counts{};

    std::string okay{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                     "abcdefghijklmnopqrstuvwxyz"
                     "0123456789-_"};

    std::string word{};
    while (std::cin >> word) {
        std::string copy{};
        for (char ch : word)
            if (okay.find(ch) != std::string::npos)
                copy.push_back(ch);
        
        if (not copy.empty())
            ++counts[copy];
    }

    str_size longest{ 0 };
    for (auto pair : counts)
        if (pair.first.size() > longest)
            longest = pair.first.size();

    constexpr int count_size{ 10 };
    for (auto pair : counts) 
        std::cout << std::setw(longest) << std::left << pair.first
                  << std::setw(count_size) << std::right << pair.second
                  << std::endl;

    return 0;
}
