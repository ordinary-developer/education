#include <iostream>

template <typename T, int numberOfElements>
class MyArray {
    public:
        MyArray() : m_Array{} { }
        
        T& operator[](const unsigned int index) { return m_Array[index]; }
        
    private:
        T m_Array[numberOfElements];
};

int main()
{
    const unsigned int ARRAY_SIZE{ 5 };
    
    MyArray<int, ARRAY_SIZE> myIntArray{};
    for (unsigned int i{ 0 }; i < ARRAY_SIZE; ++i)
        myIntArray[i] = i;
    for (unsigned int i{ 0 }; i < ARRAY_SIZE; ++i )    
        std::cout << myIntArray[i] << std::endl;
        
    MyArray<float, ARRAY_SIZE> myFloatArray{};
    for (unsigned int i{ 0 }; i < ARRAY_SIZE; ++i)
        myFloatArray[i] = static_cast<float>(i) + 0.5F;
    for (unsigned int i{ 0 }; i < ARRAY_SIZE; ++i)
        std::cout << myFloatArray[i] << std::endl;
        
    return 0;
}
