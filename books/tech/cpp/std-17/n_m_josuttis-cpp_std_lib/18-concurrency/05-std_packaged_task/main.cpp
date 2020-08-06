#include <thread>
#include <future>
#include <chrono>
#include <iostream>


int compute() {
    std::this_thread::sleep_for(std::chrono::milliseconds{ 3000 });
    return 42;
}

int main() {
    try {
        std::packaged_task<int(void)> task{ compute };
        std::future<int> f = task.get_future();
    
        task();
    
        int const res = f.get();
        std::cout << "result = " << res << std::endl;
    }
    catch (std::exception const& e) {
        std::cerr << "exception in f.get() " << e.what() << std::endl;
    }
                           
    return 0;
}
