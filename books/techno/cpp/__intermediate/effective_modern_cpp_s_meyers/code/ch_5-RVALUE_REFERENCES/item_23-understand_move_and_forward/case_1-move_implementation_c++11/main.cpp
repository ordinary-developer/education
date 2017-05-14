#include <type_traits>
#include <iostream>

template <typename T>
typename std::remove_reference<T>::type&&
move(T&& param) 
{
    using ReturnType =
        typename std::remove_reference<T>::type&&;

    std::cout << "Our move implementation\n";

    return static_cast<ReturnType>(param);
}

class ExempliGratia { };

int main() {
    ExempliGratia eg;
    move(eg);

    return 0;
}
