#include <iostream>

class base {
    public:
        void print(int x) { std::cout << "int: " << x << '\n'; }
};

class derived : public base {
    public:
        void print(double x) { std::cout << "double: " << x << '\n'; }
};

int main() {
    derived d{};
    d.print(3);
    d.print(3.0);
    d.print(3.3);
    d.base::print(3);
    d.base::print(3.0);
    d.base::print(3.3);

    return 0;
}
