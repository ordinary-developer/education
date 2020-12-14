#include <iostream>
#include <vector>
#include <iterator>
namespace example1 {
class MoveableClass {
    public:
        MoveableClass() {
            std::cout << "Default constructor" << std::endl;
        }

        MoveableClass(MoveableClass const& src) {
            std::cout << "Copy constructor" << std::endl;
        }

        MoveableClass(MoveableClass&& src) noexcept {
            std::cout << "Move constructor" << std::endl;
        }

        MoveableClass& operator=(MoveableClass const& rhs) {
            std::cout << "Copy assignment operator" << std::endl;
            return *this;
        }

        MoveableClass& operator=(MoveableClass&& rhs) noexcept {
            std::cout << "Move assignmetn operator" << std::endl;
            return *this;
        }
};

void run() {
    std::vector<MoveableClass> srcVector{};
    MoveableClass moveableClassInstance{};
    srcVector.push_back(moveableClassInstance);
    srcVector.push_back(moveableClassInstance);

    std::vector<MoveableClass> v1{ srcVector.cbegin(),
                                   srcVector.cend() };

    std::vector<MoveableClass> v2{ std::make_move_iterator(std::begin(srcVector)),
                                   std::make_move_iterator(std::end(srcVector)) };
}
}

int main() {
    example1::run();

    return 0;

}

