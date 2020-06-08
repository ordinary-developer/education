#include <ostream>

class MyClass {
    public:
        bool IsValid() const { return true; }
        friend std::ostream& operator <<(std::ostream& os,
                                         const MyClass& obj);
};


inline std::ostream& operator <<(std::ostream& os,
                                 const MyClass& obj)
{
    return os;
}


#include "scpp_assert.hpp"
int main() {
    MyClass obj{ };
    SCPP_ASSERT(obj.IsValid(), "Object " << obj << " is invalid.");
    SCPP_ASSERT(!obj.IsValid(), "Object " << obj << " is invalid.");

    return 0;
}

