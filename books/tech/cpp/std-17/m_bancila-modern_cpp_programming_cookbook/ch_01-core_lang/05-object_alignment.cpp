// region [how to do it]
#include <iostream>
#include <typeinfo>
namespace example_01 {
    
struct alignas(4) foo {
    char a;
    char b;
};
    
struct bar {
    alignas(2) char a;
    alignas(8) int b;
};
    
void run() {
    foo foo_instance{};
    auto foo_align{ alignof(foo) };
    auto foo_instance_align{ alignof(foo_instance) };
    std::cout << "[foo_align]: " << foo_align << std::endl;
    std::cout << "[foo_instance_align]: " << foo_instance_align << std::endl;
    
    bar bar_instance{};
    auto bar_align{ alignof(bar) };
    auto bar_instance_align{ alignof(bar_instance) };
    std::cout << "[bar_align]: " << bar_align << std::endl;
    std::cout << "[bar_instance_align]: " << bar_instance_align << std::endl;
    
    
    alignas(8) int a{};
    auto a_align = alignof(a);
    std::cout << "[a_align]: " << a_align << std::endl;
    std::cout << "[int_align]: " << alignof(int) << std::endl;
    
    alignas(256) long b[4]{};
    auto b_align = alignof(b);
    std::cout << "[b_align]: " << b_align << std::endl;
    std::cout << "[long[4] aling]: " << alignof(long[4]) << std::endl;
    
    std::cout << "type of align: " 
              << typeid(alignof(char)).name() << std::endl;
}    
} // example_01
// endregion [how to do it]

// region [how it works]
#include <iostream>
namespace example_02 {
    
struct foo1 {
    char a;    
};    
    
struct foo2 {
    char a;
    char b;
}; 
    
struct foo3 {
    char a;
    int b;
}; 
    
    
struct foo4 {
    int a;
    char b;
    float c;
    double d;
    bool e;
};    

    
void run() {
    std::cout << "[sizeof foo1]: " << sizeof(foo1) << std::endl;
    std::cout << "[align of foo1]: " << alignof(foo1) << std::endl;
    
    std::cout << "[sizeof foo2]: " << sizeof(foo2) << std::endl;
    std::cout << "[align of foo2]: " << alignof(foo2) << std::endl;
    
    std::cout << "[sizeof foo3]: " << sizeof(foo3) << std::endl;
    std::cout << "[align of foo3]: " << alignof(foo3) << std::endl;
    
    std::cout << "[sizeof foo4]: " << sizeof(foo4) << std::endl;
    std::cout << "[align of foo4]: " << alignof(foo4) << std::endl;
}
}

#include <iostream>
namespace example_03 {
    
struct alignas(4) foo1 {
    char a;
    char b;
};   
    
struct alignas(4) foo2 {
    alignas(2) char a;
    alignas(8) int b;
};
    
    
void run() {
    std::cout << "[sizeof foo1]: " << sizeof(foo1) << std::endl;
    std::cout << "[align of foo1]: " << alignof(foo1) << std::endl;
    
    std::cout << "[sizeof foo12: " << sizeof(foo2) << std::endl;
    std::cout << "[align of foo2]: " << alignof(foo2) << std::endl;
}    
    
} // example_03

#include <iostream>
#include <cstdio>
namespace example_04 {
    
void run() {
    alignas(8) int a{};
    alignas(256) long b[4];
    printf("%p", &a);
    std::cout << std::endl;
    printf("%p", &b);
    std::cout << std::endl;
}    
}
// endregion [how it works]


#include <iostream>
int main() {
    example_01::run();
    example_02::run();
    example_03::run();
    example_04::run();
    
    std::cout << "DONE" << std::endl;
    
    
    std::cout << "DONE" << std::endl;
    
    return 0;
}