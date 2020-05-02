#include <type_traits>
#include <iostream>

template <typename T>
void process_helper(T const& t, std::true_type) {
    std::cout << t << " is an integral type." << std::endl;
}

template <typename T>
void process_helper(T const& t, std::false_type) {
    std::cout << t << " is a non-integral type." << std::endl;
}

template <typename T>
void process(T const& t) {
    process_helper(t, typename std::is_integral<T>::type());
}


#include <string>
int main() {
    process(123);
    process(2.2);
    process(std::string{"Test"});

    return 0;
}
