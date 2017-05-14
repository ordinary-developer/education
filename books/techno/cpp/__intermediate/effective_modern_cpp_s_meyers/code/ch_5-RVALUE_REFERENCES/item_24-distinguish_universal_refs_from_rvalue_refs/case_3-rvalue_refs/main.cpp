#include <vector>

// the parameter is an rvalue
template<typename T>
void f(std::vector<T>&& param) { }

// the paramter is an rvalue
template<typename T>
void f2(const T&& param) { }

int main() {
    std::vector<int> v;
    // an error, must be rvalue
    // f(v);

    return 0;
}
