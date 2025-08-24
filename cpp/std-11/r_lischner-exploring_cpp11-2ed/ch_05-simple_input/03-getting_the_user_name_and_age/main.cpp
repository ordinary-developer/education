#include <iostream>
#include <string>

int main() {
    std::cout << "What is your name? ";
    std::string name{ };
    std::cin >> name;

    std::cout << "Hello, " << name << ", how old are you? ";
    int age{ };
    std::cin >> age;

    std::cout << "Good-by, " << name << ". You are " << age << " year";
    if (1 != age)
        std::cout << 's';
    std::cout << " lod.\n";

    return 0;
}
