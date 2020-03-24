#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
namespace str_lib {

// type aliases 
template <typename CharT>
using string_t = 
    std::basic_string<CharT, std::char_traits<CharT>, std::allocator<CharT>>;

template <typename CharT>
using stringstream_t =
    std::basic_stringstream<CharT, std::char_traits<CharT>, std::allocator<CharT>>;
    
// to_upper / to_lower    
template <typename CharT>
inline string_t<CharT> to_upper(string_t<CharT> txt) {
    std::transform(std::begin(txt), std::end(txt), std::begin(txt), toupper);
    return txt;
}

template <typename CharT>
inline string_t<CharT> to_lower(string_t<CharT> txt) {
    std::transform(std::begin(txt), std::end(txt), std::begin(txt), tolower);
    return txt;
}

// reverse
template <typename CharT>
inline string_t<CharT> reverse(string_t<CharT> txt) {
    std::reverse(std::begin(txt), std::end(txt));
    return txt;
}

// trim (by space)
template <typename CharT>
inline string_t<CharT> trim(string_t<CharT> const& txt) {
    auto const first{ txt.find_first_not_of(' ') };
    auto const last{ txt.find_last_not_of(' ') };
    return txt.substr(first, (last - first + 1));
}

template <typename CharT>
inline string_t<CharT> trimleft(string_t<CharT> const& txt) {
    auto const first{ txt.find_first_not_of(' ') };
    return txt.substr(first, txt.size() - first);
}

template <typename CharT>
inline string_t<CharT> trimright(string_t<CharT> const& txt) {
    auto const last{ txt.find_last_not_of(' ') };
    return txt.substr(0, last + 1);
}

// trim (by delimiters)
template <typename CharT>
inline string_t<CharT> trim(
    string_t<CharT> const& txt, string_t<CharT> const& chars)
{
    auto const first{ txt.find_first_not_of(chars) };
    auto const last{ txt.find_last_not_of(chars) };
    return txt.substr(first, (last - first + 1));
}

template <typename CharT>
inline string_t<CharT> trimleft(
    string_t<CharT> const& txt, string_t<CharT> const& chars)
{
    auto const first{ txt.find_first_not_of(chars) };
    return txt.substr(first, txt.size() - first);
}

template <typename CharT>
inline string_t<CharT> trimright(
    string_t<CharT> const& txt, string_t<CharT> const& chars)
{
    auto const last{ txt.find_last_not_of(chars) };
    return txt.substr(0, last + 1);
}

// erase
template <typename CharT>
inline string_t<CharT> remove(string_t<CharT> txt, CharT const ch) {
    auto const start = std::remove_if(
        std::begin(txt), std::end(txt), [=](CharT const c) { return c == ch; });
    txt.erase(start, std::cend(txt));
    return txt;
}

template <typename CharT>
inline std::vector<string_t<CharT>> split(
    string_t<CharT> txt, CharT const delim)
{
    auto tokens = std::vector<string_t<CharT>>{};
    
    auto sstr = stringstream_t<CharT>{ txt };
    auto token = string_t<CharT>{};
    while (std::getline(sstr, token, delim))
        if (not token.empty())
            tokens.push_back(token);

    return tokens;
}
} // str_lib


#include <string>
#include <iostream>
namespace example_01 { void run() {
    using namespace std::string_literals;
    
    auto const s1{ str_lib::to_upper("this is not UPPERCASE"s) };
    auto const s2{ str_lib::to_lower("THIS IS NOT lowercase"s) };
    
    std::cout << s1 << std::endl << s2 << std::endl;
}    
} // example_01


#include <string>
#include <iostream>
namespace example_02 {
void run() {
    using namespace std::string_literals;    
    
    auto const s{ str_lib::reverse("cookbook"s) };
   
    std::cout << s << std::endl;
}
} // example_02


#include <string>
#include <iostream>
namespace example_03 {
void run() {
    using namespace std::string_literals;
    
    auto const s{ "   this is an example   "s };
    auto const s1{ str_lib::trim(s) };
    auto const s2{ str_lib::trimleft(s) };
    auto const s3{ str_lib::trimright(s) };
    
    std::cout << s1 << std::endl << s2 << std::endl << s3 << std::endl;
}    
} // example_03


#include <string>
#include <iostream>
namespace example_04 {
void run() {
    using namespace std::string_literals;
    
    auto const chars{ " !%\r\n"s };
    auto const txt{ "!!  this % needs a lot\rof trimming  !\n"s };
    
    auto const s1{ str_lib::trim(txt, chars) };
    auto const s2{ str_lib::trimleft(txt, chars) };
    auto const s3{ str_lib::trimright(txt, chars) };
    
    std::cout << s1 << std::endl << s2 << std::endl << s3 << std::endl;
}    
    
} // example_04


#include <string>
#include <iostream>
namespace example_05 {
void run() {
    using namespace std::string_literals;
    
    auto const txt{ "must remove all * from text**"s };
    auto const s1{ str_lib::remove(txt, '*') };
    auto const s2{ str_lib::remove(txt, '!') };
    
    std::cout << s1 << std::endl << s2 << std::endl;
}    
} // example_05


#include <string>
#include <iostream>
namespace example_06 {
void run() {
    using namespace std::string_literals;
    
    auto const txt1{ "this text wil be split   "s };
    auto const tokens1{ str_lib::split(txt1, ' ') };
    for (auto const& t: tokens1)
        std::cout << t << " ";
    std::cout << std::endl;        
    
    auto const txt2{ ""s };
    auto const tokens2{ str_lib::split(txt2, ' ') };
    for (auto const& t: tokens2)
        std::cout << t << " ";
    std::cout << std::endl;
}
}


#include <string>
#include <iostream>
int main() {
    std::cout << "exaple_01 => " << std::endl; example_01::run(); std::cout << std::endl;
    std::cout << "exaple_02 => " << std::endl; example_02::run(); std::cout << std::endl;
    std::cout << "exaple_03 => " << std::endl; example_03::run(); std::cout << std::endl;
    std::cout << "exaple_04 => " << std::endl; example_04::run(); std::cout << std::endl;
    std::cout << "exaple_05 => " << std::endl; example_05::run(); std::cout << std::endl;
    std::cout << "exaple_06 => " << std::endl; example_06::run(); std::cout << std::endl;
    
    return 0;
}
