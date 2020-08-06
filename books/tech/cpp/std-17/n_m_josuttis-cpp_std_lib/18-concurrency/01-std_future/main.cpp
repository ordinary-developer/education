#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>
namespace example_01 { // <- std::future - base review

int doSomething(char c) {
    std::default_random_engine dre{ (long unsigned int)c };
    std::uniform_int_distribution<int> id{ 10, 1000 };
    
    for (int i{0}; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds{ id(dre) });
        std::cout.put(c).flush();
    }
    
    return c;
}

int func1() { return doSomething('.'); }
int func2() { return doSomething('+'); }

void run() {
    {    
        try {
            std::future<int> result1{ std::async(func1) };
            int const result2 = func2();
            int const result = result1.get() + result2;
    
            std::cout << "\nresult of func1() + func2(): (1-st iteration): " << result << std::endl;
        }
        catch (std::bad_alloc const& e) {
            std::cout << "memory for internal structures can not be allocated" << std::endl;    
        }
        catch (std::exception const& e) {
            std::cout << "get has an exception" << std::endl;    
        }
    }
    
    {
        try {
            std::future<int> result1{ std::async(std::launch::async, func1) };
            int const result2 = func2();
            int const result = result1.get() + result2;
    
            std::cout << "\nresult of func1() + func2(): (2-nd iteration): " << result << std::endl;
        }
        catch (std::bad_alloc const& e) {
            std::cout << "memory for internal structures can not be allocated" << std::endl;    
        }
        catch (std::system_error const& e) {
            std::cout << "can't start the async" << std::endl;
        }
        catch (std::exception const& e) {
            std::cout << "get has an exception" << std::endl;
        }
    }
    
    {
        try {
            std::future<int> result1{ std::async(std::launch::deferred, func1) };
            int const result2 = func2();
            int const result = result1.get() + result2;
    
            std::cout << "\nresult of func1() + func2(): (3-d iteration): " << result << std::endl;
        }
        catch (std::bad_alloc const& e) {
            std::cout << "memory for internal structures can not be allocated" << std::endl;    
        }
        catch (std::exception const& e) {
            std::cout << "get has an exception" << std::endl;
        }
    }
}
} // example_01


#include <chrono>
#include <random>
#include <thread>
#include <future>
#include <iostream>
namespace example_02 { // <- std::future and std::launch::deferred

bool getRandBool() {
    std::chrono::system_clock::time_point tp =
        std::chrono::system_clock::now();
    std::chrono::system_clock::duration dtn =
        tp.time_since_epoch();
        
    long unsigned int const seed = dtn.count() * std::chrono::system_clock::period::num /
        std::chrono::system_clock::period::den;
        
    std::default_random_engine dre{ seed };
    std::uniform_int_distribution<int> id{ 0, 1 };
    
    return (bool)id(dre);
}

int func1() {
    std::cout << "func1 is performing\n";
    std::this_thread::sleep_for(std::chrono::milliseconds{ 5000 });
    
    return 5000;
}

int func2() {
    std::cout << "func2 is performing\n";
    std::this_thread::sleep_for(std::chrono::milliseconds{ 7000 }); 
    
    return 7000;
}

void run() {
    auto f1 = std::async(std::launch::deferred, func1);
    auto f2 = std::async(std::launch::deferred, func2);
    
    try {
        auto const val = (getRandBool() ? f1.get() : f2.get());
        (void)val;
    }
    catch (std::bad_alloc const& e) {
        std::cout << "memory for internal structures can not be allocated" << std::endl;    
    }
    catch (std::exception const& e) {
        std::cout << "get has an exception" << std::endl;
    }
}
} // example_02


#include <future>
#include <exception>
#include <iostream>
namespace example_03 { // <- std::future and exceptions
    
void task() {
    throw std::runtime_error{ "error during task execution" };    
}
    
void run() {
    try {
        std::cout << "starting 2 tasks" << std::endl;
        std::cout << "- task1: a task with an exception" << std::endl;
        std::cout << "- task2: wait for <return> and then for task1" << std::endl;
    
        auto f = std::async(task);
    
        std::cin.get();
    
        std::cout << "\nwait for the end of task1: " << std::endl;
        
        f.get();
    } 
    catch (std::bad_alloc const& e) {
        std::cout << "memory for internal structures can not be allocated" << std::endl;    
    }
    catch (std::exception const& e) { 
        std::cerr << "excepton from get() has been called" << std::endl;
        std::cerr << "EXCEPTION - " << e.what() << std::endl;
    }
}
} // example_03


#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <iostream>
namespace example_04 { // <- std::future and wait()
    
void func() {
    std::default_random_engine dre{42};
    std::uniform_int_distribution<int> id{ 10, 1000 };
    
    for (int i{0}; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds{ id(dre) });
        std::cout.put('-').flush();
    }
    std::cout.put('\n').flush();
}
    
void run() {
    {
        try {
            auto f = std::async(func);
            f.wait();
        }
        catch (std::bad_alloc const& e) {
            std::cout << "memory for internal structures can not be allocated" << std::endl;    
        }
    }
    
    {
        try {
            auto f = std::async(std::launch::async, func);
            f.wait();
        }
        catch (std::system_error const& e) {
            std::cout << "can't start the async" << std::endl;
        }
        catch (std::bad_alloc const& e) {
            std::cout << "memory for internal structures can not be allocated" << std::endl;    
        }
    }
    
    {
        try {
            auto f = std::async(std::launch::deferred, func);
            f.wait();
        }
        catch (std::bad_alloc const& e) {
            std::cout << "memory for internal structures can not be allocated" << std::endl;    
        }
    }
}    
} // example_04


