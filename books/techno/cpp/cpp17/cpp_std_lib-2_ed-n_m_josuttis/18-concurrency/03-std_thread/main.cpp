#include <thread>
#include <chrono>
#include <random>
#include <exception>
#include <iostream>

void doSomething(int num, char c) noexcept {
    try {
        std::default_random_engine dre{ (long unsigned int)(42 * c) };
        std::uniform_int_distribution<int> id{ 10, 1000 };
        for (int i{0}; i < num; ++i) {
            std::this_thread::sleep_for(std::chrono::milliseconds{ id(dre) });
            std::cout.put(c).flush();
        }
    }
    catch (std::exception const& e) {
        std::cerr << "THREAD-EXCEPTION (thread "
            << std::this_thread::get_id() << "): " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "THREAD-EXCEPTION (thred "
            << std::this_thread::get_id() << ")" << std::endl;
    }
}

int main() {
    try {
        std::thread t1{ doSomething, 5, '.' };
        std::cout << "- started fg thread " << t1.get_id() << std::endl;
        
        for (int i{0}; i < 5; ++i) {
            std::thread t{ doSomething, 10, 'a' + i };
            std::cout << "- detach started bg thread " << t.get_id() << std::endl;
            t.detach();
        }
        
        std::cin.get();
        
        std::cout << "- join fg thread " << t1.get_id() << std::endl;
        t1.join();
    }
    catch (std::system_error const& e) {
        std::cerr << "can't start the thread " << e.what() << std::endl;
    }
    catch (std::exception const& e) {
        std::cerr << "EXCEPTION: " << e.what() << std::endl;
    }
    return 0;
}
