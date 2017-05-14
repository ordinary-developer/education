#include <cstddef> // for size_t
#include <functional> // for struct hash
#include <unordered_set>
#include <iostream>


class IntWrapper {
    public:
        IntWrapper(int i) : _i(i) { }
        int getValue() const { return _i; }

        friend bool operator == (
                const IntWrapper& lhs, const IntWrapper& rhs);
    private:
        int _i;
};

bool operator == (const IntWrapper& lhs, const IntWrapper& rhs) {
    return lhs._i == rhs._i;
}

namespace std {
    template<> struct hash<IntWrapper> {
        typedef IntWrapper argument_type;
        typedef size_t result_type;
        result_type operator () (const argument_type& f) const {
            return std::hash<int>()(f.getValue());
        }
    };
}


auto main() -> int {
    std::unordered_set<IntWrapper> s;

    s.insert(IntWrapper(1));
    s.insert(IntWrapper(2));

    for (const auto& element : s) {
        std::cout << element.getValue() << std::endl;
    }

    return 0;
}
