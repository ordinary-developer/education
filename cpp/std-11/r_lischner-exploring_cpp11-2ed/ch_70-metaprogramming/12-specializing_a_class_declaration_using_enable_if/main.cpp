#include <limits>
#include <type_traits>

template <
  class T,
  class Enable = typename std::enable_if<std::numeric_limits<T>::is_integer,
                                         T>::type>
class rational { };


int main() {
    rational<long> okay{};

    // compilation error here 
    // rational<float> problem{};

    return 0;
}

