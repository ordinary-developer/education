#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
void example1() {
    std::vector<int> v1{ 1, 100, 201, 100, 301 }, v2{};
    std::remove_copy_if(v1.cbegin(),
                        v1.cend(),
                        std::back_insert_iterator<std::vector<int>>{ v2 },
                        [](int i) { return 100 == i; });
    std::copy(v2.cbegin(), 
              v2.cend(), 
              std::ostream_iterator<int>{ std::cout, " " });

    std::cout << std::endl;
}

#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
void example2() {
    std::vector<int> v1{ 1, 100, 201, 100, 301 }, v2{};
    std::remove_copy_if(v1.cbegin(),
                        v1.cend(),
                        std::back_inserter(v2),
                        [](int i) { return 100 == i; });
    std::copy(v2.cbegin(), 
              v2.cend(), 
              std::ostream_iterator<int>{ std::cout, " " });

    std::cout << std::endl;
}

#include <vector>
#include <set>
#include <iterator>
#include <iostream>
void example3() {
    std::vector<int> v1{ 1, 100, 201, 100, 301 };
    std::set<int> s1{};

    std::remove_copy_if(
      v1.cbegin(),
      v1.cend(),
      std::insert_iterator<std::set<int>>{ s1, std::begin(s1) },
      [](int i) { return 100 == i; });

    std::copy(s1.cbegin(),
              s1.cend(),
              std::ostream_iterator<int>(std::cout, " "));

    std::cout << std::endl;
}

int main() {
    example1();
    example2();
    example3();

    return 0;
}
