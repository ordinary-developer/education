class Base {
    public:
        virtual void mf1() const { } 
        virtual void mf2(int x) { }
        virtual void mf3() & { }
        void mf4() const { }
};

class Derived : public Base {
    public:
        // error: has no "const"
        virtual void mf1() { } 

        // error: uses unsigned int instead of int
        virtual void mf2(unsigned int x) { }

        // error: uses && instead of &
        virtual void mf3() && { }

        // error: mf4() isn't declared virtual in Base
        void mf4() const { }
};

int main() {

}
