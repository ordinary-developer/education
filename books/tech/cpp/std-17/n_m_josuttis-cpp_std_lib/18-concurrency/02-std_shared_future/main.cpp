#include <future>
#include <thread>
#include <chrono>
#include <exception>
#include <stdexcept>
#include <iostream>

int queryNumber() {
    std::cout << "read number: ";
    int num;
    std::cin >> num;
    
    if (not std::cin) 
        throw std::runtime_error{ "no number read" };
    
    return num;
}

void doSomething(char c, std::shared_future<int> const f)
{
    try {
        int const num = f.get();
        
        for (int i{0}; i < num; ++i) {
            std::this_thread::sleep_for(std::chrono::milliseconds{ 100 });
            std::cout.put(c).flush();
        }
    }
    catch (std::exception const& e) {
        std::cerr << "EXCEPTION in thread " << std::this_thread::get_id()
            << ": " << e.what() <<  std::endl;
    }
}

int main() {
    try {
        std::shared_future<int> const f = std::async(queryNumber);
        
        auto f1 = std::async(std::launch::async, doSomething, '.', f);
        auto f2 = std::async(std::launch::async, doSomething, '+', f);
        auto f3 = std::async(std::launch::async, doSomething, '*', f);
        
        f1.get();
        f2.get();
        f3.get();
    }
    catch (std::bad_alloc const& e) {
        std::cout << "memory for internal structures can not be allocated" << std::endl;    
    }
    catch (std::system_error const& e) {
        std::cout << "can't start the async" << std::endl;
    }    
    catch (std::exception const& e) {
        std::cout << "\nEXCEPTION: " << e.what() << std::endl;
    }
    return 0;
}
