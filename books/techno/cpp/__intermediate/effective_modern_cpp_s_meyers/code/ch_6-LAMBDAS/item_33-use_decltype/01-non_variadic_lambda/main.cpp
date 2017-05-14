#include <iostream>

template <typename T>
void normalize(T&& value) {
    std::cout << value << std::endl;
}


int main() {
    std::string str = "lvalue string";
    normalize(str);
    
    normalize(std::string("rvalue string"));

    auto f = 
        [](auto&& param) 
        {
            return 
              normalize(std::forward<decltype(param)>(param));
        };
    f(str);
    f(std::string("rvalue string"));

    return 0;
}

