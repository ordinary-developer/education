#include <memory>

void f(int (*pf)(int)) { }

template <typename... Ts>
void fwd(Ts&&... params)
{
    f(std::forward<Ts>(params)...);
}

int processVal(int value) { return 0; }
int processVal(int value, int priority) { return 0; }

template <typename T>
T workOnVal(T param) { }


using ProcessFuncType = int (*)(int);

int main() {
    // Ok
    f(workOnVal);
    // Error
    // fwd(workOnVal);
    
    // Ok
    ProcessFuncType processValPtr = workOnVal;
    fwd(processValPtr);
    
    // Ok
    fwd(static_cast<ProcessFuncType>(workOnVal));

    return 0;
}
