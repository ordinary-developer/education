#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <cassert>
namespace test {

class Person final {
    public:
        enum class Gender { Male, Female, Other };

        Person(std::string const& name = "none", Gender const gender = Gender::Male)
            : name_{name}, gender_{gender} {}

        bool operator ==(Person const& other) const { return other.name_ == name_ and other.gender_ == gender_; }

        std::string name() const { return name_; }
        Gender gender() const { return gender_; }

    private:
        std::string name_;
        Gender gender_;
};

bool isFemale(Person const& person) { return Person::Gender::Female == person.gender(); }
std::string name(Person const& person) { return person.name(); }

void run() {
    std::vector<Person> people {
        { "David" , Person::Gender::Male   },
        { "Jane"  , Person::Gender::Female },
        { "Martha", Person::Gender::Female },
        { "Peter" , Person::Gender::Male   },
        { "Rose"  , Person::Gender::Female },
        { "Tom"   , Person::Gender::Male   }};


    std::vector<Person> females{};
    std::copy_if(std::cbegin(people), std::cend(people), 
        std::back_inserter(females), isFemale);

    std::vector<std::string> names(females.size());
    std::transform(std::cbegin(females), std::cend(females),
        std::begin(names), name);

    assert((std::vector<std::string>{ "Jane", "Martha", "Rose" } == names));
}
} // test


#include <iostream>
int main() {
    std::cout << "test => [ok]" << std::endl; test::run(); std::cout << std::endl;

    return 0;
}
