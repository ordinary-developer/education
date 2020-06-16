#include <string>
#include <iostream>
namespace example_01 { // usage of the stringizing operator
    
#define MAKE_STR2(x) #x
#define MAKE_STR(x) MAKE_STR2(x)

#define MERGE2(x, y) x##y
#define MERGE(x, y) MERGE2(x, y)

#define NUMBER 42
    
void run() {
    std::string const s1{ MAKE_STR(sample) };
    std::string const s2{ MAKE_STR2(sample) };
    
    std::cout << "s1 = " << s1 << std::endl;
    std::cout << "s2 = " << s2 << std::endl;
    
    std::string const s3{ MAKE_STR(NUMBER) };    
    std::string const s4{ MAKE_STR2(NUMBER) };    
    std::cout << "s3 = " << s3 << std::endl;
    std::cout << "s4 = " << s4 << std::endl;
}    
} // example_01


#include <iostream>
#include <typeinfo>
namespace example_02 { // usage of the concatenation operator
    
#define DECL_MAKE(x) DECL_MAKE2(x)
#define DECL_MAKE2(x) x* make##_##x() { return new x{}; }
 
struct bar {};
struct foo {};
    
DECL_MAKE(foo)
DECL_MAKE(bar)
    

void run() {
    auto f = make_foo();
    auto b = make_bar();
    
    std::cout << "typeof(f) = " << typeid(f).name() << std::endl;
    std::cout << "typeof(b) = " << typeid(b).name() << std::endl;
}    
} // example_02


#include <iostream>
#include <typeinfo>
namespace example_03 { // "reimplementing" Windows' _T macro
    
#ifdef _UNICODE
#define __T(x) L ## x
#else
#define __T(x) x
#endif
    
#define _T(x) __T(x)
#define _TEXT(x) __T(x)
    
void run() {
    auto txt{ _T("sample") };    
    
    std::cout << "typeof(_T(sample)) = " << typeid(txt).name() << std::endl;
}    
} // example_03


#include <iostream>
int main() {
    std::cout << "example_01 => " << std::endl; example_01::run(); std::cout << std::endl;
    std::cout << "exapmle_02 => " << std::endl; example_02::run(); std::cout << std::endl;
    std::cout << "exapmle_03 => " << std::endl; example_03::run(); std::cout << std::endl;
    
    return 0;
}