template <typename T, int INITIAL_CAPACITY = 16>
class C;

template <typename T>
class H {
    public:
        H(T const& value) : value_{ value } { }
        virtual ~H() = default;

        bool operator==(H const& that) const { 
            return value_ == that.value_;
        }
            

    private:
        T value_;
};


template <typename T, int INITIAL_CAPACITY>
class C : public H<T>
{
    public:
        C(T const& value) : H<T>(value) { }
        virtual ~C() final override = default;
};


#include <iostream>
int main() {
    C<int> c1{ 1 } , c2{ 1 };
    if (c1 == c2)
        std::cout << "are equal" << std::endl;

    return 0;
}
