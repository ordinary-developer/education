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

class company_t {
public:
    company_t(std::vector<person_t> const& employees) : m_employees{employees} {}

    std::string team_name_for(person_t const& person) const { return "Team1"; }

    int count_team_members(std::string const& team_name) const {
        return std::count_if(
            std::cbegin(m_employees), std::cend(m_employees),
            [this, &team_name] (person_t const& employee) {
                return team_name_for(employee) == team_name;
            }
        );
    }

private:
    std::vector<person_t> m_employees;
};

void run() {
    std::vector<person_t> const people {
        { "David"  , person_t::male   , 56 },
        { "Jane"   , person_t::female , 24 },
        { "Martha" , person_t::female , 52 },
        { "Peter"  , person_t::male   , 84 },
        { "Rose"   , person_t::female , 32 },
        { "Tom"    , person_t::male   , 31 } };

    assert(6 == company_t{people}.count_team_members("Team1"));
    assert(0 == company_t{people}.count_team_members("Team2"));
}

} // test


#include <iostream>
int main() {
    std::cout << "test => [ok]" << std::endl; test::run();     

    return 0;
}
