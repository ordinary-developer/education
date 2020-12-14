#include <iostream>
#include <string>

void handleValue(int value) { 
    std::cout << "Integer: " << value << std::endl;
}

void handleValue(double value) {
    std::cout << "Double: " << value << std::endl;
}

void handleValue(std::string const& value) {
    std::cout << "String" << value << std::endl;
}


template <typename T>
void processValues(T&& arg) { handleValue(std::forward<T>(arg)); }

template <typename T1, typename... Tn>
void processValues(T1&& arg1, Tn&&... args) {
    handleValue(std::forward<T1>(arg1));
    processValues(std::forward<Tn>(args)...);
}


int main() {
    processValues(1, 2, 3.56, "test", 1.1f);

    return 0;
}
