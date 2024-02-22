// Example C++17 program using fold expressions copied from:
// https://www.modernescpp.com/index.php/cpp17-core
//
// foldExpressionAll.cpp

#include <iostream>
#include <string_view>
#include <vector>

void printVector(const std::vector<int> & nums) {
    for (auto i : nums)
        std::cout << i << ' ';
    std::cout << std::endl;
}

int main(){
    std::vector nums{ 1, 4, 5 };
    nums.insert(nums.begin(), 1);
    printVector(nums);

    nums.insert(nums.begin() + nums.size() / 2, 3);
    printVector(nums);

    std::vector<int> moreNums{ 6, 7, 8 };
    nums.insert(nums.end(), moreNums.begin(), moreNums.end());
    printVector(nums);

    int moreNums02[] { 6, 7, 8 };
    nums.insert(nums.end(), moreNums02, moreNums02 + std::size(moreNums02));
    printVector(nums);

    int moreNums03[] { 6, 7, 8 };
    nums.insert(std::end(nums), std::cbegin(moreNums03), std::cend(moreNums03));
    printVector(nums);
}
