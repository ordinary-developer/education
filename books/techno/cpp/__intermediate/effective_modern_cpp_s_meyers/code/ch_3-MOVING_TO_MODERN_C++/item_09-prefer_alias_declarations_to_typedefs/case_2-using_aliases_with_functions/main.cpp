#include <string>

// with typedef
typedef void (*FP)(int, const std::string&);

//with aliases
using FP = void (*)(int, const std::string&);

int main() {
}
