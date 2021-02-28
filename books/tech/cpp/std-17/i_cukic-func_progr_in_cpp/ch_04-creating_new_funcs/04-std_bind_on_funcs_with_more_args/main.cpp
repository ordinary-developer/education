#include <ostream>
#include <string>
namespace {
class person_t final {
    public:
        enum gender_t { female, male, other };

        enum output_format_t { name_only, full_name };

        person_t(std::string const& name, std::string const& surname, gender_t const gender, int const age = 0)
            : name_{ name }, surname_{ surname }, gender_{ gender }, age_{age} {}

        person_t(std::string const& name, gender_t const gender)
            : person_t{ name, "Doe", gender } {}

        std::string name() const { return name_; }
        std::string surname() const { return surname_; }
        gender_t gender() const { return gender_; }
        int age() const { return age_; }

        void print(std::ostream& out, person_t::output_format_t const fmt) const {
            if (person_t::name_only == fmt)
                out << name() << '\n';
            else if (person_t::full_name == fmt)
                out << name() << ' ' << surname() << '\n';
        }

    private:
        std::string const name_;
        std::string const surname_;
        gender_t const gender_;
        int const age_;
};

} // anonymous namespace


#include <algorithm>
#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <vector>
namespace test {

void print_person(person_t const& person, std::ostream& out, person_t::output_format_t const& fmt) {
    if (person_t::name_only == fmt)
        out << person.name() << '\n';
    else if (person_t::full_name == fmt)
        out << person.name() << ' ' << person.surname() << '\n';
}

void run() {
    using namespace std::placeholders;

    std::vector<person_t> const people {
        { "David"  , person_t::male   },
        { "Jane"   , person_t::female },
        { "Martha" , person_t::female },
        { "Peter"  , person_t::male   },
        { "Rose"   , person_t::female },
        { "Tom"    , person_t::male   } };

    std::ofstream file{"test"};

    // passing a non-member function as the function object to std::bind
    std::for_each(std::cbegin(people), std::cend(people), 
        std::bind(print_person, _1, std::ref(std::cout), person_t::name_only));

    std::for_each(std::cbegin(people), std::cend(people),
        std::bind(print_person, _1, std::ref(file), person_t::full_name));

    std::cout << std::endl;

    // passing a member function pointer to std::bind
    std::for_each(std::cbegin(people), std::cend(people),
        std::bind(&person_t::print, _1, std::ref(std::cout), person_t::name_only));

    std::cout << std::endl;

    // passing a lambda function instead of using std::bind
    std::for_each(std::cbegin(people), std::cend(people),
        [](person_t const& person) {
            print_person(person, std::cout, person_t::name_only);
        });

    std::for_each(std::cbegin(people), std::cend(people),
        [&file](person_t const& person) {
            print_person(person, file, person_t::full_name);
        });
}

} // test


#include <iostream>
int main() {
    std::cout << "test => [ok]" << std::endl; test::run(); std::cout << std::endl;

    return 0;
}
