#include <iostream>
#include <vector>
#include <cassert>
namespace example_01 {

template <typename T>
concept SupportsValidation = requires(T t)
{
    t.validate();
};

template <typename T>
void Send(const T& data)
{
    if constexpr(SupportsValidation<T>) { data.validate(); }
}

class ComplexType {
public:
    void validate() const {
        assert(true);
    };
};

class SimpleType {};


void run() {
    ComplexType complexType;
    Send(complexType);

    SimpleType simpleType;
    Send(simpleType);
}

} // example 01



int main() {
    example_01::run();
}