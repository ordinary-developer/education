#include <iostream>

template <class T>
T min(T a, T b) {
    if (a < b)
        return a;
    else if (b < a)
        return b;
    else
        return a;
}


int main() {
    int x1{ 10 }, y1{ 20 }, z1{ min(x1, y1) };

    int x2{ 10 };
    long y2{ 20 };
    // std::cout << min(x2, y2); // error here
    
    int x3{ 10 };
    long y3{ 20 };
    std::cout << min<long>(x3, y3) << std::endl;

    return 0;
}
