class CX {
    public:
        CX() = default;
        CX(int a, int b) : a_{a}, b_{b} { }

        int get_a() const { return a_; }
        int get_b() const { return b_; }

        int foo() const { return a_ + b_; }

    private:
        int a_, b_;
};

constexpr CX create_cx() { return CX{}; }

constexpr CX clone(CX value) { return value; }

int main() {
    return 0;
}
