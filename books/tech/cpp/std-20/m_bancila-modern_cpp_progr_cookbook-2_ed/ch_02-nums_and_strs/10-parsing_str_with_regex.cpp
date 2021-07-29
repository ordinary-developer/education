#include <iostream>
#include <regex>
#include <string>
#include <cassert>
namespace example_01 { // the "how to do it..." section

void run() {
    using namespace std::string_literals;

    auto txt{ R"(
        remove # to uncomment a line
        timeout=120
        server = 127.0.0.1
        #retrycount=3
    )"s };
    //std::string txt = "#remove # to uncomment a line\r\ntimeout=120\r\nserver = 127.0.0.1\r\nretrycount=3";

    auto rx = std::regex{ R"(^(?!#)(\w+)\s*=\s*([\w\d]+[\w\d._,\-:]*)$)"s };
    //auto rx = std::regex{ std::string("^(?!#)(\\w+)\\s*=\\s*([\\w\\d]+[\\w\\d._,\\-:]*)$") };
    
    {
        auto match = std::smatch{};
        if (std::regex_search(txt, match, rx)) {            
            std::cout << match[1] << '=' << match[2] << '\n';
        }
    }
    
    {
        auto end = std::sregex_iterator{};
        for (auto it = std::sregex_iterator{ std::begin(txt), std::end(txt), rx };
            it != end;
            ++it)
        {
            std::cout << '\'' << (*it)[1] << "\'=\'" << (*it)[2] << '\'' << '\n';
        }
    }
    
    {
        auto end = std::sregex_token_iterator{};
        for (auto it = std::sregex_token_iterator{std::begin(txt), std::end(txt), rx };
            it != end;
            ++it)
        {
            std::cout << *it << '\n';
        }
    }
    
    {
        auto end = std::sregex_token_iterator{};
        for (auto it = std::sregex_token_iterator{ std::begin(txt), std::end(txt), rx, 1};
            it != end;
            ++it)
        {
            std::cout << *it << '\n';
        }
    }
    
    {
        auto end = std::sregex_token_iterator{};
        for (auto it = std::sregex_token_iterator{ std::begin(txt), std::end(txt), rx, -1 };
            it != end;
            ++it)
        {
            std::cout << *it << '\n';
        }        
    }
}
    
} // example_01



#include <iostream>
int main() {
    std::cout << "example 01 => [ok]" << std::endl;
    example_01::run();
    std::cout << std::endl;
    
    
	return 0;
}
