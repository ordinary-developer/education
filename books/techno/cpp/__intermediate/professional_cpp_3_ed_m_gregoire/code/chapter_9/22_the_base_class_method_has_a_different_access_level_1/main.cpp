#include <iostream>

class Gregarious {
    public:
        virtual void talk() {
            std::cout << "Gregarious says hi!" << std::endl;
        }
};

class Shy : public Gregarious {
    protected:
        virtual void talk() override {
            std::cout << "Shy reluctantly syas hello." << std::endl;
        }
};

auto main() -> int {
    Shy myShy;
    Gregarious& ref = myShy;
    ref.talk();

    // will not compile
    // myShy.talk();

    return 0;
}
