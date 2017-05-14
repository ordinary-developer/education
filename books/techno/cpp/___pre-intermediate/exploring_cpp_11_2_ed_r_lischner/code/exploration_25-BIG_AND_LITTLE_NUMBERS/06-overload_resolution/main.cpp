#include <iostream>

void print(signed char value) {
    std::cout << "print(signed char = " 
               << static_cast<int>(value) << ")\n";
}

void print(short value) {
    std::cout << "print(short = " << value << ")\n";
}

void print(int value) {
    std::cout << "print(int = " << value << ")\n";
}

void print(long value) {
    std::cout << "print(long = " << value << ")\n";
}


void guess(bool value) {
    std::cout << "guess(bool = " << value << ")\n";
}

void guess(int value) {
    std::cout << "guess(int = " << value << ")\n";
}

void guess(long value) {
    std::cout << "guess(long = " << value << ")\n";
}


void error(bool value) {
    std::cout << "error(bool = " << value << ")\n";
}

void error(long value) {
    std::cout << "error(long = " << value << ")\n";
}


int main() {
    signed char byte{ 10 };
    short shrt{ 20 };
    int i{ 30 };
    long lng{ 40 };

    print(byte);
    print(shrt);
    print(i);
    print(lng);

    guess(byte);
    guess(shrt);
    guess(i);
    guess(lng);

    // error(byte); // error
    // error(shrt); // error
    // error(i); // error
    error(lng);

    return 0;
}
