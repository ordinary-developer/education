#include <algorithm>
#include <string>
#include <type_traits>
#include <vector>
#include <unordered_map>
#include <utility>
#include <cassert>
#include <cstddef>

#include <iostream>
namespace test {

template <typename C, typename T = typename C::value_type>
std::unordered_map<T, unsigned int> count_occurences(C const& collection) {
    std::unordered_map<T, unsigned int> ret{};

    for (auto const& c : collection)
        ret[c]++;

    return ret;
}

// reverses all pairs in a collection
template <
    typename C,
    typename P1 = typename std::remove_cv<
        typename C::value_type::first_type>::type,
    typename P2 = typename C::value_type::second_type
>
std::vector<std::pair<P2, P1>> reverse_pairs(C const& items) {
    std::vector<std::pair<P2, P1>> ret(items.size());

    std::transform(
        std::begin(items), std::end(items),
        std::begin(ret),
        [](std::pair<const P1, P2> const& p) {
            return std::make_pair(p.second, p.first);
        });

    return ret;
}

void run() {
  {
    std::string const sentence = "Hello world";

    auto const& actual = reverse_pairs(count_occurences(sentence));
    std::vector<std::pair<unsigned int, char>> const expected{
        {1, 'r'}, {1, 'e'}, {1, 'd'}, {2, 'o'}, {1, 'H'}, {1, ' '}, {1, 'w'}, {3, 'l'} };
    assert(expected == actual);
  }

  {
    std::vector<std::string> words{ 
        std::string("The"),
        std::string("Farm"),
        std::string("from"),
        std::string("the"),
        std::string("Animal"),
        std::string("Farm") };

    auto const& actual = reverse_pairs(count_occurences(words));
    std::vector<std::pair<unsigned int, std::string>> const expected{
        {1, "the"}, {1, "from"}, {1, "The"}, {1, "Animal"}, {2, "Farm"} };
    assert(expected == actual);
  }
}

} // test


#include <iostream>
int main() {
    std::cout << "test => [ok]" << std::endl; test::run(); std::cout << std::endl;

    return 0;
}
