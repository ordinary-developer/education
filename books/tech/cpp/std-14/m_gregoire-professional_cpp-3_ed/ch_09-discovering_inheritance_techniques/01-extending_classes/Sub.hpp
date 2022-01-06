#ifndef SUB_HPP
#define SUB_HPP

#include "Super.hpp"

class Sub : public Super {
    public:
        Sub();
        virtual void someMethod() override;
        virtual void someOtherMethod();
};

#endif

