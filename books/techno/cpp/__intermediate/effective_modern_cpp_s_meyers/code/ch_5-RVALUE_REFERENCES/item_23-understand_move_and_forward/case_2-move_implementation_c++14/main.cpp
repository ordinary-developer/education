#include <type_traits>
#include <iostream>

template <typename T>
decltype(auto) move(T&& param) 
{
    using ReturnType = std::remove_reference_t<T>&&;
    std::cout << "our implementation\n";
    return static_cast<ReturnType>(param);
}

class ExempliGratia { };

int main() {
    ExempliGratia eg;
    move(eg);

    return 0;
}
