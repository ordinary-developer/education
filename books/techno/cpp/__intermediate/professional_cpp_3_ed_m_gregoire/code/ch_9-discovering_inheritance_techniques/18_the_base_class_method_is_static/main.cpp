#include <iostream>
#include <string>

class SuperStatic {
    public:
        static void beStatic() {
            std::cout << "SuperStatic being static." << std::endl;
        }
};

class SubStatic : public SuperStatic {
    public:
        static void beStatic() {
            std::cout << "SubStatic keepin' in static." << std::endl;
        }
};

auto main() -> int {
    SuperStatic::beStatic();
    SubStatic::beStatic();

    SubStatic mySubStatic;
    SuperStatic& ref = mySubStatic;
    mySubStatic.beStatic();
    ref.beStatic();

    return 0;
}
