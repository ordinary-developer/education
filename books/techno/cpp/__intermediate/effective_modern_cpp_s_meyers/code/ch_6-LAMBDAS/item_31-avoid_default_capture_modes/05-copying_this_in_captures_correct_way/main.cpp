#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>
#include <memory>


using FilterContainer =
    std::vector<std::function<bool(int)>>;

FilterContainer filters;


class Widget {
    public:
        void setDivisor(int divisor) { 
            _divisor = divisor;
        }

        void addFilter() const {
            // bad way
            filters.emplace_back(
                [=](int value) {
                    return (0 == (value % _divisor));
                }
            );

            // good way
            auto divisorCopy = _divisor;

            filters.emplace_back(
                [divisorCopy](int value) {
                    return (0 == (value % divisorCopy));
                }
            );
            // or
            filters.emplace_back(
                [=](int value) {
                    return (0 == (value & divisorCopy));
                }
            );       
            // C++14 good way
            filters.emplace_back(
                [divisor = _divisor](int value) {
                    return (0 == (value % divisor));
                }
            );
        }

    private:
        int _divisor;
};

void doSomeWork() {
    auto pw = std::make_unique<Widget>();
    pw->setDivisor(2);
    pw->addFilter();
}


int main() { 
    doSomeWork();

    std::vector<int> vector = { 1, 2, 3, 4, 5 };
    for (const auto& filter : filters) {
        if (std::all_of(std::begin(vector), std::end(vector),
                        filter))
        {
            std::cout << "All" << std::endl;
        }
        else {
            std::cout << "Not all" << std::endl;
        }
    }

    return 0;
}
