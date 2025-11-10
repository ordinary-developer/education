#include <iostream>
#include <memory>
namespace example_01 { // the "how to do it" section

void func(int) = delete;

template <typename T>
void run(T val) = delete;

void run(long val) {}

void run() {
    {
        struct foo {
            foo() = default;
        };
    }
    
    {
        struct foo {
            foo(foo const &) = delete;
        };
    }
    
    {
        class foo_not_copyable {
        public:
            foo_not_copyable() = default;
            
            foo_not_copyable(foo_not_copyable const &) = delete;
            foo_not_copyable& operator=(foo_not_copyable const&) = delete;
        };
    }
    
    {
        struct Data{};
        
        class data_wrapper {
            Data* data;
        public:
            data_wrapper(Data* d = nullptr) : data(d) {}
            ~data_wrapper() { delete data; }
            
            data_wrapper(data_wrapper const&) = delete;
            data_wrapper& operator=(data_wrapper const&) = delete;
            
            data_wrapper(data_wrapper&& other) : data(std::move(other.data)) { other.data = nullptr; }
            data_wrapper& operator=(data_wrapper&& other) {
                if (this != std::addressof(other)) {
                    delete data;
                    data = std::move(other.data);
                    other.data = nullptr;
                }
                return *this;
            }
        };
    }
    
    {
        run(42L);
    }
    
}
}  // example_01


#include <iostream>
namespace example_02 { // the "how it works" section

class foo {
public:
    foo() = default;
    inline foo& operator=(foo const &);
};

inline foo& foo::operator=(foo const &) = default;

void run() {
    
}
    
} // example_02

#include <iostream>
int main() {
    std::cout << "example_01 => [ok]"; example_01::run(); std::cout << std::endl << std::endl;
    std::cout << "example_02 => [ok]"; example_02::run(); std::cout << std::endl << std::endl;
	return 0;
}