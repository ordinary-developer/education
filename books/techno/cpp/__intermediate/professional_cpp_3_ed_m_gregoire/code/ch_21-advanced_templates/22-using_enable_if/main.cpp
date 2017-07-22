#include <iostream>
#include <type_traits>

template <typename T1, typename T2>
typename std::enable_if<std::is_same<T1, T2>::value, bool>::type
    check_type(T1 const& t1, T2 const& t2) 
{
    std::cout << "'" << t1 << "' and '" << t2 << "' ";
    std::cout << "are the same types." << std::endl;
    return true;
}

template <typename T1, typename T2>
typename std::enable_if<not std::is_same<T1, T2>::value, bool>::type
    check_type(T1 const& t1, T2 const& t2) 
{
    std::cout << "'" << t1 << "' and '" << t2 << "' ";
    std::cout << "are differenct types." << std::endl;
    return false;
}

#include <iostream>
int main() {
    check_type(1, 32);
    check_type(1, 3.01);
    check_type(3.01, std::string{ "Test" });

    return 0;
}
