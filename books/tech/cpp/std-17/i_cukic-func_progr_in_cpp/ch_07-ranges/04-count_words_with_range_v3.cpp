#include <iostream>
#include <functional>
#include <string>
#include <vector>

#include <cstdlib>
#include <cctype>

#include <range/v3/view.hpp>
#include <range/v3/action.hpp>
#include <range/v3/istream_range.hpp>
#include <range/v3/to_container.hpp>

namespace rg = ranges::v3;
namespace rv = ranges::v3::view;

std::string string_to_lower(std::string const& s) {
    return s | rv::transform(tolower) | rg::to<std::string>;
}

std::string string_only_alnum(std::string const& s) {
    return s | rv::filter(isalnum) | rg::to<std::string>;
}

int main(int argc, char* argv[]) {
    int const n = argc <= 1 ? 10 : atoi(argv[1]);

    auto const words = rg::istream_range<std::string>{std::cin}
        | rv::transform(string_to_lower)
        | rv::remove_if(&std::string::empty)
        | rg::to_vector | rg::action::sort;

    auto const results = words
        | rv::group_by(std::equal_to<>{})
        | rv::transform([](auto const& group) {
            return std::make_pair(
                std::distance(std::cbegin(group), std::cend(group)), 
                *std::cbegin(group));
          })
        | rg::to_vector | rg::action::sort;

    for (auto value : results | rv::reverse | rv::take(n))
        std::cout << value.first << " " << value.second << std::endl;
    
    return 0;
}
