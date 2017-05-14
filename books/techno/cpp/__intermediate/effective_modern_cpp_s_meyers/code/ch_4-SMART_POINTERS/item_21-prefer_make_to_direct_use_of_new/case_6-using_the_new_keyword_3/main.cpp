#include <memory>

class ReallyBigType { };

int main() {
    // before destroying weak_ptr
    // memory can be occupied
    auto pBigObj1 = std::make_shared<ReallyBigType>();

    // after destroying the object
    // only the control block can be still allocated
    std::shared_ptr<ReallyBigType> pBigObj2(new ReallyBigType);

    return 0;
}
