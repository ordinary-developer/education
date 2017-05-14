#include <chrono>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std::literals;

class MyClass {
    public:
        MyClass() = default;
        MyClass(const MyClass& rhs) = default;
        MyClass(MyClass&& rhs) = default;

        int GetValue() const { return m_Value; }

    private:
        std::vector<std::string> m_String{
            "This is a pretty long string that"
            " must be copy constructed into"
            " copyConstructed!"s
        };

        int m_Value{ 1 };
};

int main() {
    using MyVector = std::vector<MyClass>;
    constexpr unsigned int ITERATIONS{ 1'000'000U };


    MyVector copyConstructed(ITERATIONS);
    int value{ 0 };

    auto copyStartTime 
        = std::chrono::high_resolution_clock::now();
    for (unsigned int i{ 0 }; i < ITERATIONS; ++i) {
        MyClass myClass{};
        copyConstructed.push_back(myClass);
        value = myClass.GetValue();
    }
    auto copyEndTime 
        = std::chrono::high_resolution_clock::now();

    std::cout << value << std::endl;


    MyVector moveConstructed(ITERATIONS);

    auto moveStartTime 
        = std::chrono::high_resolution_clock::now();
    for (unsigned int i{ 0 }; i < ITERATIONS; ++i) {
        MyClass myClass{};
        moveConstructed.push_back(std::move(myClass));
        value = myClass.GetValue();
    }
    auto moveEndTime 
        = std::chrono::high_resolution_clock::now();

    std::cout << value << std::endl;


    auto copyDuration =
        std::chrono::duration_cast<std::chrono::milliseconds>(
                copyEndTime - copyStartTime);
    std::cout << "Copy lasted: " << copyDuration.count() << "ms"
              << std::endl;

    auto moveDuration =
        std::chrono::duration_cast<std::chrono::milliseconds>(
                moveEndTime - moveStartTime);
    std::cout << "Move lasted: " << moveDuration.count() << "ms"
              << std::endl;

    return 0;
}
