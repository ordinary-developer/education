#include <memory>
namespace example1 {

class EG { };

std::shared_ptr<EG> func() {
    auto ptr = std::make_shared<EG>();
    return ptr;
}

void run() {
    std::shared_ptr<EG> ptr{ func() };
}

}

#include <memory>
#include <utility>
namespace example2 {

void run() {
    auto ptr1 = std::make_unique<int>(42);
    std::unique_ptr<int> p2{ std::move(ptr1) };
}

}

int main() {
    example1::run();
    example2::run();

    return 0;
}
