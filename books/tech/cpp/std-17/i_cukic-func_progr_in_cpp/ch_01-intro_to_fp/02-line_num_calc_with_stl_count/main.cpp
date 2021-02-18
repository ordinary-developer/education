// read from a file with std::count
#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
namespace test_01 {

int count_lines(std::string const& file) {
    std::ifstream in{file};

    return std::count(
        std::istreambuf_iterator<char>{in},
        std::istreambuf_iterator<char>{},
        '\n');
}

std::vector<int> countLines(std::vector<std::string> const& files) {
    std::vector<int> ret{};

    for (auto const& file : files)
        ret.push_back(count_lines(file));

    return ret;
}

void run() {
    for (auto const cnt : countLines( { "main.cpp", "main.cpp", "main.cpp"}))
        std::cout << "line count: " << cnt << std::endl;
}
} // test_01


// count lines for strings with std::count
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
namespace test_02 {
    
int count_lines(std::string const& str) {
    std::istringstream in{str};
    
    return std::count(
        std::istreambuf_iterator<char>{in},        
        std::istreambuf_iterator<char>{},
        '\n');
}

std::vector<int> countLines(std::vector<std::string> const& strs) {
    std::vector<int> ret{};
    
    for (auto const& str : strs)
        ret.push_back(count_lines(str));
        
    return ret;
}

void run() {
    for (auto const cnt : countLines({ "1\n2\n3", "1\n2\n3", "1\n2\n3" }))
        std::cout << "line count: " << cnt << std::endl;
}

} // test_02


// count lines both for files and lines
#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
namespace test_03 {
    
int count_lines(std::string const& streamSrc, const bool isFileMode = true) {
    std::ifstream inFile;
    std::istringstream inStr;
    std::istreambuf_iterator<char> begin;
    std::istreambuf_iterator<char> end = std::istreambuf_iterator<char>{};
    
    if (isFileMode) {
        inFile = std::ifstream{streamSrc};
        begin = std::istreambuf_iterator{inFile};
    }
    else {
        inStr = std::istringstream{streamSrc};
        begin = std::istreambuf_iterator{inStr};
        
    }
    
    return std::count(begin, end, '\n');
}

std::vector<int> countLines(std::vector<std::string> const& strs, const bool isFileMode = true) {
    std::vector<int> ret{};
    
    for (auto const& str : strs)
        ret.push_back(count_lines(str, isFileMode));
        
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


#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <functional>
#include <memory>
#include <string>
#include <sstream>
#include <type_traits>
#include <vector>
namespace test_04 {

int count_lines(std::string const& streamSrc,
    std::function<std::unique_ptr<std::istream>(std::string const&)> const& getStream)
{    
    return std::count(
        std::istreambuf_iterator<char>{ *getStream(streamSrc).get() },
        std::istreambuf_iterator<char>{},
        '\n');    
}

std::vector<int> countLines(std::vector<std::string> const& streamSrcs,
    std::function<std::unique_ptr<std::istream>(std::string const&)> const& getStream)
{
    std::vector<int> ret{};
    
    for (auto const& streamSrc : streamSrcs)
        ret.push_back(count_lines(streamSrc, getStream));    
        
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
        
    std::cout << std::endl;
}
} // test_04


// the last test
#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <functional>
#include <memory>
#include <string>
#include <sstream>
#include <type_traits>
#include <vector>
namespace test_05 {
    
std::vector<int> countLines(std::vector<std::string> const& streamSrcs,
    std::function<std::unique_ptr<std::istream>(std::string const&)> const& getStream)
{
    std::vector<int> ret{};
    
    for (auto const& streamSrc : streamSrcs)
        ret.push_back(
            std::count(
                std::istreambuf_iterator<char>{ *getStream(streamSrc).get() },
                std::istreambuf_iterator<char>{},
                '\n'));        
                
    return ret;
}

std::vector<int> countLinesInFiles(std::vector<std::string> const& files) {
    return countLines(files,  [](auto const& streamSrc) { return std::make_unique<std::ifstream>(streamSrc); });
}

std::vector<int> countLinesInStrs(std::vector<std::string> const& strs) {
    return countLines(strs,  [](auto const& streamSrc) { return std::make_unique<std::istringstream>(streamSrc); });
}
    
void run() {
    auto const& lineCntInFiles = countLinesInFiles({ "main.cpp", "main.cpp", "main.cpp" });        
    auto const& lineCntInStrs = countLinesInStrs({ "1\n2\n\3", "1\n2\n\3", "1\n2\n\3" });
        
    std::copy(std::cbegin(lineCntInFiles), std::cend(lineCntInFiles), 
        std::ostream_iterator<std::remove_cvref<decltype(lineCntInFiles)>::type::value_type>{ std::cout, " "});

    std::copy(std::cbegin(lineCntInStrs), std::cend(lineCntInStrs), 
        std::ostream_iterator<std::remove_cvref<decltype(lineCntInStrs)>::type::value_type>{ std::cout, " "});
    
    std::cout << std::endl;
}
} // test_05


int main() {
    std::cout << "test 01 => [ok]" << std::endl; test_01::run(); std::cout << std::endl;
    std::cout << "test 02 => [ok]" << std::endl; test_02::run(); std::cout << std::endl;
    std::cout << "test 03 => [ok]" << std::endl; test_03::run(); std::cout << std::endl;
    std::cout << "test 04 => [ok]" << std::endl; test_04::run(); std::cout << std::endl;
    std::cout << "test 05 => [ok]" << std::endl; test_05::run(); std::cout << std::endl;

    return 0;
}
