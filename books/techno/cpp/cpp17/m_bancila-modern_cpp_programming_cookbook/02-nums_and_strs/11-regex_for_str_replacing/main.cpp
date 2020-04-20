#include <regex>
#include <string>
#include <iostream>
namespace example_01 { // -> base use of std::regex_replace
    
void run() {
    using namespace std::string_literals;    
    
    {
    auto const txt{ "abc aa bca ca bbbb"s };
    auto const rx{ std::regex{ R"(\b[a|b|c]{3}\b)"s } };
    auto const& newtxt1 = std::regex_replace(txt, rx, "---"s);
    auto const& newtxt2 = std::regex_replace(txt, rx, "---"s, 
        std::regex_constants::format_first_only);                                             
        
    std::cout << "new txt1: " << newtxt1 << std::endl;
    std::cout << "new txt2: " << newtxt2 << std::endl;
    }
    
    {
    auto const txt{ "bancila, marius"s };
    auto const rx{ std::regex{ R"((\w+),\s*(\w+))"s } };
    auto const& newtxt = std::regex_replace(txt, rx, "$2 $1"s);
        
    std::cout << "new txt: " << newtxt << std::endl;
    }
    
    {
    auto const txt{ "this is a example with a error"s };
    auto const rx{ std::regex{ R"(\ba ((a|e|i|u|o)\w+))"s } };
    auto const& newtxt = std::regex_replace(txt, rx, "an $1");
                  
    std::cout << "newtxt: " << newtxt << std::endl;                  
    }
    
    {
    auto const txt{ "today is 1.06.2016!!"s };
    auto const rx{ std::regex{ 
        R"((\d{1,2})(\.|-|/)(\d{1,2})(\.|-|/)(\d{4}))"s } };    
    auto const& newtxt1 = std::regex_replace(txt, rx, R"($5$4$3$2$1)"s);
    auto const& newtxt2 = std::regex_replace(txt, rx, R"([$`][$&][$'])"s);
        
    std::cout << "new txt1: " << newtxt1 << std::endl;
    std::cout << "new txt2: " << newtxt2 << std::endl;
    }
    
    std::cout << "[ok]";
}
    
} // example_01


#include <iostream>
int main() {
    std::cout << "example_01 => " << std::endl; example_01::run(); std::cout << std::endl;
    
    return 0;
}