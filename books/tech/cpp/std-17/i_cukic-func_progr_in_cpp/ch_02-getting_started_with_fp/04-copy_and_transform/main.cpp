#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>


namespace {
class person_t final {
    public:
        enum gender_t { female, male, other };

        person_t(std::string const& name, gender_t const gender)
            : name_{ name }, gender_{ gender } {}

        std::string name() const { return name_; }
        gender_t gender() const { return gender_; }

    private:
        std::string const name_;
        gender_t const gender_;
};
} // anonymous namespace


std::string name(person_t const& person) { return person.name(); }
bool is_female(person_t const& person) { return person_t::female == person.gender(); }

int main() {
    std::vector<person_t> people {
        { "David",  person_t::male   },
        { "Jane",   person_t::female },
        { "Martha", person_t::female },
        { "Peter",  person_t::male   },
        { "Rose",   person_t::female },
        { "Tom",    person_t::male   }
    };

    std::vector<person_t> females{};
    std::copy_if(std::cbegin(people), std::cend(people),
        std::back_inserter(females), is_female);

    std::vector<std::string> names(females.size());
    std::transform(std::cbegin(females), std::cend(females),
        names.begin(), name);
    
    std::copy(std::cbegin(names), std::cend(names),
        std::ostream_iterator<std::string>{ std::cout, " " });

    return 0;
}
