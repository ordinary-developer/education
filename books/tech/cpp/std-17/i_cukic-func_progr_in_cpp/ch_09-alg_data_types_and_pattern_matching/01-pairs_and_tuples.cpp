#include <iostream>
#include <string>
#include <tuple>
#include <cassert>
namespace workspace {

class person_t {
public:
    person_t(std::string const & name, std::string const & surname)
        : m_name{name}, m_surname{surname} {}

private:
    std::string const m_name;
    std::string const m_surname;

    friend bool operator < (person_t const & lhs, person_t const & rhs);
};

bool operator < (person_t const & lhs, person_t const & rhs) {
    return std::tie(lhs.m_name, lhs.m_surname)
        < std::tie(rhs.m_name, rhs.m_surname);
}


void run() {
    person_t const person1{ "a", "a" }, person2{ "b", "b" };
    assert((person1 < person2));
}

} // workspace


int main() {
    std::cout << "test => [ok]" << std::endl;
    workspace::run();
    std::cout << std::endl;

    return 0;
}
