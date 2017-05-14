#include <algorithm>
#include <iostream>
#include <vector>


class MyClass {
    public:
        MyClass(const int value) : m_Value{ value } { }

        int GetValue() const { return m_Value; }

        bool operator <(const MyClass& other) const {
            return m_Value < other.m_Value;
        }

    private:
        int m_Value;
};

int main() {
    std::vector<MyClass> myVector{ 4, 10, 6, 9, 1 };
    auto minimum = std::min_element(myVector.begin(), myVector.end());
    
    if (myVector.end() != minimum) 
        std::cout << "Minimum value: " << (*minimum).GetValue() 
                  << std::endl;

    return 0;
}
