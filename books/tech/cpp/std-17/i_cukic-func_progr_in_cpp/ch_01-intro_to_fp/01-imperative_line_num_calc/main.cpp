#include <iostream>
#include <string>
#include <vector>
#include <fstream>


std::vector<int> count_lines_in_files(std::vector<std::string> const& files) {
    std::vector<int> results{};

    char c = 0;
    for (auto const& file : files) {
        int line_count{0};
        
        std::ifstream in{file};
        while (in.get(c)) 
            if ('\n' == c)
                line_count++;
        
        results.push_back(line_count);
    }

    return results;
}


int main() {
    for (auto const line_count : count_lines_in_files( { "main.cpp" }))
        std::cout << line_count << " line(s)\n";

    return 0;
}
