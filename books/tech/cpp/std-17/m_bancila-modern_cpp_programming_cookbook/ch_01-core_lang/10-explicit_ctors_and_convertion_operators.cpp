// region [how to do it]
namespace example_01 {
    
struct handle_t {
    public:
        explicit handle_t(int const h) : handle_{ h } {}
        explicit operator bool() const { return 0 != handle_; }
    
    private:
        int handle_;
};
    
void run() {
    
}    
} // example_01
// endregion [how to do it]

// region [how it works]
#include <iostream>
namespace example_02 {
    
struct foo {
    foo() {
        std::cout << "foo" << std::endl;
    }
    
    foo(int const a) {
        std::cout << "foo(a)" << std::endl;
    }
    
    foo(int const a, double const b) {
        std::cout << "foo(a, b)" << std::endl;
    }
    
    operator bool() const { return true; }
};    
    
void bar(foo const f) { }
    
void run() {
    foo f1;
    foo f2{};
    
    foo f3(1);
    foo f4 = 1;
    foo f5{ 1 };
    foo f6 = { 1 };
    
    foo f7(1, 2.0);
    foo f8{ 1, 2.0 };
    foo f9 = { 1, 2.0 };
    
    bar({});
    bar(1);
    bar({ 1, 2.0 });
    
    bool flag = f1;
    if (f2) {}
}    
} // example_02

#include <cstddef>
#include <memory>
#include <iostream>
namespace example_03 {
   
class string_buffer {
    public:
        explicit string_buffer() {}
    
        explicit string_buffer(std::size_t const size) {}
    
        explicit string_buffer(char const* const ptr) {}
    
        explicit operator bool() const { return true; }
        
        explicit operator char * const () const { return "abc"; }
};    
    
void run() {
    std::shared_ptr<char> str{};
    
    string_buffer sb1{};
    string_buffer sb2{ 20 };
    string_buffer sb3{ str.get() };
    
    string_buffer sb4 = string_buffer('a');
    
    enum ItemSizes { DefaultHeight, Large, MaxSize };
    string_buffer sb5 = static_cast<string_buffer>(MaxSize);
    
    string_buffer sb6 = string_buffer{ "a" };
    
    std::cout << static_cast<bool>(sb1) + static_cast<bool>(sb2)
              << std::endl;
    if (static_cast<bool>(sb1) == static_cast<bool>(sb2)) {}
} 
}

// endregion [how it works]

// region [main]
#include <iostream>
int main() {
    example_01::run();
    example_02::run();
    example_03::run();
    
    std::cout << "DONE" << std::endl;
    return 0;
}
// endregion [main]