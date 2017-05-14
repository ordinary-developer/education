#include <iostream>

class Secret {
    protected:
        virtual void dontTell() {
            std::cout << "I'll never tell." << std::endl;
        }
};

class Blabber : public Secret {
    public:
        virtual void tell() { dontTell(); }
};

auto main() -> int {
    Blabber blabber;
    blabber.tell();

    return 0;
}
