// line counting in files
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
namespace test_01 {

std::vector<int> countLines(std::vector<std::string> const& files) {
    std::vector<int> ret{};
    char c{0};
    
    for (auto const& file : files) {
        std::ifstream in{file};
        
        int lineCnt{0};
        while (in.get(c))
            if ('\n' == c)
                ++lineCnt;
        
        ret.push_back(lineCnt);
    }
    
    return ret;
}

void run() {
    for (auto const cnt: countLines({ "main.cpp", "main.cpp", "main.cpp" }))
        std::cout << "line count: " << cnt << std::endl;
}
} // test_01


// line counting in strings
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
namespace test_02 {

std::vector<int> countLines(std::vector<std::string> const& strs) {
    std::vector<int> ret{};
    char c{0};
    
    for (auto const& str : strs) {
        std::istringstream in{str};
        
        int lineCnt{0};
        while (in.get(c))
            if ('\n' == c)
                ++lineCnt;
                
        ret.push_back(lineCnt);
    }
    
    return ret;
}

void run() {
    for (auto const cnt: countLines({ "1\n2\n3", "1\n2\n3", "1\n2\n3" }))
        std::cout << "line count: " << cnt << std::endl;
}

} // test_02


// line counting both in files and strings
#include <iostream>
#include <istream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
namespace test_03 {

std::vector<int> countLines(std::vector<std::string> const& streamSrcs, bool const isFileMode = true) {
    std::vector<int> ret;
    char c{0};
    
    std::ifstream inFile;
    std::istringstream inStr;
    for (auto const& streamSrc : streamSrcs) {
        if (isFileMode) 
            inFile = std::ifstream{streamSrc};
        else
            inStr = std::istringstream{streamSrc};
            
        int lineCnt{0};
        while (isFileMode ? inFile.get(c) : inStr.get(c))
            if ('\n' == c)
                ++lineCnt;
                
        ret.push_back(lineCnt);
    }
    
    return ret;
}

void run() {
    for (auto const cnt: countLines({ "main.cpp", "main.cpp", "main.cpp" }))
        std::cout << "line count: " << cnt << std::endl;
    
    std::cout << std::endl;    
    for (auto const cnt: countLines({ "1\n2\n3", "1\n2\n3", "1\n2\n3"}, false))
        std::cout << "line count: " << cnt << std::endl;    
}

} // test_03


// line counting both in files and strings (another version)
#include <iostream>
#include <istream>
#include <iterator>
#include <functional>
#include <memory>
#include <sstream>
#include <string>
#include <type_traits>
#include <vector>
namespace test_04 {

std::vector<int> countLines(std::vector<std::string> const& streamSrcs, std::function<std::unique_ptr<std::istream>(std::string const&)> const& getStream) {
    std::vector<int> ret{};
    char c{0};
    
    for (auto const& streamSrc : streamSrcs) {
        auto in = std::move(getStream(streamSrc));
        
        int lineCnt{0};
        while (in->get(c))
            if ('\n' == c)
                ++lineCnt;
                
        ret.push_back(lineCnt);                
    }
    
    return ret;
}

void run() {
    auto const& lineCntInFiles = countLines(
        { "main.cpp", "main.cpp", "main.cpp" },
        [](auto const& streamSrc) {
            return std::make_unique<std::ifstream>(streamSrc);
        });
        
    auto const& lineCntInStrs = countLines(
        { "1\n2\n\3", "1\n2\n\3", "1\n2\n\3" },
        [](auto const& streamSrc) {
            return std::make_unique<std::istringstream>(streamSrc);
        });
    
    std::copy(std::cbegin(lineCntInFiles), std::cend(lineCntInFiles), 
        std::ostream_iterator<std::remove_cvref<decltype(lineCntInFiles)>::type::value_type>{ std::cout, " "});

    std::copy(std::cbegin(lineCntInStrs), std::cend(lineCntInStrs), 
        std::ostream_iterator<std::remove_cvref<decltype(lineCntInStrs)>::type::value_type>{ std::cout, " "});
}

} // test_04


int main() {
    std::cout << "test 01 => [ok]" << std::endl; test_01::run(); std::cout << std::endl;
    std::cout << "test 02 => [ok]" << std::endl; test_02::run(); std::cout << std::endl;
    std::cout << "test 03 => [ok]" << std::endl; test_03::run(); std::cout << std::endl;
    std::cout << "test 04 => [ok]" << std::endl; test_04::run(); std::cout << std::endl;    
}
