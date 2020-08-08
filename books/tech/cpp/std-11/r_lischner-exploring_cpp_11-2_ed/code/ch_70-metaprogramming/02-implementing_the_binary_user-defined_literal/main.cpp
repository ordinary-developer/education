constexpr unsigned long long binary_helper(unsigned long long digits,
                                           unsigned long long result,
                                           int shift)
{
    return 0 == digits 
           ? result
           : binary_helper(digits / 10,
                           result | ((digits % 10 == 1) << shift),
                           digits % 10 < 2 ? shift + 1 : shift);
}

constexpr unsigned long long operator"" _binary(unsigned long long digits)
{
    return binary_helper(digits, 0ULL, 0);
}

#include <iostream>
int main() {
    std::cout << 11_binary << std::endl;

    return 0;
}
