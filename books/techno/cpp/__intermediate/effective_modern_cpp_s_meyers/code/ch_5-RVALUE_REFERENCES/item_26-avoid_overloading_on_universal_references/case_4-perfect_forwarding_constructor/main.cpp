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

int main() {
    // all is OK
    std::string stringValue("simple string value");
    Person person1(stringValue);

    // all is OK
    int integerValue = 0;
    Person person2(integerValue);

    // an error of the compiler will be
    // short shortValue = 0;
    // Person person3(shortValue);

    return 0;
}
