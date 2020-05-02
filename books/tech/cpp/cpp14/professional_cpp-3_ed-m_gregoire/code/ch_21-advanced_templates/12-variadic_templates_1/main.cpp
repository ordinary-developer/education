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
void processValues(T arg) { handleValue(arg); }

template <typename T1, typename... Tn>
void processValues(T1 arg1, Tn... args) {
    handleValue(arg1);
    processValues(args...);
}


int main() {
    processValues(1, 2, 3.56, "test", 1.1f);

    return 0;
}
