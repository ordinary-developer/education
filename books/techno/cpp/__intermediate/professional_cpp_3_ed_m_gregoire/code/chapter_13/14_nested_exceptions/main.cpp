#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>


class MyException : public std::exception {
    public:
        MyException(const char* msg) : mMsg(msg) { }
        virtual ~MyException() noexcept { }
        virtual const char* what() const noexcept override { return mMsg.c_str(); }

    private:
        std::string mMsg;
};

void doSomething() {
    try {
        throw std::runtime_error("Throwing a runtime_error exception");
    }
    catch (const std::runtime_error& e) {
        std::cout << __func__ << " caught a runtime_error" << std::endl;
        std::cout << __func__ << " throwing MyException" << std::endl;
        std::throw_with_nested(MyException("MyException with nested runtime_error"));
    }
}

auto main() -> int {
    try {
        doSomething();
    }
    catch (const MyException& e) {
        std::cout << __func__ << " caught MyException: " << e.what() << std::endl;

        const std::nested_exception* pNested = 
            dynamic_cast<const std::nested_exception*>(&e);

        if (pNested) {
            try {
                pNested->rethrow_nested();
            }
            catch (const std::runtime_error& e)  {
                std::cout << " Nested exception: " << e.what() << std::endl;
            }
        }
    }

    try {
        doSomething();
    }
    catch (const MyException& e) {
        std::cout << __func__ << " caught MyException: " << e.what() << std::endl;

        try {
            std::rethrow_if_nested(e);
        }
        catch (const std::runtime_error& e) {
            std::cout << " Nested Exception: " << e.what() << std::endl;
        }
    }

    return 0;
}

