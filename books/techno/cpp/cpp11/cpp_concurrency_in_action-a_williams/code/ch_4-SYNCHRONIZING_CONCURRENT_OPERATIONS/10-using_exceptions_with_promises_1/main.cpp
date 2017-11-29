#include <future>
#include <cmath>

double square_root(double x) {
    if (x < 0) {
        throw std::out_of_range("x < 0");
    }
    return sqrt(x);
}

double calculate_value() {
    return square_root(-1);
}

int main() {
    std::promise<double> some_promise;
    try {
        some_promise.set_value(calculate_value());
    }
    catch (...) {
        some_promise.set_exception(std::current_exception());
    }

    return 0;
}
