#include <memory>
#include <iostream>

class Demo {
    public:
        static int get() { return 5; }
};

int get() { return 10; }

namespace NS {
    int get() { return 20; }
}

auto main() -> int {
    auto pd = std::make_unique<Demo>();
    Demo d;
    std::cout << pd->get() << std::endl;
    std::cout << d.get() << std::endl;
    std::cout << NS::get() << std::endl;
    std::cout << ::get() << std::endl;
    std::cout << get() << std::endl;

    return 0;
}
