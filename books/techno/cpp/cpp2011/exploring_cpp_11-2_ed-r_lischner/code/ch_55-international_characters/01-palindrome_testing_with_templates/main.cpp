#include <algorithm>
#include <iostream>
#include <iterator>
#include <locale>
#include <string>


template<class Char>
bool non_letter(Char ch) {
    return not std::isalpha(ch, std::locale{});
}

template<class Char>
Char lowercase(Char ch) {
    return std::tolower(ch, std::locale{});
}

template<class Char>
bool same_char(Char a, Char b) {
    return lowercase(a) == lowercase(b);
}

template<class Char, class Traits, class Allocator>
bool is_palindrome(std::basic_string<Char, Traits, Allocator> str) {
    typedef typename std::basic_string<Char, Traits, Allocator> string;
    typename string::iterator end { std::remove_if(str.begin(),
                                                   str.end(),
                                                   non_letter<Char>) };
    string rev{ str.begin(), end };
    std::reverse(rev.begin(), rev.end());
    return not rev.empty() and 
                std::equal(str.begin(), end, rev.begin(), same_char<Char>);
}

int main() {
    std::locale::global(std::locale{ "" });
    std::wcin.imbue(std::locale{});
    std::wcout.imbue(std::locale{});

    std::wstring line{};
    while (std::getline(std::wcin, line))
        if (is_palindrome(line))
            std::wcout << line << L'\n';

    return 0;
}
