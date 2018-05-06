// region [how to do it]
#include <iostream>
namespace example_01 {
    
#define LIB_VERSION_1    
namespace modernlib
{
    #ifndef LIB_VERSION_1
    inline namespace version_1 
    {    
        template <typename T>
        int test(T value) { return 1; }
    } 
    #endif
    
    #ifndef LIB_VERSION_2
    inline namespace version_2
    {
        template <typename T>
        int test(T value) { return 2; }
    }
    #endif
}    
    
struct foo { int a; };
    
namespace modernlib
{
    template<>
    int test(foo value) { return value.a; }
}
    
void run() {
    auto y = modernlib::test(foo{ 42 });
    std::cout << y << std::endl;
}
} // example_01
// endregion [how to do it]

#include <iostream>
int main() {
    example_01::run();
    
    std::cout << "DONE" << std::endl;
    
    return 0;
}