#include <iostream>
#include <limits>


int main() {
    std::cout << "bits per int = ";
    if (std::numeric_limits<int>::is_signed)
        std::cout << std::numeric_limits<int>::digits + 1 << '\n';
    else
        std::cout << std::numeric_limits<int>::digits << '\n';

    std::cout << "bits per bool = ";
    if (std::numeric_limits<bool>::is_signed)
        std::cout << std::numeric_limits<bool>::digits + 1 << '\n';
    else
        std::cout << std::numeric_limits<bool>::digits << '\n';

    return 0;
}
