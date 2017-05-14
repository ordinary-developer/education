#include <type_traits>
#include <string>


class Person {
    public:
        template <
            typename T,
            typename = std::enable_if_t<
                        ! std::is_base_of<Person,
                                          std::decay_t<T>
                                         >::value
                       >
        >
        explicit Person(T&& n) 
            : name(std::forward<T>(n)) { }

        explicit Person(int idx) 
            :name(nameFromIdx(idx)) { }

    private:
        std::string nameFromIdx(int idx) {
            return std::string("exempli gratia");
        }

        std::string name;
};

class SpecialPerson : public Person {
    public:
        SpecialPerson(const SpecialPerson& rhs) 
            : Person(rhs) { }

        SpecialPerson(SpecialPerson&& rhs)
            : Person(std::move(rhs)) { }

};


int main() {
    return 0;
}


