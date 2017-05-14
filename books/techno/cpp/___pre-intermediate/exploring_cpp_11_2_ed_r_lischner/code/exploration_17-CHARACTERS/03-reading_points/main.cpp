#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

int main() {
    using intvec = std::vector<int>;
    using iterator = intvec::iterator;

    intvec xs, ys;

    {
        int x{}, y{};
        char sep{};
        while (std::cin >> x >> sep and ',' == sep and std::cin >> y) 
        {
            xs.push_back(x);
            ys.push_back(y);
        }
    }

    
    for (iterator x{ xs.begin() }, y{ ys.begin() }; 
         x != xs.end();
         ++x, ++y)
    {
        std::cout << *x << ',' << *y << '\n';
    }

    return 0;
}
