#include <future>
#include <thread>
#include <iostream>


int main() {
    int res;
    std::thread t([&]{ res = 2000 + 11; });
    t.join();
    std::cout << "[ .... ] res: " << res << std::endl;

    auto f = std::async([]{ return 2000 + 11; });
    std::cout << "[ .... ] f.get(): " << f.get() << std::endl;

    std::cout << std::endl;
}
