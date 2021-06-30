#include <cassert>
namespace workspace {

class Integer {
public:
    Integer(const int integer) : integer_(integer) {}

    Integer plus(const Integer& other) const { return Integer(integer_ + other.integer_); }

    friend bool operator == (const Integer& lhs, const Integer& rhs);

private:
    const int integer_;
};  
bool operator == (const Integer& lhs, const Integer& rhs) {
    return lhs.integer_ == rhs.integer_;
}

void run() {
    assert((Integer(3) ==
        Integer(1).plus(Integer(2))));
}
} // workspace


#include <iostream>
int main() {
    std::cout << "[test] => ok" << std::endl;
    workspace::run();
    std::cout << std::endl;

    return 0;
}
