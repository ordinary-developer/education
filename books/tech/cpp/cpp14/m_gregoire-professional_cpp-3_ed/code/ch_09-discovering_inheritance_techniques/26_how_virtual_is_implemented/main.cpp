class Super {
    public:
        virtual void func1() { }
        virtual void func2() { }
        void nonVirtualFunc() { }
};

class Sub : public Super {
    public:
        virtual void func2() override { }
        void nonVirtualFunc() { }
};

auto main() -> int {
    Super mySuper;
    Sub mySub;

    return 0;
}
