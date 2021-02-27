#include <cassert>
namespace test {

int ask() { return 42; }

typedef decltype(ask)* func_ptr;

class convertible_to_func_ptr {
    public:
        operator func_ptr() const { return ask; }
};

void run() {
    auto ask_ptr = &ask;
    assert(42 == ask_ptr());

    auto& ask_ref = ask;
    assert(42 == ask_ref());

    convertible_to_func_ptr ask_wrapper{};
    assert(42 == ask_wrapper());
}

} // test

#include <iostream>
int main() {
    std::cout << "test => [ok]" << std::endl; test::run(); 
    

    return 0;
}
