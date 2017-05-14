template <typename T>
class something { };

template <template <typename T> class X>
class example {
    X<int> x1_;
    X<double> x2_;
};

// "class" and "typename" are note equiavlent here:
// template <template <typename T> typename X> // error

typedef example<something> some_example;

int main() {
    return 0;
}
