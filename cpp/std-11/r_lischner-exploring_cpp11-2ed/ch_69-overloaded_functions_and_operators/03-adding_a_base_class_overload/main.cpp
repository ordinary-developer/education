#include <iostream>

class base {
    public:
        void print(int x) { std::cout << "int: " << x << '\n'; }
        void print(long x) { std::cout << "long: " << x << '\n'; }
};

class derived : public base {
    public:
        void print(double x) { std::cout << "double: " << x << '\n'; }
        using base::print;
};

int main() {
    derived d{};
    d.print(3);
    d.print(3.0);
    d.print(3L);

    return 0;
}
