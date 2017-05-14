template <typename T>
class outer {
    public:
        template <typename X>
        class inner {
            // use freely both X and T
        };
};

template <typename Y>
void f() {
    outer<Y>::inner<double> x1; // error, but may be passed
    outer<Y>::template inner<double> x2; // correct
}

int main() {
    outer<int>::inner<double> a; // correct
    
    return 0;
}
