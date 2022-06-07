#include <string>
#include <vector>
#include <iostream>

#include <range/v3/view.hpp>
namespace rg = ranges::v3;
namespace rv = ranges::v3::view;

template <typename T>
class err;

template <typename Range>
void write_top_10(Range const& xs) {
    auto items = rv::zip(xs, rv::ints(1, rg::unreachable))    
        | rv::transform([](auto const& pair) {
            return std::to_string(pair.second) + " " + pair.first;
          })
        | rv::take(10);
}

int main() {
    std::vector<std::string> movies{ 
        "Meaning of life", "Dr Strangelove" };
    
    write_top_10(movies);
}
