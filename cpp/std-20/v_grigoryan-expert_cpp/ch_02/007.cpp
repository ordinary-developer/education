#include <iostream>
#include <random>

int doubleIt(const int num) { return num * 2; }

constexpr int tripleIt(const int num) { return num * 3; }

void func1() {
    const int doubled = doubleIt(42);
    const int tripled = tripleIt(42);
    
    std::mt19937 engine{ std::random_device{}()};
    std::uniform_int_distribution<std::mt19937::result_type> distribution{1, 5};
    
    int test{0};
    test = distribution(engine);
    const int anotherTripled = tripleIt(test);    
}

void func2() {
    const int doubled = doubleIt(42);
    const int tripled = 126;

    std::mt19937 engine{ std::random_device{}() };
    std::uniform_int_distribution<std::mt19937::result_type> distribution{1, 5};

    int test{0};
    test = distribution(engine);
    const int anotherTripled = tripleIt(test);    
}


int main() {
    func1();
    func2();
}
