#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>

using FilterContainer = 
    std::vector<std::function<bool(int)>>;

FilterContainer filters;

class Widget {
    public:
        Widget() { 
            divisor = 1;
        }

        void addFilter() const {
            filters.emplace_back(
                [=](int value) {
                    return value % divisor == 0;
                }
            );
        }
    private:
        int divisor;
};

int main() {
    Widget w;
    w.addFilter();

    std::vector<int> vector = { 1, 2, 3, 4, 5 };

    for (const auto& function : filters) {
        if (std::all_of(std::begin(vector), 
                        std::end(vector),
                        function))
        {
            std::cout << "All" << std::endl;
        }
        else {
            std::cout << "Not all" << std::endl;
        }
    }

    return 0;
}
