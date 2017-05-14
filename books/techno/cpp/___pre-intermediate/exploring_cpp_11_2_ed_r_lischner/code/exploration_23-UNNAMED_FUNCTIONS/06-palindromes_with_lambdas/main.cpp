#include <algorithm>
#include <iostream>
#include <iterator>
#include <locale>
#include <string>

bool is_palindrome(std::string str) {
    std::string::iterator end =
        std::remove_if(str.begin(),
                       str.end(),
                       [](char ch) {
                         return not std::isalpha(ch, std::locale());
                       });
    std::string rev{ std::begin(str), end };
    std::reverse(std::begin(rev), std::end(rev));

    return not rev.empty() 
           and std::equal(std::begin(str),
                          end,
                          std::begin(rev),
                          [](char a, char b) {
                            auto lowercase = [](char ch) {
                              return std::tolower(ch, std::locale());
                            };
                            return lowercase(a) == lowercase(b);
                          });
}


int main() {
    std::locale::global(std::locale{ "" });
    std::cin.imbue(std::locale{});
    std::cout.imbue(std::locale{});

    std::string line{};
    while (std::getline(std::cin, line))
        if (is_palindrome(line))
            std::cout << line << '\n';

    return 0;
}
