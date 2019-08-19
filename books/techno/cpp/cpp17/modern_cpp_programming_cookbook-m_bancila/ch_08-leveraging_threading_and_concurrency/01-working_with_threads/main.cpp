#include <chrono>
#include <iomanip>
#include <iostream>
#include <ctime>
inline void print_time() {
    auto const& now = std::chrono::system_clock::now();
    auto const& stime = std::chrono::system_clock::to_time_t(now);
    auto const& ltime = std::localtime(&stime);
    
    std::cout << std::put_time(ltime, "%c") << std::endl;
}


#include <thread>
namespace example_01 { // <- thread_without_starting
void run() {
    std::thread{};    
}
} // example_01


#include <thread>
namespace example_02 { // <- thread func without params and with a free function
    
void func() {
    std::cout << "thread func without params" << std::endl;
}
    
void run() {
    std::thread{ func }.join();
}
} // example_02


#include <thread>
namespace example_03 { // <- thread func without params and with a lambda
void run() {
    std::thread{ [](){
        std::cout << "thread func without params" << std::endl;
    }}.join();
}    
} // example_03


#include <thread>
#include <string>
#include <iostream>
namespace example_04 { // <- thread func with params
    
void func(int const i, double const d, std::string const s) {
    std::cout << i << ", " << d << ", " << s << std::endl;
}
    
void run() {
    std::thread{ func, 42, 42.0, "42" }.join();
}    
} // example_04


#include <thread>
#include <functional>
#include <iostream>
namespace example_05 { // <- thread and passing args by reference

void func(int& i) { i *= 2; }
    
void run() {
    int n{42};
    std::thread{ func, std::ref(n) }.join();
    std::cout << n << std::endl;
}
    
} // example_05


#include <thread>
#include <chrono>
namespace example_06 { // <- suspending a thread for specified time
    
void func() {
    using namespace std::literals;
    print_time();
    std::this_thread::sleep_for(2s);
    print_time();
}
    
void run() {
    std::thread{ func }.join();    
}
} // example_06


#include <thread>
#include <chrono>
namespace example_07 { // <- suspending a thread until specified time
    
void func() {
    using namespace std::literals;
    print_time();
    std::this_thread::sleep_until(
        std::chrono::system_clock::now() + 2s);
    print_time();
}

void run() {
    std::thread{ func }.join();
}
} // example_07


#include <thread>
#include <chrono>
namespace example_08 { // <- reshedule thread execution to allow another thread run
    
void func(std::chrono::seconds const timeout) {
    auto const now = std::chrono::system_clock::now();
    auto const then = now + timeout;
    do {
        std::this_thread::yield();
    } while (std::chrono::system_clock::now() < then);
}
    
void run() {
    print_time();
    std::thread{ func, std::chrono::seconds{2} }.join();
    print_time();
}
} // example_08


#include <functional>
#include <cstddef>
#include <string>
#include <iostream>
int main() {
    using FuncDelegate = std::function<void(void)>;
    
    FuncDelegate const funcs[] {
        example_01::run, example_02::run, example_03::run, example_04::run,
        example_05::run, example_06::run, example_07::run, example_08::run
    };
    
    unsigned int index{1};
    for (auto const& func : funcs) {
        std::string const exampleName = "example_" + std::to_string(index++);
        std::cout << exampleName << " =>\n";
        func();
        std::cout << "[ok] - " << exampleName << "\n\n";
    }
    return 0;
}
