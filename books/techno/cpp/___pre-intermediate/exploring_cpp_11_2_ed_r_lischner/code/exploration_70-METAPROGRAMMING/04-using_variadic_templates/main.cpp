#include <iostream>
#include <utility>

template <class... Types>
void print(std::ostream& stream, Types&&...);

template <class T, class... Types>
void print_split(std::ostream& stream, T&& head, Types&&... rest)
{
    stream << head << ' ';
    print(stream, std::forward<Types>(rest)...);
}
void print_split(std::ostream&) { }

template <class... Types>
void print(std::ostream& stream, Types&&... args) {
    print_split(stream, std::forward<Types>(args)...);
}

int main() {
    print(std::cout, 42, 'x', "hello", 3.14159, 0, '\n');
}
