#include <iostream>

void f(std::size_t val) { }

template <typename... Ts>
void fwd(Ts&&... params) 
{
    f(std::forward<Ts>(params)...);
}


class Widget1 {
    public:
        static const std::size_t MinVals = 28;
};

class Widget2 {
    public:
        static const std::size_t MinVals = 28;
};
const std::size_t Widget2::MinVals;

int main() {
    f(Widget1::MinVals);
    // will not be linked
    // fwd(Widget1::MinVals);
    
    f(Widget2::MinVals);
    // here is all right
    fwd(Widget2::MinVals);

    return 0;
}
