// current function declaration
#include <vector>

void f(const std::vector<int>& v) { }

// template definition
#include <memory>

template <typename... Ts>
void fwd(Ts&&... params) 
{
    f(std::forward<Ts>(params)...);
}


int main() {
    // Will be compiled
    f({ 1, 2, 3 });

    // Will be not compiled
    // fwd({ 1, 2, 3 });
    
    // Will be compiled
    auto il = { 1, 2, 3 };
    fwd(il);

    return 0;
}
