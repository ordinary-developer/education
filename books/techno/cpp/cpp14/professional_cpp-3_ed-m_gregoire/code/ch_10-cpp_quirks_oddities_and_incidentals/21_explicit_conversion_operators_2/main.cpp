class IntWrapper {
    public:
        IntWrapper(int i) : mInt(i) { }
        explicit operator int() const { return mInt; }
    private:
        int mInt;
};

auto main() -> int {
    IntWrapper c(123);
    // en error will ge generated
    //int iC1 = c;
    int iC2 = static_cast<int>(c);

    return 0;
}
