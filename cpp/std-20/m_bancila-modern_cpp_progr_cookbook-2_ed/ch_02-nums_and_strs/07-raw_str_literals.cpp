#include <iostream>
#include <string>
namespace example_01 { // the "how to do it..." section

void run() {
    using namespace std::string_literals;
    
    auto filename{ R"(C:\Users\Marius\Documents\)"s };
    std::cout << filename << std::endl;
    
    auto pattern{ R"((\w+)=(\d+)$)"s };
    std::cout << pattern << std::endl;
    
    auto sqlselect {
        R"(SELECT *
        FROM books
        WHERE publisher='Packtpub'
        ORDER BY pubdata DESC)"s };
    std::cout << sqlselect << std::endl;
    
    auto txt{ R"!!(This text contains both "( and )".)!!"s };
    std::cout << txt << std::endl;
}
    
} // example_01


#include <iostream>
#include <string>
namespace example_02 { // the "how it works..." section

void run() {
    using namespace std::string_literals;
    
    auto filename1{ R"(C:\Users\Marius\Documents\)"s };
    std::cout << filename1 << std::endl;
    
    auto filename2{ R"(C:\\Users\\Marius\\Documents\\)"s };
    std::cout << filename2 << std::endl;
    
    auto t1{ LR"(text)" };  // const wchart_t*
    auto t2{ u8R"(text)" }; // const char* (in UTF8)
    auto t3{ uR"(text)" };  // const char16_t*
    auto t4{ UR"(text)" };  // const char32_t*
    
    auto t5{ LR"(text)"s };  // wstring
    auto t6{ u8R"(text)"s }; // string (in UTF8)
    auto t7{ uR"(text)"s };  // u16string
    auto t8{ UR"(text)"s };  // u32string
}    

} // example_02


#include <iostream>
int main() {
    std::cout << "example_01 => [ok]" << std::endl;
    example_01::run();
    std::cout << std::endl;
    
    std::cout << "example_02 => [ok]" << std::endl;
    example_02::run();
    std::cout << std::endl;
    
	return 0;
}
