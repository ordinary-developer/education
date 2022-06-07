#include <chrono>
#include <iomanip>
#include <iostream>
namespace pre_example { // -> "getting ready"

inline void printTime() {
    auto now = std::chrono::system_clock::now();
    auto stime = std::chrono::system_clock::to_time_t(now);
    auto ltime = std::localtime(&stime);

    std::cout << std::put_time(ltime, "%c");
}

void run() {
    printTime();   
}
} // pre_example


#include <chrono>
#include <iomanip>
#include <iostream>
#include <thread>
namespace example { // -> "how to do it"

inline void printTime() {
    auto now = std::chrono::system_clock::now();
    auto stime = std::chrono::system_clock::to_time_t(now);
    auto ltime = std::localtime(&stime);

    std::cout << std::put_time(ltime, "%c") << '\n';
}

void func1() { std::cout << "thread func without params" << '\n'; }

void func2(int const i, double const d, std::string const s) {
    std::cout << i << ", " << d << ", " << s << '\n';
}

void func3(int & i) { i *= 2; }

void func4() {
    using namespace std::chrono_literals;
    printTime();
    std::this_thread::sleep_for(2s);
    printTime();
}

void func5() {
    using namespace std::chrono_literals;
    printTime();
    std::this_thread::sleep_until(
        std::chrono::system_clock::now() + 2s);
    printTime();
}

void func6(std::chrono::seconds timeout) {
    auto now = std::chrono::system_clock::now();
    auto then = now + timeout;
    do {
        std::this_thread::yield();
    } while (std::chrono::system_clock::now() < then);
}

void run() {
    {
        std::thread t{};
    }

    {
        std::thread t{func1};
        t.join();
    }

    {
        std::thread t{[]() {
            std::cout << "thread func without params" << '\n';
        }};
        t.join();
    }

    {
        std::thread t{func2, 42, 42.0, "42"};
        t.join();
    }

    {
        int n = 42;
        std::thread t{func3, std::ref(n)};
        t.join();
        std::cout << n << '\n';
    }

    {
        std::thread t{func4};
        t.join();
    }

    {
        std::thread t{func5};
        t.join();
    }

    {
        std::thread t{func6, std::chrono::seconds{2}};
        t.join();
        printTime();
    }
}
} // example


#include <iostream>
#include <thread>
namespace post_example { // -> "how it works"
void run() {
    std::cout << "this thread id: " << std::this_thread::get_id() << std::endl;
}
} // post_example


#include <iostream>
int main() {
    std::cout << "[pre example] =>" << std::endl;
    pre_example::run();
    std::cout << std::endl << std::endl;
    
    std::cout << "[example] =>" << std::endl;
    example::run();
    std::cout << std::endl << std::endl;

    std::cout << "[post_example] =>" << std::endl;
    post_example::run();
    std::cout << std::endl << std::endl;
    
    return 0; 
}
