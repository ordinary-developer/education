#include <algorithm>
#include <iostream>
#include <vector>


class MyClass {
    public:
        MyClass(const int value) : m_Value{ value } { }

        int GetValue() const { return m_Value; }

    private:
        int m_Value;
};

bool CompareMyClasses(MyClass const& left, MyClass const& right) {
    return left.GetValue() < right.GetValue();
}

int main() {
    std::vector<MyClass> myVector{ 4, 10, 6, 9, 1 };
    auto minimum = std::min_element(myVector.begin(), 
                                    myVector.end(),
                                    CompareMyClasses);
    
    if (myVector.end() != minimum) 
        std::cout << "Minimum value: " << (*minimum).GetValue() 
                  << std::endl;

    return 0;
}
