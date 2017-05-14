#include <algorithm>
#include <iostream>

class X {
    public:
        X() : data(new int[1'000'000]) {
            std::cout << "default constructor" << std::endl;
        }
        ~X() { 
            delete[] data;
            data = nullptr;
        }

        X(const X& other) : data(new int[1'000'000]) {
            std::cout << "copy constructor" << std::endl;
            std::copy(other.data, other.data + 1'000'000, data);
        }

        X(X&& other) : data(other.data) {
            std::cout << "move constructor" << std::endl;
            other.data = nullptr;
        }

    private:
        int* data;
};

void do_stuff(X&& x_) {
    X a(x_);
    X b(std::move(x_));
}

int main() {
    X x1;
    X x2 = std::move(x1);
    X x3 = static_cast<X&&>(x2);
    std::cout << "---------" << std::endl;

    do_stuff(X());
    std::cout << "---------" << std::endl;

    X x;
    // error
    //do_stuff(x);
    do_stuff(std::move(x));


    return 0;
}
