#include <string>
#include <vector>
#include <iostream>


template <typename T>
class MyClass1 {
    public:
        std::string getName() const {
            return "42";
        }
    private:
        double value_;
        std::string name_;
        std::vector<T> data_;
};

// should be
class MyBaseClass {
    public:
        std::string getName() const { return "42"; }

    protected:
        virtual ~MyBaseClass() = default;

        double value_;
        std::string name_;
};

template <typename T>
class MyClass2 : MyBaseClass {
    public:
        using MyBaseClass::getName;

    private:
        std::vector<T> data_;
};


int main() {
    MyClass2<int> a;
    std::cout << a.getName() << std::endl;

    return 0;
}
