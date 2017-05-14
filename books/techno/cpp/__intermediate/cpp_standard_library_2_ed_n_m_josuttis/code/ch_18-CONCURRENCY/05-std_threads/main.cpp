#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>


void doSomething(int number, char c) {
    try {
        std::default_random_engine randomEngine{c};
        std::uniform_int_distribution<int> distribution{ 10, 1000 };
        for (int i{0}; i < number; ++i) {
            std::this_thread::sleep_for(
                std::chrono::milliseconds{ distribution(randomEngine) });
            std::cout.put(c).flush();
        }
    }
    catch (std::exception const& e) {
        std::cerr << "[THREAD-EXCEPTION] " << "(thread "
                  << std::this_thread::get_id() << "): " << e.what()
                  << std::endl;
    }
    catch (...) {
        std::cerr << "[THREAD-EXCEPTION] " << "(thread "
                  << std::this_thread::get_id() << "): " << std::endl;
    }
}


int main() {
    try {
        std::thread t1(doSomething, 5, '-');
        std::cout << "[OK] " << "started fg thread " << t1.get_id() 
                  << std::endl;

        for (int i{0}; i < 5; ++i) {
            std::thread t{ doSomething, 10, 'a' + i };
            std::cout << "[OK] " << "detach started " << t.get_id()
                      << std::endl;
            t.detach();
        }

        std::cin.get();
        std::cout << "[OK] " << "join fg thread " << t1.get_id()
                  << std::endl;
        t1.join();
    }
    catch (std::exception const& e) {
        std::cerr << "[EXCEPTION] " << e.what() << std::endl;
    }

    return 0;
}
