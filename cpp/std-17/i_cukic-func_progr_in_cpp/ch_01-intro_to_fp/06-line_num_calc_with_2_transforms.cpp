#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <sstream>
#include <string>
#include <vector>
namespace test {
    
std::istringstream open_str(std::string const& str) { return std::istringstream{str}; }

int count_lines(std::istringstream strstream) {
    return std::count(
        std::istreambuf_iterator<char>{strstream},
        std::istreambuf_iterator<char>{},
        '\n');
}

std::vector<int> countLines(std::vector<std::string> const& strs) {
    std::vector<int> ret{};  
    
    auto const& vals = strs
        | std::ranges::views::transform(open_str)
        | std::ranges::views::transform(count_lines);
        
    std::copy(std::cbegin(vals), std::cend(vals), std::back_inserter(ret));        
    
    return ret;
}

void run() {
    for (auto const cnt: countLines( { "1\n2\n3", "1\n2\n3", "1\n2\n3" } ))
        std::cout << "line count: " << cnt << std::endl;
}
} // test


int main() {
    std::cout << "test => [ok]" << std::endl; test::run(); std::cout << std::endl;

    return 0;
}
