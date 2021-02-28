#include <algorithm>
#include <vector>
#include <cassert>
namespace test {

class greater_than {
public:
    greater_than(int const value) : m_value{value} {}

    bool operator()(int const arg) const { return arg > m_value; }

private:
    int const m_value;
};

void run() {
    greater_than const greater_than_42{42};

    assert(not greater_than_42(1));
    assert(greater_than_42(50));

    std::vector<int> ages{ 2, 10, 3, 11, 4, 12, 5, 6, 5 };
    std::stable_partition(std::begin(ages), std::end(ages), greater_than{6});

    std::vector<int> const expected{ 10, 11, 12, 2, 3, 4, 5, 6, 5 };
    assert(expected == ages);
}

} // test


#include <iostream>
int main() {
    std::cout << "test => [ok]";
    test::run();
    std::cout << std::endl;

    return 0;
}
