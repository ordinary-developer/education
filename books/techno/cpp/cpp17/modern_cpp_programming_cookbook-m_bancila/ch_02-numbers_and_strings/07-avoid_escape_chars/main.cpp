#include <string>
#include <iostream>
namespace example_01 {
    
void run() {
    using namespace std::string_literals;
    
    auto const filename{ R"(C:\folder1\folder2\folder3])"s };
    auto const pattern{ R"((\w+)=(\d+)$)"s };
    std::string const sqlselect = { 
        R"(SELECT * 
        FROM Books WHERE Publisher='Packtpub'
        ORDER BY PubData DESC)"s };
    
    std::cout << filename << std::endl;
    std::cout << pattern << std::endl;
    std::cout << sqlselect << std::endl;
}     
} // example_01


#include <string>
#include <iostream>
namespace example_02 {
void run() {
    using namespace std::string_literals;
    
    auto const text{ R"!!(This test contains borth "( and )".)!!"s };
    std::cout << text << std::endl;
}
} // example_02


#include <string>
#include <iostream>
namespace example_03 {
void run() {
    using namespace std::string_literals;
    
    auto const filename1{ R"(C:\folder1\foloder2\folder3\)"s };
    auto const filename2{ R"(C:\\folder1\\folder2\\folder3\\)"s };
    
    std::cout << filename1 << std::endl;
    std::cout << filename2 << std::endl;
}
} // example_03


#include <string>
#include <typeinfo>
#include <iostream>
namespace example_04 {
void run() {
    using namespace std::string_literals;
    
    auto const t1{ LR"(text)" };
    auto const t2{ u8R"(text)" };
    auto const t3{ uR"(text)" };
    auto const t4{ UR"(text)" };
    std::cout << typeid(t1).name() << std::endl;
    std::cout << typeid(t2).name() << std::endl;
    std::cout << typeid(t3).name() << std::endl;
    std::cout << typeid(t4).name() << std::endl;
    
    auto const t5{ LR"(text)"s };
    auto const t6{ u8R"(text)"s };
    auto const t7{ uR"(text)"s };
    auto const t8{ UR"(text)"s };
    std::cout << typeid(t5).name() << std::endl;
    std::cout << typeid(t6).name() << std::endl;
    std::cout << typeid(t7).name() << std::endl;
    std::cout << typeid(t8).name() << std::endl;
}    
} // example_04


#include <iostream>
int main() {
    std::cout << "example_01 => " << std::endl; example_01::run(); std::cout << std::endl; 
    std::cout << "example_02 => " << std::endl; example_02::run(); std::cout << std::endl; 
    std::cout << "example_03 => " << std::endl; example_03::run(); std::cout << std::endl; 
    std::cout << "example_04 => " << std::endl; example_04::run(); std::cout << std::endl; 
    return 0;
}