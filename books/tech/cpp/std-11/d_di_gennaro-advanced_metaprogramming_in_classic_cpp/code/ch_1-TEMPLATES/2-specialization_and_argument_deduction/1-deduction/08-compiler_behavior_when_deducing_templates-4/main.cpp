#include <iostream>

template <int I>
class X { };

template <int I, typename T>
void g(X<I>, T x) { std::cout << "g1" << std::endl; }

template <typename T>
void g(X<0>, T x) { std::cout << "g2" << std::endl; }


int main() {
    double pi = 3.14;
    X<0> x;

    g<0>(x, pi); // calls the first g
    g(x, pi);    // calls the second g

    return 0;
}
