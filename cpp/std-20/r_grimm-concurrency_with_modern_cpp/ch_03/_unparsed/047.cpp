#include <exception>
#include <future>
#include <iostream>
#include <thread>
#include <utility>

struct Div {
    void operator() (std::promise<int> && intPromise, int a, int b) {
        try {
            if (0 == b) {
                std::string errMsg = std::string("Illegal division by zero: ") +
                                     std::to_string(a) + "/" + std::to_string(b);
                throw std::runtime_error(errMsg);
            }
            intPromise.set_value(a / b);
        }
        catch (...) {
            intPromise.set_exception(std::current_exception());
        }
    }
};

void executeDivision(int nom, int denom) {
    std::promise<int> divPromise;
    std::future<int> divResult = divPromise.get_future();

    Div div;
    std::thread divThread(div, std::move(divPromise), nom, denom);

    try {
        std::cout << nom << "/" << denom << " = " << divResult.get() << std::endl;
    }  
    catch (std::runtime_error & e) {
        std::cout << e.what() << std::endl;
    }

    divThread.join();
}

int main() {
    std::cout << std::endl;

    executeDivision(20, 0);
    executeDivision(20, 10);

    std::cout << std::endl;
}
