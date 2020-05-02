// code for assert working
#ifdef NDEBUG
#undef NDEBUG
#endif

#include <string>
#include <string_view>
#include <iostream>
#include <cassert>
namespace example_01 { // -> base use of std::string_view
    
std::string_view get_filename(std::string_view str) {
    auto const pos1{ str.find_last_of('\\') };
    auto const pos2{ str.find_last_of('.') };
    
    return str.substr(pos1 + 1, pos2 - pos1 - 1);
}
    
void run() {
    // arrange - act
    char const file1[] { R"(c:\test\example1.doc)" };
    auto const& name1 = get_filename(file1);
    
    auto const file2{ R"(c:\test\example2)" };
    auto const& name2 = get_filename(file2);
    
    auto const& name3 = get_filename(std::string_view{ file1, 16 });
    
    // assert 
    assert("example1" == name1);
    assert("example2" == name2);
    assert("example1" == name3);
    
    
    // aux output
    std::cout << "name1: " << name1 << std::endl;
    std::cout << "name2: " << name2 << std::endl;
    std::cout << "name3: " << name3 << std::endl;
}    
} // example_01


#include <string>
#include <iostream>
#include <cassert>
namespace example_02 { // -> the same functionality but without std::string_view
    
std::string get_filename(std::string const& str) {
    auto const pos1{ str.find_last_of('\\') };
    auto const pos2{ str.find_last_of('.') };
    return str.substr(pos1 + 1, pos2 - pos1 - 1);
}    
    
void run() {
    // arrange - act
    auto const& name1 = get_filename(R"(c:\test\example1.doc)");
    auto const& name2 = get_filename(R"(c:\test\example2)");
    auto const first_char = get_filename(R"(c:\test\_sample_.tmp)").front();
    
    // assert
    assert("example1" == name1);
    assert("example2" == name2);
    assert('_' == first_char);
    
    // aux output 
    std::cout << "name1: " << name1 << std::endl;
    std::cout << "name2: " << name2 << std::endl;
    std::cout << "first char: " << first_char << std::endl;
    
    std::cout << "[ok]";
}
} // example_02


#include <string>
#include <string_view>
#include <array>
#include <utility>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <cstddef>
#include <cassert>
namespace example_03 { // -> using "shrink" operations for std::string_view
    
std::string_view trim_view(std::string_view str) {
    auto const pos1{ str.find_first_not_of(" ") };
    auto const pos2{ str.find_last_not_of(" ") };
    str.remove_suffix(str.length() - pos2 - 1);
    str.remove_prefix(pos1);
    
    return str;
}
    
void run() {
    // arrange - act
    std::size_t const size{4};
    
    std::array<std::string_view, size> const str_views{ trim_view("sample"), trim_view("   sample"), 
        trim_view("sample    "), trim_view("    sample   ") };
    std::array<std::string, size> strs;
    std::generate(std::begin(strs), std::end(strs), 
        [&str_views = std::as_const(str_views), i = 0] () mutable {
            return *(std::next(std::cbegin(str_views), i++));
    });
    
    // assert
    std::for_each(std::cbegin(str_views), std::cend(str_views), [](std::string_view sv) {
        assert("sample" == sv);
    });
    std::for_each(std::cbegin(strs), std::cend(strs), [](std::string const& s) {
        assert("sample" == s);
    });
    
    // aux output
    std::copy(std::cbegin(str_views), std::cend(str_views), 
        std::ostream_iterator<std::string_view>(std::cout, "\n"));    
    std::copy(std::cbegin(strs), std::cend(strs),
        std::ostream_iterator<std::string>(std::cout, "\n"));              
    
    std::cout << "[ok]";
}
} // example_03


#include <iostream>
int main() {
    std::cout << "example_01 => " << std::endl; example_01::run(); std::cout << std::endl;
    std::cout << "example_02 => " << std::endl; example_02::run(); std::cout << std::endl;
    std::cout << "example_03 => " << std::endl;  example_03::run(); std::cout << std::endl;
    
    return 0;
}