#include <iostream>

#include <concepts>
#include <memory>
#include <utility>
#include <stdexcept>
#include <string>


// declaration
template <typename T> requires std::default_initializable<T>
    && std::destructible<T>
class Array {
public:
    Array();
    explicit Array(std::size_t size);
    ~Array();

    // copy/move ctor/assign
    Array(const Array & array) requires std::copyable<T>;
    Array & operator = (const Array & rhs) requires std::copyable<T>;
    Array(Array && array) noexcept requires std::movable<T>;
    Array& operator = (Array&& rhs) noexcept requires std::movable<T>;

    // operators
    T & operator[](std::size_t index);
    const T & operator[](std::size_t index) const;

    void swap(Array & other) noexcept;
    void push_back(T element) requires std::movable<T>;
    std::size_t getSize() const { return m_size; }

private:
    T* m_elements;
    std::size_t m_size;
};


// ctor/dtor
template <typename T> requires std::default_initializable<T>
    && std::destructible<T>
Array<T>::Array()
    : Array{0}
{}

template <typename T> requires std::default_initializable<T>
    && std::destructible<T>
Array<T>::Array(std::size_t size)
    : m_elements{ new T[size]{} }, m_size{ size }
{}

template <typename T> requires std::default_initializable<T>
    && std::destructible<T>
Array<T>::~Array() { delete[] m_elements; }


// copy/move ctor/assign
template <typename T> requires std::default_initializable<T>
    && std::destructible<T>
Array<T>::Array(const Array & array) requires std::copyable<T>
    : Array{array.m_size}
{
    for (std::size_t i{}; i < m_size; ++i)
        m_elements[i] = array.m_elements[i];
}

template <typename T> requires std::default_initializable<T>
    && std::destructible<T>
Array<T> & Array<T>::operator = (const Array & rhs) requires std::copyable<T>
{
    Array<T> copy{ rhs };
    swap(copy);
    return *this;
}

template <typename T> requires std::default_initializable<T>
    && std::destructible<T>
Array<T>::Array(Array && moved) noexcept requires std::movable<T>
    : m_size{moved.m_size}, m_elements{moved.m_elements}
{
    moved.m_elements = nullptr;
}

template <typename T> requires std::default_initializable<T>
    && std::destructible<T>
Array<T> & Array<T>::operator = (Array && rhs) noexcept requires std::movable<T>
{
    if (&rhs != this) {
        delete [] m_elements;
        m_elements = rhs.m_elements;
        m_size = rhs.m_size;
        rhs.m_elements = nullptr;
    }
    return *this;
}


// operators
template <typename T> requires std::default_initializable<T>
    && std::destructible<T>
T & Array<T>::operator [] (std::size_t index)
{
    return const_cast<T&>(std::as_const(*this)[index]);
}

template <typename T> requires std::default_initializable<T>
    && std::destructible<T>
const T & Array<T>::operator[](std::size_t index) const
{
    if (index >= m_size)
        throw std::out_of_range{ "Index too large: " + std::to_string(index)};
    return m_elements[index];
}


// public
template <typename T> requires std::default_initializable<T>
    && std::destructible<T>
void Array<T>::swap(Array & other) noexcept
{
    std::swap(m_elements, other.m_elements);
    std::swap(m_size, other.m_size);
}

template <typename T> requires std::default_initializable<T>
    && std::destructible<T>
void swap(Array<T> & one, Array<T> & other) noexcept
{
    one.swap(other);
}

template <typename T> requires std::default_initializable<T>
    && std::destructible<T>
void Array<T>::push_back(T element) requires std::movable<T>
{
    Array<T> newArray{ m_size + 1 };
    for (std::size_t i{}; i < m_size; ++i)
        newArray[i] = std::move(m_elements[i]);

    newArray[m_size] = std::move(element);

    swap(newArray);
}


static_assert(requires {typename Array<std::unique_ptr<int>>; });

int main() {
    Array<int> vals;

    Array<std::unique_ptr<int>> tenSmartPointers(10);
    Array<std::unique_ptr<int>> target;
    //target = tenSmartPointers; /* Constraint not satisfied: copyable<unique_ptr> */
    target = std::move(tenSmartPointers);
    target.push_back(std::make_unique<int>(123));
}
