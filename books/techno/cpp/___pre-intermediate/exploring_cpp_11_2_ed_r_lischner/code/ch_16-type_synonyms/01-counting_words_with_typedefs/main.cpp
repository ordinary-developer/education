#include <iomanip>
#include <iostream>
#include <map>
#include <string>


int main() {
    std::map<std::string, int> counts{};
    typedef std::map<std::string, int> count_map;
    typedef count_map::iterator count_iterator;

    std::string word{};
    while (std::cin >> word)
        ++counts[word];

    count_iterator the{ counts.find("the") };

    if (counts.end() == the)
        std::cout << "\"the\": not found\n";
    else if (1 == the->second)
        std::cout << "\"the\": occurs " << the->second << " times\n";
    else
        std::cout << "\"the\": occurs " << the->second << " times\n";

    return 0;
}
