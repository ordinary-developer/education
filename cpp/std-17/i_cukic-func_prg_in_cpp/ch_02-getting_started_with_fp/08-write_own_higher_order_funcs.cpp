#include <string>
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

std::string name(person_t const& person) { return person.name(); }
bool is_female(person_t const& person) { return person.gender() == person_t::female; }

} // anonymous namespace


#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <cassert>
namespace test_01 { // implement with loops

template <typename FilterFunction>
std::vector<std::string> names_for(
    std::vector<person_t> const& people,
    FilterFunction filter)
{
    std::vector<std::string> ret{};

    for (person_t const& person : people)
        if (filter(person))
            ret.push_back(name(person));

    return ret;
}

void run() {
    std::vector<person_t> const people {
        { "David"  , person_t::male   },
        { "Jane"   , person_t::female },
        { "Martha" , person_t::female },
        { "Peter"  , person_t::male   },
        { "Rose"   , person_t::female },
        { "Tom"    , person_t::male   } };

    auto const& names = names_for(people, is_female);
   
    assert((std::vector<std::string>{ "Jane", "Martha", "Rose"} == names));
}
} // test_01


#include <algorithm>
#include <string>
#include <vector>
namespace test_02 { // implement with a recursion

template <typename T>
T tail(T const& collection) { return T(collection.cbegin() + 1, collection.cend()); }

template <typename T, typename C>
C prepend(T&& item, C collection) {
    C ret(collection.size() + 1);
    ret[0] = std::forward<T>(item);
    std:copy(std::cbegin(collection), std::cend(collection), ret.begin() + 1);
    return ret;
}

template <typename FilterFunction>
std::vector<std::string> names_for(
    std::vector<person_t> const& people,
    FilterFunction filter)
{
    if (people.empty()) {
        return {};
    }
    else {
        auto const head = people.front();
        auto const processed_tail = names_for(tail(people), filter);
        return (filter(head) ? prepend(name(head), processed_tail) : processed_tail);
    }
}

void run() {
    std::vector<person_t> const people {
        { "David"  , person_t::male   },
        { "Jane"   , person_t::female },
        { "Martha" , person_t::female },
        { "Peter"  , person_t::male   },
        { "Rose"   , person_t::female },
        { "Tom"    , person_t::male   } };

    auto const& names = names_for(people, is_female);
   
    assert((std::vector<std::string>{ "Jane", "Martha", "Rose"} == names));
}
} // test_02


#include <memory>
#include <string>
#include <vector>
namespace test_03 { // implement with a tail recursion

template <typename FilterFunction, typename Iterator>
std::vector<std::string> names_for_helper(
    Iterator people_begin,
    Iterator people_end,
    FilterFunction filter,
    std::vector<std::string> prev_collected)
{
    if (people_begin == people_end) {
        return prev_collected;
    }
    else {
        const auto head = *people_begin;
        if (filter(head)) {
            prev_collected.push_back(name(head));
        }

        return names_for_helper(
            people_begin + 1,
            people_end,
            filter,
            std::move(prev_collected));
    }
}

template <typename FilterFunction, typename Iterator>
std::vector<std::string> names_for(
    Iterator people_begin,
    Iterator people_end,
    FilterFunction filter)
{
    return names_for_helper(people_begin, people_end, filter, {});
}

void run() {
    std::vector<person_t> const people {
        { "David"  , person_t::male   },
        { "Jane"   , person_t::female },
        { "Martha" , person_t::female },
        { "Peter"  , person_t::male   },
        { "Rose"   , person_t::female },
        { "Tom"    , person_t::male   } };

    auto const& names = names_for(
        std::begin(people), std::end(people), is_female);
  
    assert((std::vector<std::string>{ "Jane", "Martha", "Rose"} == names));   
}
} // test_03


#include <iostream>
int main() {
    std::cout << "test 01 => [ok]" << std::endl; test_01::run(); 
    std::cout << "test 02 => [ok]" << std::endl; test_02::run();    
    std::cout << "test 03 => [ok]" << std::endl; test_03::run();
    std::cout << "test 04 => [ok]" << std::endl; test_04::run();

    return 0;
}
