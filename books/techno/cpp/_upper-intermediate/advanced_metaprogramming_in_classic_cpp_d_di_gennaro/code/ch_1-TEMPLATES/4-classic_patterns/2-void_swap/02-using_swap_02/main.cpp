#include <utility>
namespace example_1 {
    using std::swap;

    template <typename X>
    void doSomething(X& result) {
        X temp;
        swap(temp, result);
    }


    void run() {
        int a{ 42 };
        doSomething(a);
    }
}


#include <utility>
namespace example_2 {
    class X {
        public:
            X() = default;
            X(const X&) = default;
            ~X() = default;
            void swap(X&) { }

            X& operator=(const X& that) {
                if (this != &that) {
                    X temp(that);
                    temp.swap(*this);
                }
                return *this;
            }

            X& operator=(X that) {
                that.swap(*this);
                return *this;
            }
    };


    void run() {
        X x1, x2;
        x1.swap(x2);
    }

};



int main() {
    example_1::run();
    example_2::run();

    return 0;
}
