#include <iostream>
#include <vector>


int main() {
    {
        int numbers[] { 1, 2, 3, 4, 5 };
        for (int * pnumber{numbers}; pnumber < numbers + std::size(numbers); ++pnumber) {
            std::cout << *pnumber << ' ';
        }
        std::cout << std::endl;
    }
    
    {
        std::vector numbers{ 1, 2, 3, 4, 5 };
        for (auto iter{ numbers.begin() }; iter < numbers.begin() + numbers.size(); ++iter) {
            std::cout << *iter << ' ';
        }
        std::cout << std::endl;
    }

    {
        std::vector numbers{ 1, 2, 3, 4, 5 };
        for (auto iter{ numbers.begin() }; iter != numbers.end(); ++iter)
            std::cout << *iter << ' ';
        std::cout << std::endl;
    }
}
