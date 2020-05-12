#include <iostream>
#include <thread>
#include <stdexcept>
#include <exception>

void doSomeWork() {
    for (int i{0}; i < 5; ++i) {
        std::cout << i << std::endl;
    }
    std::cout << "Thread throwing a runtime_error exception ..."
              << std::endl;
    throw std::runtime_error{ "Exception from a thread" };
}

void threadFunction(std::exception_ptr& error) {
    try {
        doSomeWork();
    } catch (...) {
        std::cout << "Thread caught exception, returning exception ..."
                  << std::endl;
        error = std::current_exception();
    }
}

void doWorkInThread() {
    std::exception_ptr error{};
    std::thread t{ threadFunction, std::ref(error) };
    t.join();

    if (error) {
        std::cout << "Main thread received exception, rethrowing it..."
                  << std::endl;
        std::rethrow_exception(error);
    }
    else
        std::cout << "Main thread did not receive any exception."
                  << std::endl;
}

int main() {
    try {
        doWorkInThread();
    }
    catch (std::exception const& e) {
        std::cout << "Main function caught: '" << e.what() << "'"
                  << std::endl;
    }

    return 0;
}
