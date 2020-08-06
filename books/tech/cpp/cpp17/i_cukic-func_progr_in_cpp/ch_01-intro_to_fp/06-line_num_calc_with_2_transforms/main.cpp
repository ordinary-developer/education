#include <algorithm>
#include <ranges>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <iterator>

std::istringstream open_str(std::string const& str) {
    return std::istringstream{str};
}


int count_lines(std::istringstream strstream) {        
    return std::count(
        std::istreambuf_iterator<char>(strstream),
        std::istreambuf_iterator<char>(),
        '\n');
}

std::vector<int> count_lines_in_files(std::vector<std::string> const& strs) {
    auto const& tmp_vals = strs
        | std::ranges::views::transform(open_str)
        | std::ranges::views::transform(count_lines);        
    
    std::vector<int> cnts{};
    std::copy(std::cbegin(tmp_vals), std::cend(tmp_vals), std::back_inserter(cnts));
    
    return cnts;
}


int main() {    
    for (auto const line_count : count_lines_in_files( { "1\n2\n3" }))
       std::cout << line_count << " line(s)\n";

    return 0;
}
