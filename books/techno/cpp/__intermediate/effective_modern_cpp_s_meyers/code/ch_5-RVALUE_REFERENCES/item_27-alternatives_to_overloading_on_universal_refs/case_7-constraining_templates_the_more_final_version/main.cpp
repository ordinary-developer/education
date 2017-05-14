#include <type_traits>
#include <string>


class Person {
    public:
        template <
            typename T,
            typename = std::enable_if_t<
                !std::is_base_of<Person, std::decay_t<T>>::value
                &&
                !std::is_integral<std::remove_reference_t<T>>::value
            >
        >
        explicit Person(T&& n)
            : name(std::forward<T>(n)) 
        {
            static_assert(
                std::is_constructible<std::string, T>::value,
                "Parameter n can't be used to construct a std::string"
            );
        }

        explicit Person(int idx)
            :name(nameFromIdx(idx)) { }

    private:
        std::string nameFromIdx(int idx) {
            return std::string("exempli gratia");
        }

        std::string name;
};


int main() {
    return 0;
}
