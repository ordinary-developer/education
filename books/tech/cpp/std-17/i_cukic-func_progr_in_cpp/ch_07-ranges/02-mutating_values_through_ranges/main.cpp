#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <type_traits>
#include <vector>
#include <cassert>
namespace test {
    
void run() {
    std::vector<std::string> words_raw{ "The", "brown", "fox", "jumped", "over", "a", "dog" };
    
    auto words = std::views::all(words_raw);
    std::ranges::sort(words);
    std::ranges::unique(words);
    
    std::vector<std::decay_t<std::ranges::range_value_t<decltype(words)>>> const words_as_vec{ std::cbegin(words), std::cend(words) };
    assert((std::vector<std::string>{ "The", "a", "brown", "dog", "fox", "jumped", "over" } == words_raw));
    assert((std::vector<std::string>{ "The", "a", "brown", "dog", "fox", "jumped", "over" } == words_as_vec));
}
    
} // test


#include <iostream>
int main() {
    std::cout << "test => [ok]" << std::endl; test::run(); std::cout << std::endl;   
        
    return 0;
} 