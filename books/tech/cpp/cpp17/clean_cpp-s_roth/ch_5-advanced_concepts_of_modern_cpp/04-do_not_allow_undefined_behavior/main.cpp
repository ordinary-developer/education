#include <cstddef>
#include <memory>
namespace example01 {

template <typename Type>
struct CustomArrayDeleter {
    void operator()(Type const* pointer) { delete[] pointer; }
};

void run() {
    std::size_t const NUMBER_OF_STRINGS{ 100 };

    std::shared_ptr<std::string> arrayOfStrings1{ 
        new std::string[NUMBER_OF_STRINGS], 
        CustomArrayDeleter<std::string>{} };

    std::shared_ptr<std::string> arrayOfStrings2{ 
        new std::string[NUMBER_OF_STRINGS],
        std::default_delete<std::string[]>{} };
}
} // namespace example01

int main() {
    example01::run();

    return 0;
}
