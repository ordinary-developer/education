#include <chrono>
#include <iostream>


int main() {
    std::chrono::milliseconds ms(54802);
    std::chrono::seconds s = 
        std::chrono::duration_cast<std::chrono::seconds>(ms);

    std::cout << s.count() << std::endl;

    return 0;
}
