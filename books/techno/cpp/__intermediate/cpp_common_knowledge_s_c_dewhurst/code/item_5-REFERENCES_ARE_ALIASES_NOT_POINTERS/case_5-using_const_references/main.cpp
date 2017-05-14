#include <iostream>
#include <string>

template <typename T>
void swap(T& a, T& b)
{
    T temp(a);
    a = b;
    b = temp;
}

template <typename T>
T add(const T& a, const T& b) 
{
    return a + b;
}


int main()
{
    // error
    // double &d = 12.3;
    
    // there is no error in new compilers
    swap(std::string("Hello"), std::string(", World"));

    const double &cd = 12.3; // OK

    const std::string &greeting = add(std::string("Hello"), 
                                      std::string(", World")); // OK
    std::cout << greeting << std::endl;

    return 0;   
}