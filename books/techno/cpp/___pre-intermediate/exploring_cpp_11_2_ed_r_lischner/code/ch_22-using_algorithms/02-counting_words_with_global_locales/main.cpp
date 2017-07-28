#include <iomanip>
#include <iostream>
#include <locale>
#include <map>
#include <string>

typedef std::map<std::string, int> count_map;
typedef count_map::value_type count_pair;
typedef std::string::size_type str_size;

void initialize_streams() {
    std::cin.imbue(std::locale{});
    std::cout.imbue(std::locale{});
}

str_size get_longest_key(const count_map& map) {
    str_size result{ 0 };
    for (auto pair : map)
        if (pair.first.size() > result)
            result = pair.first.size();
    return result;
}

void print_pair(const count_pair& pair, str_size longest) {
    int const count_size{ 10 };
    std::cout << std::setw(longest) << std::left << pair.first
              << std::setw(count_size) << std::right
              << pair.second << '\n';
}

void print_counts(count_map counts) {
    str_size longest{ get_longest_key(counts) };
    for (count_pair pair : counts)
        print_pair(pair, longest);
}

std::string sanitize(const std::string&  str) {
    std::string result{};
    for (char c : str)
        if (std::isalnum(c, std::locale{}))
            result.push_back(std::tolower(c, std::locale{}));
    return result;
}


int main() {
    std::locale::global(std::locale{ "" });
    initialize_streams();

    count_map counts{};
    
    std::string word{};
    while (std::cin >> word) {
        std::string copy{ sanitize(word) };
        if (not copy.empty())
            ++counts[copy];
    }

    print_counts(counts);

    return 0;
}
