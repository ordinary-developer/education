#include <random>
inline bool randomBool()
{
    const double chance = 0.5; // this is the chance of getting true, between 0 and 1;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::bernoulli_distribution dist(chance);
    return dist(mt);
}


#include <iostream>
#include <cstdlib>
void exit_handler_1() { std::cout << "exit handler 1" << '\n'; }
void exit_handler_2() { std::cout << "exit handler 2" << '\n'; }

void quick_exit_handler_1() { std::cout << "quick exit handler 1" << '\n'; }
void quick_exit_handler_2() { std::cout << "quick exit handler 2" << '\n'; }


#include <iostream>
#include <cstdlib>
namespace example_01 { // -> the "how to do it..." section

void run() {
    std::atexit(exit_handler_1);
    std::atexit(exit_handler_2);
    std::atexit([]() { std::cout << "exit handler 3" << '\n'; });
    
    std::at_quick_exit(quick_exit_handler_1);
    std::at_quick_exit(quick_exit_handler_2);
    std::at_quick_exit([]() { std::cout << "quick exit handler 3" <<  '\n'; });
    
    (randomBool() ? std::exit(0) : std::quick_exit(0));
}

} // example_01


#include <iostream>
#include <cstdlib>
namespace example_02 { // -> the "how it works..." section

void run() {
    struct static_foo {
        ~static_foo() { std::cout << "static foo destroyed!" << '\n'; }
        static static_foo* instance() {
            static static_foo obj{};
            return &obj;
        }
    };
    
    std::atexit(exit_handler_1);
    static_foo::instance();
    std::atexit(exit_handler_2);
    std::atexit([]() { std::cout << "exit handler 3" << '\n'; });
    
    std::exit(42);
}
} // example_02


#include <iostream>
int main() {
    std::cout << "example_01 / 02 -->" << std::endl;
    (randomBool() ? example_01::run() : example_02::run());
    std::cout << "-> ok" << std::endl << std::endl;
    
    return 0;
}
