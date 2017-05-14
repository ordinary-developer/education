#ifndef SUPER_HPP
#define SUPER_HPP

class Super {
    public:
        Super();
        virtual void someMethod();
    protected:
        int mProtectedInt;
    private:
        int mPrivateInt;
};

#endif
