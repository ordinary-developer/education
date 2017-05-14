#include <vector>
#include <algorithm>
#include <iostream>


auto main() -> int {
    std::vector<int> vector {1, 2, 3, 4, 5, 6, 7, 8, 9 };

    int value = 3;

    int count = count_if(begin(vector), end(vector),
            [value] (int i) { return i > value; });
    std::cout << "Found " << count << " values > " << value << std::endl;

    int countLambdaCalled = 0;
    count = count_if(begin(vector), end(vector),
            [value, &countLambdaCalled] (int i ) 
            {
                ++countLambdaCalled;
                return i > value;
            }
    );
    std::cout << "The lambda expression was called " << countLambdaCalled
              << " times." << std::endl;
    std::cout << "Found " << count << " values > " << value << std::endl;

    return 0;
}
