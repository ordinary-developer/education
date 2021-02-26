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
bool isNotFemale(Person const& person) { return not isFemale(person); }

void run() {
    std::vector<Person> people {
        { "David" , Person::Gender::Male   },
        { "Jane"  , Person::Gender::Female },
        { "Martha", Person::Gender::Female },
        { "Peter" , Person::Gender::Male   },
        { "Rose"  , Person::Gender::Female },
        { "Tom"   , Person::Gender::Male   }};

    people.erase(
        std::remove_if(std::begin(people), std::end(people), isNotFemale),
        std::end(people));

    std::vector<Person> const expected {
        { "Jane"  , Person::Gender::Female },
        { "Martha", Person::Gender::Female },
        { "Rose"  , Person::Gender::Female } };
    assert(expected == people);
}
} // test


#include <iostream>
int main() {
    std::cout << "test => [ok]" << std::endl; test::run(); std::cout << std::endl;

    return 0;
}
