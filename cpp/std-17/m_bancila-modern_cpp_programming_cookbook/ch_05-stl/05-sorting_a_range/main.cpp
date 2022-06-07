#include <vector>
#include <algorithm>
#include <cassert>
namespace example_01 { // std::sort
void run() {
    std::vector<int> v{ 3, 13, 5, 8, 1, 2, 1 };
    
    std::sort(std::begin(v), std::end(v));
    assert((std::vector<int>{ 1, 1, 2, 3, 5, 8, 13 } == v));
    
    std::sort(std::begin(v), std::end(v), std::greater<>{});
    assert((std::vector<int>{ 13, 8, 5, 3, 2, 1, 1 } == v));
}
} // example_01


#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
namespace example_02 { // std::stable_sort

struct Task {
    int priority;
    std::string name;
};

bool operator<(Task const& lhs, Task const& rhs) {
    return lhs.priority < rhs.priority;
}

bool operator>(Task const& lhs, Task const& rhs) {
    return lhs.priority > rhs.priority;
}

bool operator==(Task const& lhs, Task const& rhs) {
    return lhs.priority == rhs.priority and lhs.name == rhs.name;
}

void run() {
    using namespace std::literals::string_literals;
    std::vector<Task> v{
        { 10, "Task 1"s }, { 40, "Task 2"s }, { 25, "Task 3"s },
        { 10, "Task 4"s }, { 80, "Task 5"s }, { 10, "Task 6"s }
    };
    
    std::stable_sort(std::begin(v), std::end(v));
    assert((
        std::vector<Task>{ 
            { 10, "Task 1"s}, { 10, "Task 4"s }, { 10, "Task 6"s },
            { 25, "Task 3"s}, { 40, "Task 2"s }, { 80, "Task 5"s } }
        == v));
        
    std::stable_sort(std::begin(v), std::end(v), std::greater<>{});
    assert((
        std::vector<Task>{
            { 80, "Task 5"s }, { 40, "Task 2"s }, { 25, "Task 3"s },
            { 10, "Task 1"s }, { 10, "Task 4"s }, { 10, "Task 6"s } }
        == v));            
}
} // example_02


#include <vector>
#include <algorithm>
#include <cassert>
namespace example_03 { // std::partial_sort
void run() {
    std::vector<int> v{ 3, 13, 5, 8, 1, 2, 1 };
    
    std::partial_sort(std::begin(v), std::begin(v) + 4, std::end(v));
    assert((1 == v[0] and 1 == v[1] and 2 == v[2] and 3 == v[3]));
    
    std::partial_sort(std::begin(v), std::begin(v) + 4, std::end(v), std::greater<>{});
    assert((13 == v[0] and 8 == v[1] and 5 == v[2] and 3 == v[3]));
}
} // example_03


#include <vector>
#include <algorithm>
#include <cassert>
namespace example_04 { // std::partial_sort_copy
void run() {
    std::vector<int> const v{ 3, 13, 5, 8, 1, 2, 1 };
    std::vector<int> vcopy(v.size());
    
    std::partial_sort_copy(std::cbegin(v), std::cend(v),
        std::begin(vcopy), std::end(vcopy));
    assert((std::vector<int>{ 1, 1, 2, 3, 5, 8, 13 } == vcopy));        
    
    std::partial_sort_copy(std::cbegin(v), std::cend(v),
        std::begin(vcopy), std::end(vcopy), std::greater<>{});
    assert((std::vector<int>{ 13, 8, 5, 3, 2, 1, 1 } == vcopy));
}    
} // example_04


#include <vector>
#include <algorithm>
#include <cassert>
namespace example_05 { // std::nth_element
void run() {
    std::vector<int> v{ 3, 13, 5, 8, 1, 2, 1 };
    int const n = 3;
    
    std::nth_element(std::begin(v), std::begin(v) + n, std::end(v));
    assert((3 == v[3]));
    for (size_t i = 0; i < n; ++i)
        for (size_t j = n + 1; j < v.size(); ++j)
            assert(v[i] <= v[j]);
            
    std::nth_element(std::begin(v), std::begin(v) + n, std::end(v),
        std::greater<>{});
    assert((3 == v[3]));        
    for (size_t i = 0; i < n; ++i)
        for (size_t j = n + 1; j < v.size(); ++j)
            assert(v[i] >= v[j]);
}
} // example_05


#include <vector>
#include <algorithm>
#include <cassert>
namespace example_06 { // std::is_sorted
void run() {
    std::vector<int> const v{ 1, 1, 2, 3, 5, 8, 13 };
    
    assert((std::is_sorted(std::cbegin(v), std::cend(v))));
    assert((not std::is_sorted(std::cbegin(v), std::cend(v), std::greater<>{})));
}
} // example_06


#include <vector>
#include <algorithm>
#include <cassert>
namespace example_07 { // std::is_sorted_until
void run() {
    std::vector<int> const v{ 3, 13, 5, 8, 1, 2, 1 };
    
    auto const it = std::is_sorted_until(std::cbegin(v), std::cend(v));
    auto const len = std::distance(std::cbegin(v), it);
    assert((2 == len));
}
} // example_07


#include <iostream>
int main() {
    std::cout << "[ok] - example_01 =>" << std::endl; example_01::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example_02 =>" << std::endl; example_02::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example_03 =>" << std::endl; example_03::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example_04 =>" << std::endl; example_04::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example_05 =>" << std::endl; example_05::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example_06 =>" << std::endl; example_06::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] - example_07 =>" << std::endl; example_07::run(); std::cout << std::endl << std::endl;
    
    return 0;
}

