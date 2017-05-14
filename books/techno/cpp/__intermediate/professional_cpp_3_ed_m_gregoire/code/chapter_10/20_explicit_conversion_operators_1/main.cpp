class IntWrapper {
    public:
        IntWrapper(int i) : mInt(i) { }
        operator int() const { return mInt; }
    private:
        int mInt;
};

auto main() -> int {
    IntWrapper c(123);
    int iC1 = c;
    int iC2 = static_cast<int>(c);

    return 0;
}
