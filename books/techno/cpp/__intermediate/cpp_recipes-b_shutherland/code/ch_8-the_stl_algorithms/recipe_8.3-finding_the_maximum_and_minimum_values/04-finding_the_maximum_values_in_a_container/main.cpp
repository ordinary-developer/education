#include <algorithm>
#include <iostream>
#include <vector>


class MyClass {
    public:
        MyClass(const int value) : m_Value{ value } { }

        int GetValue() const { return m_Value; }

        bool operator <(MyClass const& other) const {
            return m_Value < other.m_Value;
        }

    private:
        int m_Value;
};

bool CompareMyClasses(MyClass const& left, MyClass const& right) {
    return left.GetValue() < right.GetValue();
}

int main() {
    std::vector<int> myIntVector{ 4, 10, 6, 9, 1 };
    auto intMaximum = std::max_element(myIntVector.begin(),
                                       myIntVector.end());

    if (myIntVector.end() != intMaximum) 
        std::cout << "Maximum value: " << *intMaximum << std::endl;


    std::vector<MyClass> myMyClassVector{ 4, 10, 6, 9, 1 };
    auto overrideOperatorMaximum = 
        std::max_element(myMyClassVector.begin(),
                         myMyClassVector.end());
    if (overrideOperatorMaximum != myMyClassVector.end())
        std::cout << "Maximum value: "  
                  << (*overrideOperatorMaximum).GetValue() 
                  << std::endl << std::endl;

    auto functionComparisonMaximum =
        std::max_element(myMyClassVector.begin(),
                         myMyClassVector.end(),
                         CompareMyClasses);
    if (functionComparisonMaximum != myMyClassVector.end())
        std::cout << "Maximum value: " 
                  << (*functionComparisonMaximum).GetValue()
                  << std::endl << std::endl;

    return 0;
}
