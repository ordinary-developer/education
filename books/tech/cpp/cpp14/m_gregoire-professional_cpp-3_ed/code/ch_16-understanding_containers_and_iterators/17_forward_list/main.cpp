#include <iostream>
#include <forward_list>


auto main() -> int {
    std::forward_list<int> lst1 = { 5, 6 };
    std::forward_list<int> lst2 = { 1, 2, 3, 4 };
    std::forward_list<int> lst3 = { 7, 8, 9 };

    lst1.splice_after(lst1.before_begin(), lst2);

    lst1.push_front(0);

    auto iter = lst1.before_begin();
    auto iterTemp = iter;
    while (++iterTemp != end(lst1)) {
        ++iter;
    }
    lst1.insert_after(iter, begin(lst3), end(lst3));

    for (auto& i : lst1) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    return 0;
}
