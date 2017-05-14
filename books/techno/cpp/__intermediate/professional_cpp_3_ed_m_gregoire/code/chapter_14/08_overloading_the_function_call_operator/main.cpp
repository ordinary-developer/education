#include <string>
#include <iostream>


class FunctionObject {
    public:
        int operator () (int inParam);
        void operator () (std::string& str) { }
        int doSquare(int inParam);
};

int FunctionObject::operator () (int inParam) {
    return doSquare(inParam);
}

int FunctionObject::doSquare(int inParam) {
    return inParam * inParam;
}

auto main() -> int {
    int x = 3, xSquared, xSquaredAgain;

    FunctionObject square;

    xSquared = square(x);
    xSquaredAgain = square.doSquare(x);

    std::cout << xSquared << std::endl;
    std::cout << xSquaredAgain << std::endl;

    return 0;
}
