#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>


int main() {
    std::vector<int> data{};
    int x{};
    while (std::cin >> x)
        data.push_back(x);

    for (std::vector<int>::iterator start{ std::begin(data) },  
                                    end{ std::end(data) };
         start != end;
         /*empty*/)
    {
        --end;
        if (start != end) {
            std::iter_swap(start, end);
            ++start;
        }
    }

    std::copy(std::begin(data), std::end(data), 
              std::ostream_iterator<int>(std::cout, "\n"));

    return 0;
}
