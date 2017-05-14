class CX {
    public:
        CX() = default;
        constexpr CX(int a, int b)
            : a_{a}, b_{b} { }

        constexpr int get_a() const { return a_; }
        constexpr int get_b() { return b_; }

        constexpr int foo() { return a_ + b_; }

    private:
        int a_, b_;
};

constexpr CX make_cx(int a) { return CX{a, 1}; }
constexpr CX half_double(CX old) {
    return CX{ old.get_a() / 2,
               old.get_b() * 2 };
}
CX si{ half_double(CX{42, 19}) };

constexpr int square(int x) { return x * x; }
constexpr int foo_squared(CX value) {
    return square(value.foo());
}
int array[foo_squared(half_double(make_cx(10)))];


int main() {
    return 0;
}
