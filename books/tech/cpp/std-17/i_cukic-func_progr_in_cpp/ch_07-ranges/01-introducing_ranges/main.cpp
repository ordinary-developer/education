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
    
bool is_female(person_t const& person) { return person_t::female == person.gender(); }
std::string pull_name(person_t const& person) { return person.name(); }
    
} // anonymous namespace


#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <initializer_list>
#include <vector>
#include <cassert>
namespace test {    
    
namespace rv = std::ranges::views;
namespace rg = std::ranges;
    
void run() {
    std::initializer_list<person_t> const people {
        { "David"  , person_t::male   , 56 },
        { "Jane"   , person_t::female , 24 },
        { "Martha" , person_t::female , 52 },
        { "Peter"  , person_t::male   , 84 },
        { "Rose"   , person_t::female , 32 },
        { "Tom"    , person_t::male   , 31 } };
    
    
    auto names = people 
        | std::views::filter(is_female) 
        | std::views::transform(pull_name);
    std::ranges::copy(names, std::ostream_iterator<std::string>{std::cout, " "});
    std::cout << std::endl;
    
    std::initializer_list<std::string> const expected_names_raw{ "Jane", "Martha", "Rose" };
    auto expected_names = std::views::all(expected_names_raw);
    assert(std::ranges::equal(expected_names, names));
  
    
    auto first_two = people
        | std::views::filter(is_female)
        | std::views::transform(pull_name)
        | std::views::take(2);
    
    std::initializer_list<std::string> const expected_first_two_raw{ "Jane", "Martha" };
    auto expected_first_two = std::views::all(expected_first_two_raw);
    assert(std::ranges::equal(expected_first_two, first_two));    
}
    
} // test


#include <iostream>
int main() {
    std::cout << "test => [ok]" << std::endl; test::run(); std::cout << std::endl;   
        
    return 0;
}
