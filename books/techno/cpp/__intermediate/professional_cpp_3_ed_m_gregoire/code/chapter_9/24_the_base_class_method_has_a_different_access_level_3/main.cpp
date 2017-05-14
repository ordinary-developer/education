#include <iostream>


class Secret {
    protected:
        virtual void dontTell() {
            std::cout << "I'll never tell." << std::endl;
        }
};

class Blabber : public Secret {
    public:
        virtual void dontTell() override {
            std::cout << "I'll tell all!" << std::endl;
        }
};

auto main() -> int {
    Blabber myBlabber;
    Secret& ref = myBlabber;
    Secret* ptr = &myBlabber;
    myBlabber.dontTell();
    // will not compile
    // ref.dontTell();
    // ptr.dontTell();

    return 0;
}
