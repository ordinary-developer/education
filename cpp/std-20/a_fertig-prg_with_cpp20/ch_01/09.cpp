#include <iostream>
#include <type_traits>
namespace example_01 {

template <typename T>
concept HasRelease = requires(T t)
{
    t.Release();
};

template <typename T>
concept NotTriviallyDestructible = 
    not std::is_trivially_destructible_v<T>;

template <typename T>
class MyOptional {
public:
    MyOptional() = default;

    ~MyOptional() requires (NotTriviallyDestructible<T>)
    {
        if (has_value()) {
            std::cout << "a custom desctructor 01" << std::endl;   

            // value.as()->~T();
        }
    }

    ~MyOptional() requires (NotTriviallyDestructible<T>
                            and HasRelease<T>)
    {
        if (has_value()) {
            std::cout << "a custom destructor 02" << std::endl;

            // value.as()->Release();
            // value.as()->~T();
        }
    }

    ~MyOptional() requires HasRelease<T> {
        if (has_value()) {
            std::cout << "a custom destructor 03" << std::endl;
        }
    }

    ~MyOptional() = default;

    MyOptional(const MyOptional&) requires std::is_copy_constructible_v<T> = default;

private:
    bool has_value() { return true; }
};

struct SimpleType {};

struct ComplexType {
    ~ComplexType() {
        std::cout << "ComplexType destructor" << std::endl;
    }
};

struct ComplexTypeWithRelease {
    void Release() {
        std::cout << "ComplexTypeWithRelease::Release" << std::endl;
    }

    ~ComplexTypeWithRelease() {
        std::cout << "ComplexTypeWithRelease" << std::endl;
    }
};

struct SimpleTypeWithRelease {
    void Release() {
        std::cout << "SimpleTypeWithRelease::Release" << std::endl;
    }
};

MyOptional<SimpleType> _;
MyOptional<ComplexType> __;
MyOptional<ComplexTypeWithRelease> ___;
MyOptional<SimpleTypeWithRelease> ____;

void run() {
    std::cout << "[ ok ] example 01" << std::endl;
}

} // example 01



int main() {
    example_01::run();
}

