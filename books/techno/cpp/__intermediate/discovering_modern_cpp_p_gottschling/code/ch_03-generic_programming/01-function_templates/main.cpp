#include <iostream>
namespace example01_functionTemplates{

int maxFunc(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

template <typename T>
T max(T a, T b) {
    if (a > b)
        return a;
    else
        return b;
}

void run() {
    std::cout << maxFunc(3, 4) << std::endl;
    std::cout << max(3, 4) << std::endl;
    std::cout << max(3l, 4l) << std::endl;
    std::cout << max(3.0, 4.0) << std::endl;
    std::cout << max(3.0, 4.0) << std::endl;

    unsigned u1{2}, u2{8};
    std::cout << max(u1, u2) << std::endl;
    std::cout << max(u1 * u2, u1 + u2) << std::endl;

    std::cout << max<float>(8.1, 9.3) << std::endl;
}
} // example01

#include <memory>
namespace example02_valueParameters {

template <typename TPara>
void f1(TPara p) { (void)p; }

template <typename TPara>
void f2(const TPara& p) { (void)p; }

template <typename TPara>
void f3(TPara& p) { (void)p; }

template <typename TPara>
void f4(TPara&& p) { (void)p; }

template <typename TPara>
void f5(TPara&& p) {
    f4(std::forward<TPara>(p));
}

void run() {
    int i{0};
    int& j{i};
    const int& k{i};
    std::unique_ptr<int> up{};

    f1(3); // TPara is int
    f1(i); // TPara is int
    f1(j); // TPara is int
    f1(k); // TPara is int
    f1(std::move(up));

    f2(3); // TPara is int 
    f2(j); // TPara is int
    f2(k); // TPara is int
    f2(up);

    // f3(3);  // refused 
    f3(i); // TPara is int, p is int&
    f3(j); // TPara is int, p is int&
    f3(k); // TPara is const int, p is const int&

    f4(3); // TPara is int, p is int&&
    f4(std::move(i)); // TPara is int, p is int&&
    f4(std::move(up));
    f4(i); // TPara is int&, p is int&
    f4(j); // TPara is int&, p is int&

}
} // example02

#include <iostream>
namespace example03_mixingTypes {

template <typename T>
T max(T a, T b) { return a > b ? a : b; }

void run() {
    unsigned u1{2};
    int i{3};
    std::cout << max(static_cast<int>(u1), i) << std::endl;
    std::cout << max<int>(u1, i) << std::endl;
}
} // example03

int main() {
    example01_functionTemplates::run();
    example02_valueParameters::run();
    example03_mixingTypes::run();

    return 0;
}
