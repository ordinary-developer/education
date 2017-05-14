#include <string>
#include <future>
#include <iostream>

struct X {
    void foo(int, const std::string&) { 
        std::cout << "calling {foo}" << std::endl;
    }
    std::string bar(const std::string& str) { 
        std::cout << "calling {bar}" << std::endl;
        return std::string(str);
    }
};

X baz(X& x) {
    std::cout << "calling {baz}" << std::endl;
    return X(x);
}

struct Y {
    double operator() (double) {
        std::cout << "calling {y()}" << std::endl;
        return 42;
    }
};

class move_only {
    public:
        move_only() = default;
        move_only(move_only&&) = default;
        move_only(const move_only&) = delete;

        move_only& operator= (move_only&&) = default;
        move_only& operator= (const move_only&) = delete;

        void operator() () { 
            std::cout << "calling {move_only()}" << std::endl;
        }
};

int main() {
    X x;
    auto f0 = std::async(&X::foo, &x, 42, "hello");
    auto f1 = std::async(&X::bar, x, "goodbye");
    f0.get();
    f1.get();

    auto f2 = std::async(baz, std::ref(x));
    f2.get();

    Y y;
    auto f3 = std::async(Y(), 3.141);
    auto f4 = std::async(std::ref(y), 2.718);
    f3.get();
    f4.get();

    auto f5 = std::async(move_only());
    f5.get();

    auto f6 = std::async(std::launch::async, Y(), 1.2);

    X another_x;
    auto f7 = std::async(std::launch::deferred, baz, 
            std::ref(another_x));

    X yet_another_x;
    auto f8 = std::async(
            std::launch::deferred | std::launch::async,
            baz, std::ref(yet_another_x));

    X the_last_x;
    auto f9 = std::async(baz, std::ref(the_last_x));

    f7.wait();


    return 0;
}
