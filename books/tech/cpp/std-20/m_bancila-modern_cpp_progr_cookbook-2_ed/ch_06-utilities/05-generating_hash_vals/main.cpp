#include <string>
#include <set>
#include <unordered_set>
#include <iostream>


struct Item {
    int id;
    std::string name;
    double value;
    
    Item(int const id, std::string const & name, double const value)
        : id{id}, name{name}, value{value} {}
        
    bool operator == (Item const & other) const {
        return id == other.id and name == other.name and value == other.value;
    }
    
    bool operator != (Item const & other) const { return not (*this == other); }
    
    bool operator < (Item const & other) const {
        return id < other.id and name < other.name and value < other.value;
    }
};


namespace std {
    
template<>
struct hash<Item> {
    typedef Item argument_type;
    typedef std::size_t result_type;
    
    result_type operator()(argument_type const & item) const {
        result_type hashValue = 17;
        
        hashValue = 31 * hashValue + std::hash<int>{}(item.id);
        hashValue = 31 * hashValue + std::hash<std::string>{}(item.name);
        hashValue = 31 * hashValue + std::hash<double>{}(item.value);
        
        return hashValue;
    }
};

} // std


namespace example_01 { // the "how to do it" section
void run() {
    using namespace std::string_literals;
    
    std::set<Item> set1 { { 1, "one"s, 1.0 }, { 2, "two"s, 2.0 }, { 3, "three"s, 3.0 } };
    
    std::unordered_set<Item> set2 { { 1, "one"s, 1.0 }, { 2, "two"s, 2.0 }, { 3, "three"s, 3.0 } };
}
} // example_01


#include <iostream>
int main() {
    std::cout << "example 01 => [ok]" << std::endl; example_01::run(); std::cout << std::endl << std::endl;
    
    return 0;
}