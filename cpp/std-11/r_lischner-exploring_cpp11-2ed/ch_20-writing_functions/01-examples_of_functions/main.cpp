#include <iostream>
#include <string>

void ignore_line() {
    char c{};
    while (std::cin.get(c) and '\n' != c)
        ;
}

int prompted_read(std::string prompt) {
    std::cout << prompt;
    int x{ 0 };
    std::cin >> x;
    ignore_line();
    return x;
}

void print_result(int count, int sum) {
    if (0 == count) {
        std::cout << "no data\n";
        return;
    }

    std::cout << "\ncount = " << count;
    std::cout << "\nsum = " << sum;
    std::cout << "\nmean = " << sum / count << '\n';
}


int main() {
    int sum{ 0 };
    int count{ 0 };

    while (std::cin) {
        int x{ prompted_read("Value: ") };
        if (std::cin) {
            sum = sum + x;
            ++count;
        }
    }

    print_result(count, sum);

    return 0;
}
