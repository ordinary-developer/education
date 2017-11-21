#include <iostream>

int main() {
    int sum{ 0 };
    int count{ };
    int x;

    while (std::cin >> x) {
        sum = sum + x;
        count = count + 1;
    }

    if (0 == count)
        std::cout << "No data.\n";
    else 
        std::cout << "average = " << sum / count << '\n';

    return 0;
}
