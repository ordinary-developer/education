// code for assert working
#ifdef NDEBUG
#undef NDEBUG
#endif

#include <iostream>
#include <cassert>
namespace example_01 { // -> base use of the "default" keyword
void run() {
    // arrage - act
    struct foo{ 
        foo() = default;
        
        int val;
    } constexpr f{};
    
    // asert
    assert(0 == f.val);
    
    std::cout << "[ok]";
}
} // example_01


#include <type_traits>
#include <iostream>
#include <cassert>
namespace example_02 { // -> base use of the "delete" keyword (for classes)
void run() {
    // arrange - act
    struct foo {
        foo(foo const&) = delete;
    };
    
    // assert
    assert(not std::is_copy_constructible_v<foo>); 
    
    std::cout << "[ok]";
}
} // example_02


#include <string_view>
#include <iostream>
namespace example_03 { // -> base use of the "delete" keyword (for standalone functions)

void func(int) = delete;
void func(std::string_view) { }
    
void run() {
    func("lorem ipsum");
    // func(42); // -> will not compile
    
    std::cout << "[ok]";
}
} // example_03


#include <type_traits>
#include <iostream>
namespace example_04 { // -> not copyable and not movable class
void run() {
    // arrage - act
    class foo_not_copyable {
        public:
            foo_not_copyable() = default;
        
            foo_not_copyable(foo_not_copyable const&) = delete;
            foo_not_copyable& operator=(foo_not_copyable const&) = delete;
    };
    
    // assert
    assert(not std::is_copy_constructible_v<foo_not_copyable>);
    assert(not std::is_move_constructible_v<foo_not_copyable>);
    
    std::cout << "[ok]";
}    
} // example_04


#include <type_traits>
#include <memory>
#include <iostream>
#include <cassert>
namespace example_05 { // -> not copyable but movable
void run() {
    // arrange - act
    struct Data {};
    class data_wrapper {
        public:
            // ctor/dtor
            data_wrapper(Data *data = nullptr) : data_{data} {}
            ~data_wrapper() { delete data_; }
        
            // copy semantics
            data_wrapper(data_wrapper const&) = delete;
            data_wrapper& operator=(data_wrapper const&) = delete;
        
            // move semantics 
            data_wrapper(data_wrapper&& other) : data_{ std::move(other.data_) } { other.data_ = nullptr; }
            data_wrapper& operator=(data_wrapper&& other) {
                if (&other != this) {
                    delete data_;
                    data_ = std::move(other.data_);
                    other.data_ = nullptr;
                }
                
                return *this;
            }
            
        private:
            Data *data_;
    };
    
    // assert
    assert(not std::is_copy_constructible_v<data_wrapper>);
    assert(std::is_move_constructible_v<data_wrapper>);
    
    std::cout << "[ok]";
}
} // example_05


#include <iostream>
namespace example_06 { // -> ensure a function is called only with object of a specific type
    
template <typename T>
void run(T) = delete;
    
void run(long) { }    
    
void run() {
    run(42L);
    // run(42); // -> will not compile
    // run("lorem ipsum"); // -> will not compile
    
    std::cout << "[ok]";
}    
} // example_06


#include <type_traits>
#include <iostream>
#include <cassert>
namespace example_07 {
    
struct foo {
    foo() = default;
    inline foo& operator=(foo const &);
    
    int val; 
};
inline foo& foo::operator=(foo const&) = default;
    
void run() {
    foo f1{}, f2{};
    f1.val = 42;
    f2 = f1;
    
    assert(42 == f2.val);
    assert(std::is_copy_constructible_v<foo>);
    assert(std::is_copy_assignable_v<foo>);
    
    std::cout << "[ok]";
}
} // example_07



#include <iostream>
int main() {
    std::cout << "example_01 => " << std::endl; example_01::run(); std::cout << std::endl;
    std::cout << "example_02 => " << std::endl; example_02::run(); std::cout << std::endl;
    std::cout << "example_03 => " << std::endl; example_03::run(); std::cout << std::endl;
    std::cout << "example_04 => " << std::endl; example_04::run(); std::cout << std::endl;
    std::cout << "example_05 => " << std::endl; example_05::run(); std::cout << std::endl;
    std::cout << "example_06 => " << std::endl; example_06::run(); std::cout << std::endl;
    std::cout << "example_07 => " << std::endl; example_07::run(); std::cout << std::endl;
    
    return 0;
}