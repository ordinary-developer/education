#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
namespace example_01 { // -> the "how to do it..." section

namespace string_library {
    template <typename CharT>
    using tstring = std::basic_string<CharT, std::char_traits<CharT>, std::allocator<CharT>>;
    
    template <typename CharT>
    using tstringstream = std::basic_stringstream<CharT, std::char_traits<CharT>, std::allocator<CharT>>;
    
    namespace mutable_version {
        template <typename CharT>
        inline void to_upper(tstring<CharT>& txt) {
             std::transform(std::begin(txt), std::end(txt), std::begin(txt), toupper);
        }
         
        template <typename CharT>
        inline void to_lower(tstring<CharT>& txt) {
            std::transform(std::begin(txt), std::end(txt), std::begin(txt), tolower);
        }
        
        template <typename CharT>
        inline void reverse(tstring<CharT>& txt) {
            std::reverse(std::begin(txt), std::end(txt));
        }
        
        template <typename CharT>
        inline void trim(tstring<CharT>& txt) {
            auto first{ txt.find_first_not_of(' ') };
            auto last{ txt.find_last_not_of(' ') };
            txt = txt.substr(first, (last - first + 1));
        }
        
        template <typename CharT>
        inline void trimleft(tstring<CharT> & txt) {
            auto first{ txt.find_first_not_of(' ') };
            txt = txt.substr(first, txt.size() - first);
        }
        
        template <typename CharT>
        inline void trimright(tstring<CharT> & txt) {
            auto last{ txt.find_last_not_of(' ') };
            txt = txt.substr(0, last + 1);
        }
    }
    
    template <typename CharT>
    inline tstring<CharT> to_upper(tstring<CharT> txt) {
        std::transform(std::begin(txt), std::end(txt), std::begin(txt), toupper);
        return txt;
    }
    
    template <typename CharT>
    inline tstring<CharT> to_lower(tstring<CharT> txt) {
        std::transform(std::begin(txt), std::end(txt), std::begin(txt), tolower);
        return txt;
    }
    
    template <typename CharT>
    inline tstring<CharT> reverse(tstring<CharT> txt) {
        std::reverse(std::begin(txt), std::end(txt));
        return txt;
    }
    
    template <typename CharT>
    inline tstring<CharT> trim(tstring<CharT> const & txt) {
        auto first{ txt.find_first_not_of(' ') };
        auto last{ txt.find_last_not_of(' ' )};
        return txt.substr(first, (last - first + 1));
    }
    
    template <typename CharT>
    inline tstring<CharT> trimleft(tstring<CharT> const & txt) {
        auto first{ txt.find_first_of(' ') };
        return txt.substr(first, txt.size() - first);        
    }
    
    template <typename CharT>
    inline tstring<CharT> trimright(tstring<CharT> const & txt) {
        auto last{ txt.find_last_not_of(' ') };
        return txt.substr(0, last + 1);
    }
    
    template <typename CharT>
    inline tstring<CharT> trim(tstring<CharT> const & txt, tstring<CharT> const & chars) {
        auto first{ txt.find_first_not_of(chars) };
        auto last{ txt.find_last_not_of(chars) };
        return txt.substr(first, (last - first + 1));
    }
    
    template <typename CharT>
    inline tstring<CharT> trimleft(tstring<CharT> const& txt, tstring<CharT> const & chars) {
        auto first{ txt.find_first_not_of(chars) };
        return txt.substr(first, txt.size() - first);
    }
    
    template <typename CharT>
    inline tstring<CharT> trimright(tstring<CharT> const& txt, tstring<CharT> const& chars) {
        auto last{ txt.find_last_not_of(chars) };
        return txt.substr(0, last + 1);
    }    
    
    template <typename CharT>
    inline tstring<CharT> remove(tstring<CharT> txt, CharT const ch) {
        auto start = std::remove_if(std::begin(txt), std::end(txt), [=](CharT const c) { return c == ch; });
        txt.erase(start, std::end(txt));
        return txt;
    }
    
    template <typename CharT>
    inline std::vector<tstring<CharT>> split(tstring<CharT> txt, CharT const delimiter) {
        auto sstr = tstringstream<CharT>{ txt };
        auto tokens = std::vector<tstring<CharT>>{};
        auto token = tstring<CharT>{};
        while (std::getline(sstr, token, delimiter)) 
            if (not token.empty())
                tokens.push_back(token);
        
        return tokens;
    }
}

void run() {
    using namespace std::string_literals;
    
    {
        auto str{ string_library::to_upper("this is not UPPERCASE"s ) };
        std::cout << str << std::endl;
        std::string str2 = "this is not UPPERCASE";
        string_library::mutable_version::to_upper(str2);
        std::cout << str2 << std::endl;
    }
    
    {
        auto str{ string_library::to_lower("THIS IS NOT lowercase"s) };
        std::cout << str << std::endl;
        std::string str2 = "THIS IS NOT lowercase";
        string_library::mutable_version::to_lower(str2);
        std::cout << str2 << std::endl;    
    }
    
    {
        auto str{ string_library::reverse("cookbook"s) };
        std::cout << str << std::endl;
        std::string str2 = "cookbook";
        string_library::mutable_version::reverse(str2);
        std::cout << str2 << std::endl;
    }
    
    {
        auto txt{ "   this is an example   "s };
        
        auto str = string_library::trim(txt);
        std::cout << str << std::endl;
        std::string str2 = txt;
        string_library::mutable_version::trim(str2);
        std::cout << str2 << std::endl;
        
        str = string_library::trimleft(txt);
        std::cout << str << std::endl;
        str2 = txt;
        string_library::mutable_version::trimleft(str2);
        std::cout << str2 << std::endl;
        
        str = string_library::trimright(txt);
        std::cout << str << std::endl;
        str2 = txt;
        string_library::mutable_version::trimright(str2);
        std::cout << str2 << std::endl;
    }
    
    {
        auto chars{ " !%\n\r"s };
        auto txt{ "!!  this % needs a lot\rof trimming  !\n"s };
        
        auto str = string_library::trim(txt, chars);
        std::cout << str << std::endl;
        
        str = string_library::trimleft(txt, chars);
        std::cout << str << std::endl;
        
        str = string_library::trimright(txt, chars);
        std::cout << str << std::endl;
    }
    
    {
        auto txt{ "must remove all * from text**"s };
        
        auto str = string_library::remove(txt, '*');
        std::cout << str << std::endl;
        
        str = string_library::remove(txt, '!');
        std::cout << str << std::endl;
    }
    
    {
        auto txt{ "this text will be split    "s };
        auto tokens1{ string_library::split(txt, ' ') };
        std::cout << tokens1.size() << std::endl;
        
        auto tokens2{ string_library::split(""s, ' ') };
        std::cout << tokens2.size() << std::endl;
    }
    
    
}
    
} // example_01


#include <iostream>
int main() {
    std::cout << "example_01 => [ok]" << std::endl;
    example_01::run();
    std::cout << std::endl;
    
	return 0;
}
