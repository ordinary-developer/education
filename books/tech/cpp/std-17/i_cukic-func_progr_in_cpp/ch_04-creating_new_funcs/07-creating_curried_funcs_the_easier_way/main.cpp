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


#include <iostream>
#include <functional>
#include <cassert>
namespace test {

void print_person(person_t const& person, std::ostream& out, person_t::output_format_t const& fmt) {
    if (person_t::name_only == fmt)
        out << person.name() << '\n';
    else if (person_t::full_name == fmt)
        out << person.name() << ' ' << person.surname() << '\n';
}

auto print_person_cd(person_t const& person) {
    return [&](std::ostream& out) {
        return [&](person_t::output_format_t const& fmt) {
            print_person(person, out, fmt);
        };
    };
}

void run() {
    person_t const martha{ "Martha", person_t::female };
    
    print_person_cd(martha)(std::cout)(person_t::full_name);

    auto const& print1 = print_person_cd(martha);
    print1(std::cout)(person_t::name_only);

    auto const& print2 = print_person_cd(martha)(std::cout);
    print2(person_t::name_only);
    

}

} // test


#include <iostream>
int main() {
    std::cout << "test => [ok]" << std::endl; test::run(); std::cout << std::endl;

    return 0;
}
