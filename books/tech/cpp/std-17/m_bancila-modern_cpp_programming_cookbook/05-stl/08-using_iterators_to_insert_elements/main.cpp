#include <algorithm>
#include <vector>
#include <list>
#include <cassert>
namespace example_01 { // -> iterator adapter for inserting new elements in a container
void run() {
    {
    std::vector<int> v{ 1, 2, 3, 4, 5 };
    std::fill_n(std::back_inserter(v), 3, 0);
    assert((std::vector<int>{ 1, 2, 3, 4, 5, 0, 0, 0 } == v));
    }

    {
    std::list<int> l{ 1, 2, 3, 4, 5 };        
    std::fill_n(std::front_inserter(l), 3, 0);
    assert((std::list<int>{ 0, 0, 0, 1, 2, 3, 4, 5 } == l));
    }

    {
    std::vector<int> v{ 1, 2, 3, 4, 5 };
    std::fill_n(std::inserter(v, v.begin()), 3, 0);
    assert((std::vector<int>{ 0, 0, 0, 1, 2, 3, 4, 5 } == v));

    std::list<int> l{ 1, 2, 3, 4, 5 };
    auto it = std::begin(l);
    std::advance(it, 3);
    std::fill_n(std::inserter(l, it), 3, 0);
    assert((std::list<int>{ 1, 2, 3, 0, 0, 0, 4, 5 } == l));
    }

    {
    std::vector<int> v{ 1, 2, 3, 4, 5 };
    std::fill_n(std::inserter(v, std::begin(v)), 3, 0);
    assert((std::vector<int>{ 0, 0, 0, 1, 2, 3, 4, 5 } == v));
    }
}    
} // example_01


#include <algorithm>
#include <vector>
#include <cassert>
namespace example_02 { // -> over-simplified implementation of std::back_inserter_iterator

template <class C>
class back_insert_iterator {
public:
    typedef back_insert_iterator<C> T;
    typedef typename C::value_type V;

    explicit back_insert_iterator(C& c) : container_{&c} {}

    T& operator=(V const& val) {
        container_->push_back(val);
        return *this;
    }

    T& operator*() { return *this; }
    T& operator++() { return *this; }
    T& operator++(int) { return *this; }

protected:
    C* container_;
};

void run() {
    std::vector<int> v{ 1, 2, 3, 4, 5 };
    std::fill_n(back_insert_iterator(v), 3, 0);
    assert((std::vector<int>{ 1, 2, 3, 4, 5, 0, 0, 0 } == v));
}    
} // example_02


#include <iostream>
int main() {
    std::cout << "[ok] - example 01 =>" << std::endl; example_01::run(); std::cout << std::endl;
    std::cout << "[ok] - example 02 =>" << std::endl; example_02::run(); std::cout << std::endl;

    return 0;
}
