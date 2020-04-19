#include <string>
#include <regex>
#include <initializer_list>
#include <iostream>
namespace example_01 {
void run() {
    using namespace std::string_literals;
        
    auto const txt{
         R"(
#remove # to uncomment the following lines
timeout=120
server = 127.0.0.1

#retrycount=3
)"s };
    
    auto const txt_one_ln { "#remove #to uncomment\ntimeout=120\nserver = 127.0.0.1\n \n#retrycount=3\n"s };
    auto const lines = { 
        R"(#remove # to uncomment the following lines)"s,
        R"(timeout=120)"s,
        R"(server = 127.0.0.1)"s,
        R"()"s,   
        R"(#retrycount=3)"s
    };
    auto const pattern{ R"(^(?!#)(\w+)\s*=\s*([\w\d]+[\w\d._,\-:]*)$)"s };
    auto const rx = std::regex{ pattern };
    
    // first way
    {
    std::cout << "#first way: " << std::endl;
    for (auto const& ln : lines)
        if (auto match = std::smatch(); std::regex_search(ln, match, rx)) 
            std::cout << "[" << match[1] << "] = [" << match[2] << "]" << std::endl;
    } 
    
    // second way
    {
    std::cout << "#second way: " << std::endl;
        auto const& end = std::sregex_iterator{};
        for (auto const& ln : lines)
            for (auto it = std::sregex_iterator{ std::cbegin(ln), std::cend(ln), rx }; end != it; ++it)
                std::cout << "[" << (*it)[1] << "] = [" << (*it)[2] << "]" << std::endl;
    }
    
    // third way
    {
    std::cout << "#third way: " << std::endl;
        auto const& end = std::sregex_token_iterator{};
        for (auto const& ln : lines)
            for (auto it = std::sregex_token_iterator{ std::cbegin(ln), std::cend(ln), rx }; end != it; ++it)
                std::cout << "[" << *it << "]" << std::endl;
    }
    
    // fourth way
    {
    std::cout << "#fourth way: " << std::endl;
    auto const& end = std::sregex_token_iterator{};
    for (auto const& ln : lines)
        for (auto it = std::sregex_token_iterator{ std::cbegin(ln), std::cend(ln), rx, 1 }; end != it; ++it)
            std::cout << "[" << *it << "]" << std::endl;
    }
    
    // fifth way
    {
    std::cout << "#fifth way: " << std::endl;
    auto const& end = std::sregex_token_iterator{};
    for (auto const& ln : lines)
        for (auto it = std::sregex_token_iterator{ std::cbegin(ln), std::cend(ln), rx, -1 }; end != it; ++it)
            std::cout << "[" << *it << "]" << std::endl;
    }
    
    std::cout << "[ok]" << std::endl;
}
} // example_01


#include <iostream>
int main() {
    std::cout << "example_01 => " << std::endl; example_01::run(); std::cout << std::endl;
    
    return 0;
}