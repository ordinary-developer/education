#include <cstddef>
#include <string>


template <class T>
class hash {
    public:
        std::size_t operator()(T const& x) const {
            return reinterpret_cast<std::size_t>(&x);
        }
};

template <>
class hash<std::string> {
    public:
        std::size_t operator()(std::string const& str) const {
            std::size_t h{0};
            for (auto c : str)
                h = h << 1 | c;
            return h;
        }
};
