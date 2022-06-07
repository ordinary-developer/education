#include <stdexcept>
#include <iostream>
namespace example01 {

class MyCustomException : public std::exception {
    virtual const char* what() const noexcept override {
        return "Provide some details about what was going wrong here";
    }
};

void run() {
    try {
        throw MyCustomException{};
    }
    catch (std::exception const& ex) {
        std::cerr << ex.what() << std::endl;
    }
}

}

#include <stdexcept>
#include <iostream>
#include <string>
namespace example02 {

class DivisionByZeroException : public std::exception {
    public:
        DivisionByZeroException() = delete;

        explicit DivisionByZeroException(int const dividend) {
            buildErrorMessage(dividend);
        }

        virtual const char* what() const noexcept override {
            return errorMessage_.c_str();
        }

    private:
        void buildErrorMessage(int const dividend) {
            errorMessage_ = "A division with dividend = ";
            errorMessage_ += std::to_string(dividend);
            errorMessage_ += ", and divisor = 0, is not allowed"
                             " (Division by zero)";
        }

        std::string errorMessage_;
};

int divide(int const dividend, int const divisor) {
    if (0 == divisor)
        throw DivisionByZeroException{ dividend };
    return dividend / divisor;
}

void run() {
    try {
        divide(10, 0);
    }
    catch (DivisionByZeroException const& ex) {
        std::cerr << ex.what() << std::endl;
    }
}

}

int main() {
    example01::run();
    example02::run();

    return 0;
}
