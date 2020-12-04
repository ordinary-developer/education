#include <future>
#include <cmath>
#include <iostream>

double square_root(double x) {
    if (x < 0) {
        throw std::out_of_range("x < 0");
    }
    return sqrt(x);
}

int main() {
    std::future<double> f = std::async(square_root, -1);

    try {
        double y = f.get();
    }
    catch (std::out_of_range&) {
        std::cout << "the std::out_of_range has been caught"
                  << std::endl;
    }

    return 0;
}
