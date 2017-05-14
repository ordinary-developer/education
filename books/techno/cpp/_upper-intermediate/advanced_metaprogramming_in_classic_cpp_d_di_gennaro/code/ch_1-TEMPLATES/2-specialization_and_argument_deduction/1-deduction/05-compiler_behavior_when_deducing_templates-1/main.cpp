struct base {
    template <int I, typename X>
    void foo(X, X) { }
};

struct derived : public base {
    void foo(int i) {
        // foo<314>(i, i) // error
        base::foo<314>(i, i);
    }
};


int main() {
    return 0;
}
