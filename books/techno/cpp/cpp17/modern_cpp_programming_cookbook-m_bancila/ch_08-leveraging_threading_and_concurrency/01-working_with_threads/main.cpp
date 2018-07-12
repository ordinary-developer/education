#include <chrono>
#include <ctime>
#include <iostream>
#include <iomanip>


inline void print_time() {
    auto now = std::chrono::system_clock::now();
    auto stime = std::chrono::system_clock::to_time_t(now);
    auto ltime = std::localtime(&stime);
    
    std::cout << std::put_time(ltime, "%c") << std::endl;
}

#include <thread>
namespace example_01 {
void run() {
    std::thread t{};    
}
} // example_01


#include <thread>
#include <iostream>
namespace example_02 {
void func() {
    std::cout << "thread func without parameters" << std::endl;
}    
    
void run() {
    std::thread t{ func };
    t.join();
}    
} // example_02


#include <thread>
#include <iostream>
namespace example_03 {
void run() {
    std::thread t{ []() {
        std::cout << "thread func without params" << std::endl;
    } };
    t.join();
}
} // example_03


#include <thread>
#include <iostream>
#include <string>
namespace example_04 {
void func(int const i, double const d, std::string const& s) {
    std::cout << i << ", " << d << ", " << s << std::endl;
}

void run() {
    std::thread t{ func, 42, 42., "42" };
    t.join();
}
} // example_04


#include <thread>
#include <iostream>
#include <string>
#include <functional>
namespace example_05 {
void func(int& i) {
    i *= 2;
}

void run() {
    int n{42};
    std::thread t{ func, std::ref(n) };
    t.join();
    std::cout << n << std::endl;
}
} // example_05


#include <thread>
#include <iostream>
namespace example_06 {
void func() {
    using namespace std::literals;
    print_time();
    std::this_thread::sleep_for(2s);
    print_time();
}

void run() {
    std::thread t{ func };
    t.join();
}
} // example_06


#include <thread>
#include <chrono>
#include <iostream>
namespace example_07 {
void func() {
    using namespace std::literals;
    print_time();
    std::this_thread::sleep_until(
        std::chrono::system_clock::now() + 2s);
    print_time();        
}
void run() {
    std::thread t{ func };
    t.join(); 
}
} // example_07


#include <thread>
#include <chrono>
namespace example_08 {
void func(std::chrono::seconds const & timeout) {
    auto const now = std::chrono::system_clock::now();
    auto const then = now + timeout;
    do {
        std::this_thread::yield();
    } while (std::chrono::system_clock::now() < then);
}
void run() {
    print_time();
    std::thread t{ func, std::chrono::seconds(2) };
    t.join();
    print_time();
}
} // example_08


#include <functional>
#include <array>
#include <cstddef>
#include <string>
int main() {
    using FuncDelegate = std::function<void(void)>;
    int const N = 8;
    std::array<FuncDelegate, N> const funcs{ {
        example_01::run, example_02::run, example_03::run, 
        example_04::run, example_05::run, example_06::run,
        example_07::run, example_08::run } };
    
    std::size_t index{ 1 };
    for (auto const func : funcs) {
        std::string const exampleName = "example_" + std::to_string(index++);
        std::cout << exampleName << " =>" << std::endl;
        func();
        std::cout << "[ok] - " << exampleName << std::endl << std::endl;
    }
        
    return 0;
}
