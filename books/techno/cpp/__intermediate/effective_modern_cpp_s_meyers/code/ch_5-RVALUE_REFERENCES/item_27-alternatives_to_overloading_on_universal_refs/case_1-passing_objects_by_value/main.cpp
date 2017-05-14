#include <string>


class Person {
    public:
        explicit Person(std::string n)
            : name(std::move(n)) { }

        explicit Person(int idx)
            : name(nameFromIdx(idx)) { }

    private:
        // a dump function
        std::string nameFromIdx(int idx) {
            return std::string("exempli gratia");
        }

        std::string name;
};


int main() {
    Person p1("exempli gratia");
    Person p2(0);

    return 0;
}
