#include <algorithm>
#include <iostream>
#include <iterator>
#include <locale>
#include <string>

bool non_letter(char ch) {
    return not std::isalpha(ch, std::locale{});
}

char lowercase(char ch) {
    return std::tolower(ch, std::locale());
}

bool is_same_char(char a, char b) {
    return lowercase(a) == lowercase(b);
}

bool is_palindrome(std::string str) {
    std::string::iterator end = 
        std::remove_if(str.begin(), str.end(), non_letter);
    std::string rev{ str.begin(), end };
    std::reverse(rev.begin(), rev.end());
    return not rev.empty()
           and std::equal(str.begin(), 
                          end, 
                          rev.begin(), 
                          is_same_char);
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
