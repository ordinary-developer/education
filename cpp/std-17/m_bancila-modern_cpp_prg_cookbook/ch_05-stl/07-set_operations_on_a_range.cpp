#include <vector>
#include <algorithm>
#include <cassert>
namespace example_01 { // -> set operations on a range (of trivial types)
void run() {
    std::vector<int> const v1{ 1, 2, 3, 4, 4, 5 };
    std::vector<int> const v2{ 2, 3, 3, 4, 6, 8 };
    std::vector<int> v3{};

    {
        std::set_union(std::cbegin(v1), std::cend(v1),
            std::cbegin(v2), std::cend(v2), std::back_inserter(v3));        
        assert((std::vector<int>{ 1, 2, 3, 3, 4, 4, 5, 6, 8 } == v3));
        v3.clear();
    }

    {
        std::merge(std::cbegin(v1), std::cend(v1),
            std::cbegin(v2), std::cend(v2), std::back_inserter(v3));
        assert((std::vector<int>{ 1, 2, 2, 3, 3, 3, 4, 4, 4, 5, 6, 8 } == v3));
        v3.clear();
    }

    {
        std::set_intersection(std::cbegin(v1), std::cend(v1),
            std::cbegin(v2), std::cend(v2), std::back_inserter(v3));
        assert((std::vector<int>{ 2, 3, 4 } == v3));
        v3.clear();
    }

    {
        std::set_difference(std::cbegin(v1), std::cend(v1),
            std::cbegin(v2), std::cend(v2), std::back_inserter(v3));
        assert((std::vector<int>{ 1, 4, 5 } == v3));
        v3.clear();
    }

    {
        std::set_symmetric_difference(std::cbegin(v1), std::cend(v1),
            std::cbegin(v2), std::cend(v2), std::back_inserter(v3));
        assert((std::vector<int>{ 1, 3, 4, 5, 6, 8 } == v3));
        v3.clear();
    }

    {
        std::vector<int> const v01{ 1, 2, 3, 4, 4, 5 };
        std::vector<int> const v02{ 2, 3, 3, 4, 6, 8 };
        std::vector<int> const v03{ 1, 2, 4 };
        std::vector<int> v04{};

        auto const i1 = std::includes(std::cbegin(v01), std::cend(v01),
            std::cbegin(v02), std::cend(v02));
        assert((not i1));

        auto const i2 = std::includes(std::cbegin(v01), std::cend(v01),
            std::cbegin(v03), std::cend(v03));
        assert((i2));

        auto const i3 = std::includes(std::cbegin(v01), std::cend(v01),
            std::cbegin(v04), std::cend(v04));
        assert((i3));
    }
}
} // example_01


#include <string>
#include <vector>
#include <algorithm>
namespace example_02 { // -> set operations on a range (of user-defined types)

struct Task {
    int priority;
    std::string name;
};
bool operator<(Task const& lhs, Task const& rhs) { return lhs.priority < rhs.priority; }
bool operator>(Task const& lhs, Task const& rhs) { return lhs.priority > rhs.priority; }

bool operator==(Task const& lhs, Task const& rhs) { 
    return lhs.priority == rhs.priority 
        and lhs.name == rhs.name;
}

void run() {
    using namespace std::literals::string_literals;
    std::vector<Task> const v1 {
        { 10, "Task 1.1"s },
        { 20, "Task 1.2"s },
        { 20, "Task 1.3"s },
        { 20, "Task 1.4"s },
        { 30, "Task 1.5"s },
        { 50, "Task 1.6"s }
    };
    std::vector<Task> const v2 {
        { 20, "Task 2.1"s },
        { 30, "Task 2.2"s },
        { 30, "Task 2.3"s },
        { 30, "Task 2.4"s },
        { 40, "Task 2.5"s },
        { 50, "Task 2.6"s }
    };

    {
        std::vector<Task> v3{};
        std::set_union(std::cbegin(v1), std::cend(v1),
            std::cbegin(v2), std::cend(v2), std::back_inserter(v3));
        assert((std::vector<Task>{ {10, "Task 1.1"}, { 20, "Task 1.2" }, { 20, "Task 1.3"},
            { 20, "Task 1.4" }, { 30, "Task 1.5" }, { 30, "Task 2.3" },
            { 30, "Task 2.4" }, { 40, "Task 2.5" }, { 50, "Task 1.6" }} == v3)) ;
    }

    {
        std::vector<Task> v3{};
        std::merge(std::cbegin(v1), std::cend(v1),
            std::cbegin(v2), std::cend(v2), std::back_inserter(v3));
        assert((std::vector<Task>{ { 10, "Task 1.1" }, { 20, "Task 1.2" }, { 20, "Task 1.3" },
            { 20, "Task 1.4" }, { 20, "Task 2.1" }, { 30, "Task 1.5" },
            { 30, "Task 2.2" }, { 30, "Task 2.3" }, { 30, "Task 2.4" },
            { 40, "Task 2.5" }, { 50, "Task 1.6" }, { 50, "Task 2.6" }} == v3));
    }

    {
        std::vector<Task> v3{};
        std::set_intersection(std::cbegin(v1), std::cend(v1),
            std::cbegin(v2), std::cend(v2), std::back_inserter(v3));
        assert((std::vector<Task>{ { 20, "Task 1.2" }, { 30, "Task 1.5" }, { 50, "Task 1.6" } } == v3));
    }

    {
        std::vector<Task> v3{};
        std::set_difference(std::cbegin(v1), std::cend(v1),
            std::cbegin(v2), std::cend(v2), std::back_inserter(v3));
        assert((std::vector<Task>{ { 10, "Task 1.1" }, { 20, "Task 1.3" }, { 20, "Task 1.4" } } == v3));
    }

    {
        std::vector<Task> v3{};
        std::set_symmetric_difference(std::cbegin(v1), std::cend(v1),
            std::cbegin(v2), std::cend(v2), std::back_inserter(v3));
        assert((std::vector<Task>{ { 10, "Task 1.1" }, { 20, "Task 1.3" }, { 20, "Task 1.4" },
            { 30, "Task 2.3" }, { 30, "Task 2.4" }, { 40, "Task 2.5" } } == v3));
    }
}
} // example_02


#include <iostream>
int main() {
    std::cout << "[ok] => example 01" << std::endl; example_01::run(); std::cout << std::endl << std::endl;
    std::cout << "[ok] => example 02" << std::endl; example_02::run(); std::cout << std::endl << std::endl;
    
    return 0;
}
