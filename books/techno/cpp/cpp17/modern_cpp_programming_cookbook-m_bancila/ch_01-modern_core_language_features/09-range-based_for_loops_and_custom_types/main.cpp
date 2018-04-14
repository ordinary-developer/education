// region [getting ready]
#include <cstddef>
#include <stdexcept>
namespace example_01 {
    
template <typename T, std::size_t const Size>
class dummy_array {
public:
    T const & GetAt(std::size_t const index) const {
        if (index < Size)
            return data_[index];
            
        throw std::out_of_range("index out of range");
    }
    
    void SetAt(std::size_t const index, T const & value) {
        if (index < Size)
            data_[index] = value;
        else
            throw std::out_of_range("index out of range");
    }
    
    std::size_t GetSize() const { return Size; }
    
private:
    T data_[Size] = {};
};

void run() {
    dummy_array<int, 3> arr{};
    arr.SetAt(0, 1);
    arr.SetAt(1, 2);
    arr.SetAt(2, 3);
}    
    
} // example_01
// endregion [getting ready]

#include <cstddef>
#include <stdexcept>
#include <iostream>
namespace example_02 {
    
template <typename T, std::size_t const Size>
class dummy_array {
public:
    T const & GetAt(std::size_t const index) const {
        if (index < Size)
            return data_[index];
            
        throw std::out_of_range("index out of range");
    }
    
    void SetAt(std::size_t const index, T const & value) {
        if (index < Size)
            data_[index] = value;
        else
            throw std::out_of_range("index out of range");
    }
    
    std::size_t GetSize() const { return Size; }
    
private:
    T data_[Size] = {};
};
    
template <typename T, typename C, std::size_t const Size>
class dummy_array_iterator_type {
public:
    dummy_array_iterator_type(C& collection,
                              std::size_t const index)
        : index_{ index }, collection_{ collection } {}
    
    bool operator != (dummy_array_iterator_type const& other) const {
        return index_ != other.index_;
    }
    
    T const& operator * () const {
        return collection_.GetAt(index_);
    }
    
    dummy_array_iterator_type const& operator ++ () {
        ++index_;
        return *this;
    }
    
   
private:
    std::size_t index_;
    C& collection_; 
};
    
template <typename T, std::size_t const Size>
using dummy_array_iterator =
    dummy_array_iterator_type<T, dummy_array<T, Size>, Size>;
    
template <typename T, std::size_t const Size>
using dummy_array_const_iterator = 
    dummy_array_iterator_type<T, dummy_array<T, Size> const, Size>;
    
template <typename T, std::size_t const Size>
inline dummy_array_iterator<T, Size> begin(
    dummy_array<T, Size>& collection)
{
    return dummy_array_iterator<T, Size>(collection, 0);
}
    
template <typename T, std::size_t const Size>
inline dummy_array_iterator<T, Size> end(
    dummy_array<T, Size>& collection)
{
    return dummy_array_iterator<T, Size>(
        collection, collection.GetSize());
}
    
template <typename T, std::size_t const Size>
inline dummy_array_const_iterator<T, Size> begin(
    dummy_array<T, Size> const& collection)
{
    return dummy_array_const_iterator<T, Size>(collection, 0);
}
    
template <typename T, std::size_t const Size>
inline dummy_array_const_iterator<T, Size> end(
    dummy_array<T, Size> const& collection)
{
    return dummy_array_const_iterator<T, Size>(
        collection, collection.GetSize());
}
    
template <typename T, std::size_t const Size>
void print_dummy_array(dummy_array<T, Size> const & arr) {
    for (auto&& e : arr)
        std::cout << e << std::endl;
}
    
void run() {
    dummy_array<int, 3> arr{};
    arr.SetAt(0, 1);
    arr.SetAt(1, 2);
    arr.SetAt(2, 3);
    
    for (auto&& e : arr)
        std::cout << e << std::endl;
    
    print_dummy_array(arr);
}    
} // example_02

#include <iostream>
int main() {
    example_01::run();
    example_02::run();
    
    std::cout << "DONE" << std::endl;
    
    return 0;
}