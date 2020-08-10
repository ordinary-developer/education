#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>


namespace {
class person_t final {
    public:
        enum gender_t { male, female, other };

        person_t() : name_{ "none" }, gender_{ gender_t::male } { } 
    
        person_t(std::string const& name, gender_t const gender)
            : name_{ name }, gender_{ gender } {}

        std::string name() const { return name_; }
        gender_t gender() const { return gender_; }

        friend std::ostream& operator << (std::ostream&, person_t const&); 

    private:
        std::string name_;
        gender_t gender_;
};
    
std::ostream& operator << (std::ostream& out, person_t const& person) {
    out << person.name();
    return out;
}
} // anonymous namespace

bool is_female(person_t const& person) { return person_t::female == person.gender(); }
bool is_not_female(person_t const& person) { return not is_female(person); }

int main() {
    std::vector<person_t> people {
        { "David" , person_t::male   },
        { "Jane"  , person_t::female },
        { "Martha", person_t::female },
        { "Peter" , person_t::male   },
        { "Rose"  , person_t::female },
        { "Tom"   , person_t::male   }
    };

    people.erase(
        std::remove_if(people.begin(), people.end(), is_not_female),
        people.end());

    std::copy(std::cbegin(people), std::cend(people),
        std::ostream_iterator<person_t>(std::cout, " "));

    return 0;
}
