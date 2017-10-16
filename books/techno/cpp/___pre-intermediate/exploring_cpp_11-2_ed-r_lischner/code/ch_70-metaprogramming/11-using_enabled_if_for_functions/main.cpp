#include <limits>
#include <type_traits>

template <class T>
typename std::enable_if<std::numeric_limits<T>::is_signed, T>::type
minus(T const& x) 
{
    return -x;
}

int main() {
    int a{};
    minus(a); // ok

    // unsigned int b{};
    // minus(b); // compilation error
    
    return 0;
}
