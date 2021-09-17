#include <chrono>
#include <iostream>
namespace example_01 { // the "how to do it" section

void func(int const count = 100000000) { for (int i = 0; i < count; ++i); }

void run() {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto diff = std::chrono::high_resolution_clock::now() - start;   
    
    std::cout 
        << std::chrono::duration<double, std::milli>(diff).count() << "ms" << '\n';
    std::cout
        << std::chrono::duration<double, std::nano>(diff).count() << "ns" << '\n';
}
} // example_01


#include <chrono>
#include <functional>
#include <type_traits>
#include <iostream>
namespace example_02 { // the "how it works" section
    
void func(int const count = 100000000) { for (int i = 0; i < count; ++i); }
    
template <typename T>
void print_clock() {
    std::cout << "precision: "
        << (1000000.0 * double(T::period::num)) / (T::period::den)
        << '\n';
    std::cout << "steady: " << T::is_steady << '\n';
}

template <typename Time = std::chrono::microseconds,
          typename Clock = std::chrono::high_resolution_clock>
struct perf_timer {
    template <typename F, typename... Args>
    static Time duration(F&& f, Args... args) {
        auto start = Clock::now();
        std::invoke(std::forward<F>(f), std::forward<Args>(args)...);
        auto end = Clock::now();
        
        return std::chrono::duration_cast<Time>(end - start);
    }
};

void run() {
    {
        print_clock<std::chrono::system_clock>();
        print_clock<std::chrono::high_resolution_clock>();
        print_clock<std::chrono::steady_clock>();        
    }
    
    {
        auto t = perf_timer<>::duration(func, 100000000);
        std::cout << std::chrono::duration<double, std::milli>(t).count() << "ms" << '\n';
        std::cout << std::chrono::duration<double, std::nano>(t).count() << "ns" << '\n';
    }
    
    {        
        auto t1 = perf_timer<std::chrono::nanoseconds>::duration(func, 100000000);
        auto t2 = perf_timer<std::chrono::microseconds>::duration(func, 100000000);
        auto t3 = perf_timer<std::chrono::milliseconds>::duration(func, 100000000);
        
        std::cout
            << std::chrono::duration<double, std::micro>(t1 + t2 + t3).count() << "us" << '\n';
    }
}    

} // example_02


#include <iostream>
int main() {
    std::cout << "example 01 => [ok]" << std::endl; example_01::run(); std::cout << std::endl << std::endl;
    std::cout << "example 02 => [ok]" << std::endl; example_02::run(); std::cout << std::endl << std::endl;
    
    return 0;
}