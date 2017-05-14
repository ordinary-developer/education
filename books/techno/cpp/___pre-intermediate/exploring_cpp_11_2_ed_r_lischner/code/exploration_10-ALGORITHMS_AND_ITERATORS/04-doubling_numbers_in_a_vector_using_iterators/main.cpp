#include <iomanip>
#include <iostream>
#include <vector>


int main() {
    std::vector<int> data{};
    int x{};

    while (std::cin >> x)
        data.push_back(x);

    for (std::vector<int>::iterator i{ std::begin(data) },
                                    end{ std::end(data) };
         i != end;
         ++i)
    {
        std::cout << std::setw(2) << *i 
                  << std::setw(3) << *i * 2 
                  << std::setw(4) << *i * *i << '\n';
    }

    return 0;
}
