#include <memory>

void f(int (*pf)(int)) { }

template <typename... Ts>
void fwd(Ts&&... params)
{
    f(std::forward<Ts>(params)...);
}

int processVal(int value) { return 0; }
int processVal(int value, int priority) { return 0; }


using ProcessFuncType = int (*)(int);

int main() {
    // Ok
    f(processVal);
    // will not be compiled
    // fwd(processVal);
    
    // OK
    ProcessFuncType processValPtr = processVal;
    fwd(processValPtr);

    return 0;
}
