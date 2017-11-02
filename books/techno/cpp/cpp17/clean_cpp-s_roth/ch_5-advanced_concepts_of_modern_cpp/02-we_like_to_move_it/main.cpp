namespace example01 {
class Clazz {
    public:
        Clazz() noexcept {}
        Clazz(Clazz const& other) {}
        Clazz(Clazz&& other) noexcept {}
        Clazz& operator=(Clazz const& other) {}
        Clazz& operator=(Clazz&& other) noexcept {}
        virtual ~Clazz() noexcept {}
};

void run() {
    Clazz clazz{};
}
} // namespace example01

namespace example02 {

int theAnswerToAllQuestions{42};

int& function() {
    return theAnswerToAllQuestions;
}

void run() {
    int var{23};
    
    int* pointer{};
    int& reference{var};
    function() = 23;
}
} // namespace example02

#include <iostream>
namespace example03 {
void run() {
    int&& rvalueReference = 25 + 17;
    int* pointerToRvalueReference = &rvalueReference;
    *pointerToRvalueReference = 23;
    std::cout << rvalueReference << std::endl;
}
} // namespace example03

#include <utility>
namespace example04 {

class Clazz {
    public:
        Clazz() = default;

        Clazz(Clazz const& other) {}

        Clazz(Clazz&& other) noexcept {}

        Clazz& operator=(Clazz const& other) { return *this; }

        Clazz& operator=(Clazz&& other) noexcept { return *this; }
};

void run() {
    Clazz anObject{};
    Clazz anotherObject1{ anObject };
    Clazz anotherObject2{ std::move(anObject) };
    anObject = anotherObject1;
    anotherObject2 = std::move(anObject);
}
} // namespace example04

#include <cstddef>
#include <cstring>
namespace example05 {
class MyString {
    public:
        explicit MyString(const std::size_t size) {
            size_ = size + 1;
            data_ = new char[size];
        }

        MyString(const char* const charArray, 
                 const std::size_t size)
        {
            data_ = new char[size];
            size_ = size;
            strcpy(data_, charArray);
        }

        virtual ~MyString() { delete[] data_; }

        MyString(MyString const& other) {
            size_ = other.size_;
            data_ = new char[size_];

            strcpy(data_, other.data_);
        }

        MyString& operator=(MyString const& other) {
            size_ = other.size_;
            data_ = new char[size_];

            strcpy(data_, other.data_);

            return *this;
        }

        MyString(MyString&& other) noexcept {
            size_ = other.size_;
            data_ = other.data_;

            delete[] other.data_;
            other.data_ = nullptr;
            other.size_ = 0;
        }

        MyString& operator=(MyString&& other) noexcept {
            size_ = other.size_;
            data_ = other.data_;

            delete[] other.data_;
            other.data_ = nullptr;
            other.size_ = 0;

            return *this;
        }

    private:
        char* data_;
        std::size_t size_;
};

void run() {
    MyString aString{ "Test", 4 };
    MyString anotherString{ aString };
    MyString yetAnotherString{ aString };
}
} // namespace example05

#include <vector>
#include <cstddef>
namespace example06 {

class MyString {
    public:
        explicit MyString(std::size_t const& size) {
            data_.resize(size, ' ');
        }

        MyString(const char* const charArray, const std::size_t size)
            : MyString(size)
        {
            if (nullptr != charArray)
                for (std::size_t index{0}; index < size; ++index)
                    data_[index] = charArray[index];
        }

    private:
        std::vector<char> data_;
};

void run() {
    MyString aString{ "Test", 4 };
    MyString anotherString{ aString };
    MyString yetAnotherString{ aString };
}
} // namespace example06

int main() {
    example01::run();
    example02::run();
    example03::run();
    example04::run();
    example05::run();
    example06::run();

    return 0;
}
