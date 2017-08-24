#include <iostream>


int generate_id() {
    static int counter{ 0 };
    return ++counter;
}

int main() {
    for (int i{ 0 }; i != 10; ++i)
        std::cout << generate_id() << '\n';

    return 0;
}
