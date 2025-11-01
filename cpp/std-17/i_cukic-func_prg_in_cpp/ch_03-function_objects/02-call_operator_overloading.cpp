#include <string>
namespace {
class person_t final {
    public:
        enum gender_t { female, male, other };

        person_t(std::string const& name, gender_t const gender, int const age)
            : name_{ name }, gender_{ gender }, age_{age} {}

        std::string name() const { return name_; }
        gender_t gender() const { return gender_; }
        int age() const { return age_; }

    private:
        std::string const name_;
        gender_t const gender_;
        int const age_;
};


} // anonymous namespace


#include <algorithm>
#include <vector>
#include <cassert>
namespace test {

bool older_than_42(person_t const& person) { return person.age() > 42; }

class older_than {
public:
    older_than(int const limit) : m_limit{limit} {}

    bool operator()(person_t const& person) const { return person.age() > m_limit; }

private:
    int m_limit;
};


void run() {
    std::vector<person_t> const people {
        { "David"  , person_t::male   , 56 },
        { "Jane"   , person_t::female , 24 },
        { "Martha" , person_t::female , 52 },
        { "Peter"  , person_t::male   , 84 },
        { "Rose"   , person_t::female , 32 },
        { "Tom"    , person_t::male   , 31 } };

    assert(3 == std::count_if(std::cbegin(people), std::cend(people), older_than_42));
    assert(3 == std::count_if(std::cbegin(people), std::cend(people), older_than(42)));
}

} // test

#include <iostream>
int main() {
    std::cout << "test => [ok]" << std::endl; test::run(); 
    

    return 0;
}
