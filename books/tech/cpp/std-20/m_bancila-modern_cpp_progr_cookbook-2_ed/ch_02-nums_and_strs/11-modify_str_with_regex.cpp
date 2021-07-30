#include <iostream>
#include <regex>
#include <string>
namespace example_01 { // the "how to do it..." section

void run() {
    using namespace std::string_literals;
    
    {
        auto txt{ "abc aa bca ca bbbb"s };
        auto rx = std::regex{ R"(\b[a|b|c]{3}\b)"s };
        auto newtxt = std::regex_replace(txt, rx, "---"s);
        std::cout << newtxt << std::endl;
    }
    
    {
        auto txt{ "bancila, marius"s };
        auto rx = std::regex{ R"((\w+),\s*(\w+))"s };
        auto newtxt = std::regex_replace(txt, rx, "$2 $1"s);
        std::cout << newtxt << std::endl;
    }
}
    
} // example_01


#include <iostream>
#include <regex>
#include <string>
namespace example_02 {
    
void run() {
    using namespace std::string_literals;
    
    {
        auto txt{ "abc aa bca ca bbbb"s };
        auto rx = std::regex{ R"(\b[a|b|c]{3}\b)"s };
        auto newtxt = std::regex_replace(txt, rx, "---"s,
            std::regex_constants::format_first_only);
        std::cout << newtxt << std::endl;            
    }
    
    {
        auto txt{ "this is a example with a error"s };
        auto rx = std::regex{ R"(\ba ((a|e|i|u|o)\w+))"s };
        auto newtxt = std::regex_replace(txt, rx, "an $1");
        std::cout << newtxt << std::endl;
    }
    
    {
        auto txt{ "today is 1.06.2016!!"s };
        auto rx = std::regex{ R"((\d{1,2})(\.|-|/)(\d{1,2})(\.|-|/)(\d{4}))"s };
        auto newtxt1 = std::regex_replace(txt, rx, R"($5$4$3$2$1)");
        std::cout << newtxt1 << std::endl;
        auto newtxt2 = std::regex_replace(txt, rx, R"([$`][$&][$'])");
        std::cout << newtxt2 << std::endl;
    }
}    

} // example_02


int main() {
    std::cout << "example 01 => [ok]" << std::endl;
    example_01::run();
    std::cout << std::endl;
    
    std::cout << "example 02 => [ok]" << std::endl;
    example_02::run();
    std::cout << std::endl;
    
	return 0;
}
