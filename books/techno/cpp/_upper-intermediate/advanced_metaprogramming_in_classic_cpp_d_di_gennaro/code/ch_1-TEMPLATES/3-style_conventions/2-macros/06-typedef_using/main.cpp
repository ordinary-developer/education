// not correct
namespace example1 {
    #define T1 char*

    void run() {
        T1 x = 0;
        T1* p = &x;
    }

};

// correct
namespace example2 {
    #define T2 char*

    void run() {
        typedef T2 MyType;
        MyType x = 0;
        MyType* p = &x;
    }
};


int main() {
    example1::run();
    example2::run();

    return 0;
}
