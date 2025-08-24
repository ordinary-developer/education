#include <iomanip>
#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> counts{};

    std::string word{};
    while (std::cin >> word) 
        ++counts[word];
    
    std::map<std::string, int>::iterator the{ counts.find("the") };
    if (counts.end() == the)
        std::cout << "\"the\": not found\n";
    else if (1 == the->second)
        std::cout << "\"the\": occurs " << the->second << " time\n";
    else
        std::cout << "\"the\": occurs " << the->second << " times\n";
    
    return 0;
}
