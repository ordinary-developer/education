#include <iomanip>
#include <iostream>
#include <locale>
#include <map>
#include <string>

using count_map = std::map<std::string, int>;
using count_pair = count_map::value_type;
using str_size = std::string::size_type;


void initialize_streams(std::locale locale) {
    std::cin.imbue(locale);
    std::cout.imbue(locale);
}

str_size get_longest_key(count_map map) {
    str_size result{ 0 };
    for (auto pair : map)
        if (pair.first.size() > result)
            result = pair.first.size();

    return result;
}

void print_pair(count_pair pair, str_size longest) {
    const int count_size{ 10 };
    std::cout << std::setw(longest) << std::left << pair.first
              << std::setw(count_size) << std::right << pair.second
              << std::endl;
}

void print_counts(count_map counts) {
    str_size longest(get_longest_key(counts));
    for (count_pair pair : counts)
        print_pair(pair, longest);
}

std::string sanitize(std::string str, std::locale loc) {
    std::string result{};
    for (char ch : str) 
        if (std::isalnum(ch, loc))
            result.push_back(std::tolower(ch, loc));

    return result;
}

int main() {
    std::locale native{ "" };
    initialize_streams(native);

    count_map counts{};

    std::string word{};
    while (std::cin >> word) {
        std::string copy{ sanitize(word, native) };
        if (not copy.empty())
            ++counts[copy];
    }

    print_counts(counts);

    return 0;
}