#include <future>
#include <thread>
#include <chrono>
#include <iostream>
namespace example_05 { // <- std::future and wait_until()
    
int quickComputation() { return 42; }
    
int accurateComputation() {    
    std::default_random_engine dre{42};
    std::uniform_int_distribution<int> id{ 10, 1000 };
    
    for (int i{0}; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds{ id(dre) });
        std::cout.put('-').flush();
    }
    std::cout.put('\n').flush();
    
    return 43;
}
    
std::future<int> f{};
int bestResultInTime() {
    try {
        auto const tp = std::chrono::system_clock::now() + std::chrono::milliseconds{ 3000 };
    
        f = std::async(std::launch::async, accurateComputation);
        
        return (std::future_status::ready == f.wait_until(tp)
            ? f.get() : quickComputation());
    }
    catch (std::system_error const& e) {
        std::cout << "can't start the async" << std::endl;
    }
    catch (std::bad_alloc const& e) {
        std::cout << "memory for internal structures can not be allocated" << std::endl;    
    }
    catch (std::exception const& e) {
        std::cout << "exception from get() has been called" << std::endl;
    }
    
    return 44; // if an exception was caught
}    
   
void run() {
    std::cout << "starting \"speculative\" execution\n";
    
    int const result = bestResultInTime();
   
    std::cout << "\nresult = " << result << std::endl;
}
    
} // examaple_05


#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <exception>
#include <iostream>
namespace example_06 {  // <- std::future and wait_for()
    
void doSomething(char c) {
    std::default_random_engine dre{ (long unsigned int)c };
    std::uniform_int_distribution<int> id{ 10, 1000 };
    
    for (int i{0}; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds{ id(dre) });
        std::cout.put(c).flush();
    }
}
    
void run() {
    try {
        std::cout << "starting 2 operations asynchronously" << std::endl;
        
        auto f1 = std::async([]{ doSomething('.'); });
        auto f2 = std::async([]{ doSomething('+'); });
        
        if (std::future_status::deferred != f1.wait_for(std::chrono::seconds{0}) and
            std::future_status::deferred != f2.wait_for(std::chrono::seconds{0}))
        {
            while (std::future_status::ready != f1.wait_for(std::chrono::seconds{0}) or 
                std::future_status::ready != f2.wait_for(std::chrono::seconds{0}))
            {
                std::this_thread::yield();
            }
        }
        std::cout.put('\n').flush();
        
        f1.get();
        f2.get();
    }
    catch (std::bad_alloc const& e) {
        std::cout << "memory for internal structures can not be allocated" << std::endl;    
    }
    catch (std::exception const& e) {
        std::cout << "\nEXCEPTION: " << e.what() << std::endl;
    }
    std::cout << "\ndone" << std::endl;
}    
    
} // example_06 


#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <exception>
#include <iostream>
namespace example_07 { // <- std::future and passing arguments to it
    
struct X {
    X() : value_{42} {}
    X(const X& other) { value_ = other.value_;  std::cout << "copy ctor\n"; }
    
    void mem(int num) { value_ = num; }
    
    int value_;
};
    
void doSomething(char c) {
    std::default_random_engine dre{ (long unsigned int)c };
    std::uniform_int_distribution<int> id{ 10, 1000 };
    
    for (int i{0}; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds{ id(dre) });
        std::cout.put(c).flush();
    }
}
    
void run() {
    try {
        {
            auto f = std::async([]{ doSomething('.'); });
            f.get();
            std::cout.put('\n').flush();
        }
        
        {
            char c = '@';
            
            auto f1 = std::async([=]{ doSomething(c); });
            f1.get();
            std::cout.put('\n').flush();
            
            auto f2 = std::async(doSomething, c);
            f2.get();
            std::cout.put('\n').flush();
        }
        
        {
            char c = '@';
           
            auto f1 = std::async([&]{ doSomething(c); });
            f1.get();
            std::cout.put('\n').flush();
                                  
            auto f2 = std::async(doSomething, std::ref(c));
            f2.get();                         
            std::cout.put('\n').flush();
        }
        
        {
            X x{};
            
            auto f1 = std::async(&X::mem, x, 45);
            f1.get();
            std::cout << x.value_ << std::endl;
            std::cout.put('\n').flush();
            
            auto f2 = std::async(&X::mem, std::ref(x), 45);
            f2.get();
            std::cout << x.value_ << std::endl;
            std::cout.put('\n').flush();
        }
    }
    catch (std::bad_alloc const& e) {
        std::cout << "memory for internal structures can not be allocated" << std::endl;    
    }
    catch (std::exception const& e) {
        std::cout << "\nEXCEPTION: " << e.what() << std::endl;
    }
    
    std::cout.put('\n').flush();
}    
} // example_07


int main() {
    std::cout << "example 01 =>\n";
    example_01::run();
    std::cout << "[ok] example 01\n\n";
    
    std::cout << "example 02 =>\n";
    example_02::run();
    std::cout << "[ok] example 02\n\n";
    
    std::cout << "example 03 =>\n";
    example_03::run();
    std::cout << "[ok] example 03\n\n";
    
    std::cout << "example 04 =>\n";
    example_04::run();
    std::cout << "[ok] example 04\n\n";
    
    std::cout << "example 05 =>\n";
    example_05::run();
    std::cout << "before wait()\n";
    //example_05::f.wait();
    example_05::f.~future();
    std::cout << "after wait()\n";
    std::cout << "[ok] example 05\n\n";
    
    std::cout << "exapmle 06 =>\n";
    example_06::run();
    std::cout << "[ok] example 06\n\n";
    
    std::cout << "example 07 =>\n";
    example_07::run();
    std::cout << "[ok] example 07\n\n";
    
    return 0;
}
