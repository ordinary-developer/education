#include <iostream>
#include <algorithm>
#include <cstddef>

class Clazz final {
    public:
        Clazz(std::size_t const size)
            : resourceToManage_{ new char[size] }, size_{ size } { }
    
        ~Clazz() {
            delete[] resourceToManage_;
            resourceToManage_ = nullptr;
        }
    
        Clazz(Clazz const& other) : Clazz{ other.size_ } {
            std::copy(other.resourceToManage_, 
                      other.resourceToManage_ + other.size_,
                      resourceToManage_);
        }
    
        Clazz(Clazz&& other) noexcept {
            swap(other);
        }
    
        Clazz& operator=(Clazz other) {
            swap(other);
            return *this;
        }
    
    private:
        void swap(Clazz& other) noexcept {
            std::swap(resourceToManage_, other.resourceToManage_);
            std::swap(size_, other.size_);
        }
        
        char* resourceToManage_;
        std::size_t size_;
};

int main() {
    Clazz instance1{ 1000 };
    Clazz instance2{ instance1 };
    
    std::cout << "[OK] - all done" << std::endl;
    
    return 0;
}