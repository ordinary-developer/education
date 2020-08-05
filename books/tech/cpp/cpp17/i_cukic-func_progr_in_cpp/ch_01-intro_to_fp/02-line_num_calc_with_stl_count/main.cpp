#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>


int count_lines(std::string const& filename) {
    std::ifstream in{filename};
    return std::count(
        std::istreambuf_iterator<char>{in},
        std::istreambuf_iterator<char>{},
        '\n');
}

std::vector<int> count_lines_in_files(std::vector<std::string> const& files) {
    std::vector<int> results{};

    for (auto const& file : files)
        results.push_back(count_lines(file));

    return results;    
}


int main() {
    for (auto const line_count : count_lines_in_files( { "main.cpp" }))
        std::cout << line_count << " line(s)\n";

    return 0;
}
