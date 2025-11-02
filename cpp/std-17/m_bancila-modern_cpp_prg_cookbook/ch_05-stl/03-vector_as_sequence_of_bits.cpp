#include <vector>
#include <algorithm>
#include <cassert>
#include <iostream>
namespace example_01 { // -> manipulations with std::vector<bool>
void run() {
    std::vector<bool> bv{};
    assert((std::vector<bool>{} == bv)); 
    
    bv.push_back(true);
    bv.push_back(true);
    bv.push_back(false);
    bv.push_back(false);
    bv.push_back(false);
    bv.push_back(true);
    assert((std::vector<bool>{ true, true, false, false, false, true } == bv));
    
    bv[3] = true;
    assert((true == bv[3]));
        
    auto const count_of_ones = std::count(std::cbegin(bv), std::cend(bv), true);
    assert((4 == count_of_ones));
    
    bv.erase(bv.begin() + 2);
    assert((std::vector<bool>{ true, true, true, false, true } == bv));
    
    std::cout << "[ok]";
}    
} // example_01


#include <vector>
#include <algorithm>
#include <exception>
#include <cassert>
#include <iostream>
namespace example_02 { // -> a wrapper for std::bitset
    
class bitvector {
public:
    bitvector() = default;
    bitvector(bitvector const&) = default;
    bitvector(bitvector&&) = default;
    bitvector& operator=(bitvector const&) = default;
    bitvector& operator=(bitvector&&) = default;

    bitvector(std::vector<bool> const& boolVals) : boolVals_{boolVals} {}
    
    bool operator[](size_t const i) { return boolVals_[i]; }
    
    inline bool any() const {
        for (auto const val : boolVals_)
            if (val)
                return true;
        return false;
    }
    
    inline bool all() const {
        for (auto const& val : boolVals_)
            if (not val)
                return false;
        return true;
    }
    
    inline bool none() const { return not any(); }
    
    inline std::size_t count() const { 
        return std::count(std::cbegin(boolVals_), std::cend(boolVals_), true);
    }
    
    inline std::size_t size() const { return boolVals_.size(); }
    
    inline bitvector& add(bool const val) {
        boolVals_.push_back(val);
        return *this;
    }
    
    inline bitvector& remove(std::size_t const index) {
        if (index >= boolVals_.size())
            throw std::out_of_range("index out of range");
        boolVals_.erase(boolVals_.begin() + index);
        return *this;
    }
    
    inline bitvector& set(bool const val = true) {
        for (std::size_t i{0}; i < boolVals_.size(); ++i)
            boolVals_[i] = val;
        return *this;
    }
    
    inline bitvector& set(std::size_t const index, bool const val = true) {
        if (index >= boolVals_.size())
            throw std::out_of_range("index out of range");
        boolVals_[index] = val;
        return *this;
    }
    
    inline bitvector& reset() {
        for (std::size_t i{0}; i < boolVals_.size(); ++i)
            boolVals_[i] = false;
        return *this;
    }
    
    inline bitvector & reset(size_t const index) {
        if (index >= boolVals_.size())
            throw std::out_of_range("index out of range");
        boolVals_[index] = false;
        return *this;
    }
    
    inline bitvector& flip() {
        boolVals_.flip();
        return *this;
    }
    
    std::vector<bool>& data() { return boolVals_; }    
    
private:
    std::vector<bool> boolVals_;
};
    
void run() {
    bitvector bv{};
    assert((std::vector<bool>{} == bv.data()));
    
    bv.add(true).add(true).add(false);
    bv.add(false);
    bv.add(true);
    assert((std::vector<bool>{ true, true, false, false, true } == bv.data()));
    
    assert((bv.any()));
    assert((not bv.all()));
    assert((not bv.none()));
    assert((3 == bv.count()));
    
    bv.set(2, true);
    assert((std::vector<bool>{ true, true, true, false, true } == bv.data()));
    bv.set();
    assert((std::vector<bool>{ true, true, true, true, true } == bv.data()));
    
    bv.reset(0);
    assert((std::vector<bool>{ false, true, true, true, true } == bv.data()));
    bv.reset();
    assert((std::vector<bool>{ false, false, false, false, false } == bv.data()));
    
    bv.flip();
    assert((std::vector<bool>{ true, true, true, true, true } == bv.data()));
    
    std::cout << "[ok]";
}
} // example_02


#include <iostream>
int main() {
    std::cout << "example_01 =>" << std::endl; example_01::run(); std::cout << std::endl << std::endl;
    std::cout << "example_02 =>" << std::endl; example_02::run(); std::cout << std::endl << std::endl;
    
    return 0;
}
