#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> data{};
    int x{};

    while (std::cin >> x)
        data.push_back(x);

    std::sort(std::begin(data), std::end(data));

    for (std::vector<int>::iterator i{ data.begin() },  
                                    end{ data.end() };
         i != end; ++i)
    {
        std::cout << *i << '\n';
    }

    return 0;
}
