namespace X {
    namespace version_1_0 {
        void func1() { }
        void func2() { }
    }

    namespace version_2_0 {
        void func1() { }
        void func2() { }
    }

#define USE_1_0

#ifdef USE_1_0
    using namespace version_1_0;
#else
    using namespace version_2_0;
#endif 
}

int main() {
    X::func1();

    return 0;
}
