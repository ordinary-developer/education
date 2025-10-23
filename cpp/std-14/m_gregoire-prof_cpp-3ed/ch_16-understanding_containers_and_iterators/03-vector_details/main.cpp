#include <vector>
#include <string>
#include <memory>

class Element {
    public:
        Element() {  }
        virtual ~Element() { } 
};


auto main() -> int {
    std::vector<int> intVector1;
    std::vector<int> intVector2(10, 100);

    std::vector<std::string> stringVector(10, "Hello");

    std::vector<Element> elementVector;

    std::vector<int> intVector3({1, 2, 3, 4, 5, 6});

    std::vector<int> intVector4 = {1, 2, 3, 4, 5, 6};
    std::vector<int> intVector5{1, 2, 3, 4, 5, 6};

    auto memoryElementVector = std::make_unique<std::vector<Element>>(10);

    return 0;
}
