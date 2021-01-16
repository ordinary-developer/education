#include <thread>
#include <future>
#include <mutex>
#include <chrono>
#include <iostream>

namespace workspace {
    
std::mutex g_ioMutex{};    
    
void do_something() {
    // simulate a long running operation
    {
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(2s);
    }
    
    std::lock_guard<std::mutex> lock{ g_ioMutex };
    std::cout << "operation 1 done" << std::endl;
}
    
void do_something_else() {
    // simulate a long running operation
    {
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(1s);
    }
    
    std::lock_guard<std::mutex> lock{ g_ioMutex };
    std::cout << "operation 2 done" << std::endl;
}    
    
int compute_something() {
    // simulate a long running operation
    {
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(2s);
    }
    
    return 42;
}    
    
int compute_something_else() {
    // simulate a long running operation
    {
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(1s);
    }
    
    return 24;
}
    
void run() {
    {
        auto f = std::async(std::launch::async, do_something);
        
        do_something_else();
        
        f.wait();
        
        std::cout << "all done" << std::endl;
    }
    
    {
        auto f = std::async(std::launch::async, compute_something);
        
        auto value = compute_something_else();
        value += f.get();
        
        std::cout << value << std::endl;
    }
    
    {
        auto f = std::async(std::launch::async, do_something);
        while (true) {
            using namespace std::chrono_literals;
            auto const status = f.wait_for(500ms);
            
            if (std::future_status::ready == status)
                break;
            
            std::cout << "waiting ..." << std::endl;
        }
        std::cout << "done" << std::endl;
    }
}
    
} // workspace


int main() {
    workspace::run();
    
    return 0;
}
    