#include <iostream>
#include <type_traits>
#include <vector>
namespace example_01 {

template <typename T>
using storage_t = std::vector<T>;

template <typename T>
class MyOptional {
public:
    MyOptional() = default;

    template <
        typename U,
        typename = std::enable_if_t<std::is_same_v<U, MyOptional> and
                                    std::is_copy_constructible_v<T>
                                   >>
    MyOptional(const U&);

private:
    storage_t<T> value;
};

struct NotCopyable {
    NotCopyable(const NotCopyable&) = delete;
    NotCopyable& operator=(const NotCopyable&) = delete;
};


MyOptional<NotCopyable> a{};

// This should fail
// MyOptional<NotCopyable> b = a;



void run() {
    std::cout << "[ ok ] example 01" << std::endl;
}

} // example_01



#include <iostream>
#include <type_traits>
namespace example_02 {

struct copyable {};

struct notCopyable {
    notCopyable(const notCopyable&) = delete;
    notCopyable& operator=(const notCopyable&) = delete;
};

template <typename T>
using storage_t = std::vector<T>;

template <typename T>
class MyOptional
: public std::conditional_t<std::is_copy_constructible_v<T>,
                            copyable,
                            notCopyable>
{
public:
    MyOptional() = default;

private:
    storage_t<T> value;
};


struct Copyable {};
struct NotCopyable {
    NotCopyable(const NotCopyable&) = delete;
    NotCopyable& operator=(const NotCopyable&) = delete;
};

MyOptional<Copyable> a;

// does not work
//MyOptional<NotCopyable> b;


void run() {
    std::cout << "[ ok ] example 02" << std::endl;
}

} // example _02



#include <iostream>
#include <type_traits>
namespace example_03 {

template <typename T>
class MyOptional {
public:
    MyOptional() = default;

    MyOptional(const MyOptional&) requires std::is_copy_constructible_v<T>;
};

struct Copyable {};

struct NotCopyable {
    NotCopyable(const NotCopyable&) = delete;
    NotCopyable& operator=(const NotCopyable&) = delete;
};

MyOptional<Copyable> a;
MyOptional<NotCopyable> b;

void run() {
    std::cout << "[ ok ] example 03" << std::endl;
}

} // example 03



#include <iostream>
#include <type_traits>
namespace example_04 {

template <typename T>
class MyOptional {
public:
    MyOptional() = default;

    ~MyOptional() requires (not std::is_trivially_destructible_v<T>)
    {
        if (has_value()) {
            std::cout << "bam" << std::endl;
            // call the destructor 
        }
    }

    ~MyOptional() = default;

    MyOptional(const MyOptional&) requires std::is_copy_constructible_v<T> = default;

private:
    bool has_value() { return true; }
};

struct Copyable {};

struct NotCopyable {
    NotCopyable(const NotCopyable&) = delete;
    NotCopyable& operator=(const NotCopyable&) = delete;
};

MyOptional<Copyable> a;
MyOptional<NotCopyable> b;


void run() {
    std::cout << "[ ok ] example 04" << std::endl;

}    

} // example_04


int main() {
    example_01::run();
    example_02::run();
    example_03::run();
    example_04::run();
}