#include <string>
#include <memory>


class Person {
    public:
        template <typename T>
        explicit Person(T&& n)
            : name(std::forward<T>(n)) { }

        explicit Person(int idx) 
            : name(nameFromIdx(idx)) { } 

        // a dump function
        std::string nameFromIdx(int index) {
            return std::string("exempli gratia");
        }
    private:
        std::string name;
};

class SpecialPerson : public Person {
    public:
        // an error of the compile will occur
        // calls base class forwarding ctor!
        // SpecialPerson(const SpecialPerson& rhs) 
        //    : Person(rhs) { }

        // an error of the compiler will occur
        // calls base class forwardig ctor!
        // SpecialPerson(SpecialPerson&& rhs)
        //    : Person(std::move(rhs)) { }
};

int main() {
    return 0;
}
