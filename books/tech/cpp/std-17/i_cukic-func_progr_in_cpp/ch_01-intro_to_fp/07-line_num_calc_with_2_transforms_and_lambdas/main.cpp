#include <algorithm>
#include <ranges>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <iterator>


std::vector<int> count_lines_in_files(std::vector<std::string> const& strs) {
    auto const& tmp_vals = strs
        | std::ranges::views::transform(
            [](std::string const& str) { return std::istringstream{str}; })
        | std::ranges::views::transform(
            [](std::istringstream strstream) {
                return std::count(
                    std::istreambuf_iterator<char>(strstream),
                    std::istreambuf_iterator<char>(),
                    '\n');
            });
    
    std::vector<int> cnts{};
    std::copy(std::cbegin(tmp_vals), std::cend(tmp_vals), std::back_inserter(cnts));
    
    return cnts;
}


int main() {    
    for (auto const line_count : count_lines_in_files( { "1\n2\n3" }))
       std::cout << line_count << " line(s)\n";

    return 0;
}