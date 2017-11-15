#include <iostream>

template <typename T>
class something {
    public:
        something() = default;

        // not called when S == T
        template <typename S>
        something(const something<S>& that) {
            std::cout << "user-def copy constructor calling" 
                      << std::endl;
        }

        // not class when S == T
        template <typename S>
        something& operator= (const something<S>& that) 
        {
            std::cout << "user-def assignment operator"
                      << std::endl;
            return *this;
        }
};

int main() {
    something<int> s0;
    something<double> s1, s2;
    s0 = s1;
    s1 = s2;

    return 0;
}
