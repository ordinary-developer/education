class MyClass {
    public:
        MyClass(int& ref): mRef(ref) { }
    private:
        int& mRef;
};

auto main() -> int {
    int value = 3;
    new MyClass(value);

    return 0;
}
