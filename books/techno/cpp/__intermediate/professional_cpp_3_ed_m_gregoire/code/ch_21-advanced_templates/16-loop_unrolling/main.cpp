#include <iostream>
#include <functional>
#include <string>

template <int i>
class Loop {
    public:
        template <typename FuncType>
        static inline void Do(FuncType func) {
            Loop<i - 1>::Do(func);
            func(i);
        }
};

template <>
class Loop<0> {
    public:
        template <typename FuncType>
        static inline void Do(FuncType /* func */) { }
};

void DoWork(int i) { std::cout << "DoWork(" << i << ")" << std::endl; }

void DoWork2(std::string str, int i) {
    std::cout << "DoWork2(" << str << ", " << i << ")" << std::endl;
}

int main() {
    Loop<3>::Do(DoWork);
    Loop<2>::Do(std::bind(DoWork2, "TestStr", std::placeholders::_1));

    return 0;
}

