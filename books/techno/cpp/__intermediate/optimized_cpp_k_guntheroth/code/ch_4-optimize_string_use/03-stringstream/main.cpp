#include <sstream>
#include <iostream>

int main() {
    std::stringstream s;
    for (int i = 0; i < 10; ++i) {
        s.clear();
        s << "The square of " << i << " is " << i * i << std::endl;
    }
    std::cout << s.str();
}
