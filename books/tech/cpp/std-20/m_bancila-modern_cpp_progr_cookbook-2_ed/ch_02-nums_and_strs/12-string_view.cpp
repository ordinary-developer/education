#include <iostream>
#include <string_view>
namespace example_01 { // the "how to do it..." section

std::string_view get_filename(std::string_view str) {
    auto const pos1{ str.find_last_of('\\') };
    auto const pos2{ str.find_last_of('.') };
    return str.substr(pos1 + 1, pos2 - pos1 - 1);
}

void run() {
    
    char const file1[] { R"(c:\test\example1.doc)" };
    
    auto name1 = get_filename(file1);
    std::cout << name1 << std::endl;
    
    std::string file2{ R"(c:\test\example2)" };
    auto name2 = get_filename(file2);
    std::cout << name2 << std::endl;
    
    auto name3 = get_filename(std::string_view{ file1, 16 });
    std::cout << name3 << std::endl;
}
    
} // example_01


#include <iostream>
#include <string>
namespace example_02 {
    
std::string get_filename(std::string const & str) {
    auto const pos1{ str.find_last_of('\\') };
    auto const pos2{ str.find_last_of('.') };
    
    return str.substr(pos1 + 1, pos2 - pos1 - 1);
}
    
std::string_view trim_view(std::string_view str) {
    auto const pos1{ str.find_first_not_of(" ") };
    auto const pos2{ str.find_last_not_of(" ") };
    str.remove_suffix(str.length() - pos2 - 1);
    str.remove_prefix(pos1);
    
    return str;
}

void run() {
    {
        auto name1 = get_filename(R"(c:\test\example1.doc)");
        std::cout << name1 << std::endl;
        
        auto name2 = get_filename(R"(c:\test\example2)");
        std::cout << name2 << std::endl;
        
        if (get_filename(R"(c:\test\_sample_.tmp)").front() == '_') {
            std::cout << "underscore" << '\n';
        }
    }
    
    {
        std::string_view sv{ "demo" };
        std::string s{ sv };
    }
    
    {
        auto sv1{ trim_view("sample") };
        auto sv2{ trim_view("  sample") };
        auto sv3{ trim_view("sample   ") };
        auto sv4{ trim_view("   sample   ")};
        
        std::cout << sv1 << std::endl;
        std::cout << sv2 << std::endl;
        std::cout << sv3 << std::endl;
        std::cout << sv4 << std::endl;
    }
    
}
} // example_02 


#include <iostream>
int main() {
    std::cout << "example 01 => [ok]" << std::endl;
    example_01::run();
    std::cout << std::endl;
    
    std::cout << "example 02 => [ok]" << std::endl;
    example_02::run();
    std::cout << std::endl;
    
    return 0;
}
