#include <thread>
#include <future>
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <functional>
#include <utility>


void doSomething(std::promise<std::string>& p) {
    try {
        std::cout << "read char ('x' for exception): ";
        char c = std::cin.get();
        if ('x' == c)
            throw std::runtime_error{ std::string{"char "} + c + " read" };

        std::string s = std::string{"char "} + c + " processed";
        p.set_value(std::move(s));
    }
    catch (...) {
        p.set_exception(std::current_exception());
    }
}

int main() {
    try {
        std::promise<std::string> p{};
        std::thread t{ doSomething, std::ref(p) };
        t.detach();
        std::future<std::string> f{ p.get_future() };
        std::cout << "result: " << f.get() << std::endl;
    }
    catch (std::exception const& e) {
        std::cerr << "EXCEPTION " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "EXCEPTION " << std::endl;
    }

    return 0;
}
