#include "assignment_mixin.hpp"

#include <string>
#include <utility>

class thing : public assignment_mixin<thing> {
    public:
        thing() : value_{} { }
        thing(std::string const& str) : value_{str} { }

        void swap(thing& other) { value_.swap(other.value_); }

    private:
        std::string value_;
};

int main() {
    thing one{};
    thing two{"two"};
    one = two;

    return 0;
}
