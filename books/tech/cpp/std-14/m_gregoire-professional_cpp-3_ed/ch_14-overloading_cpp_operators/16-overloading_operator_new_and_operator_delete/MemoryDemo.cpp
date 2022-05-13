#include "MemoryDemo.hpp"

#include <iostream>

void* MemoryDemo::operator new (size_t size) {
    std::cout << "operator new" << std::endl;
    return ::operator new(size);
}

void MemoryDemo::operator delete (void* ptr) noexcept {
    std::cout << "operator delete" << std::endl;
    ::operator delete(ptr);
}

void MemoryDemo::operator delete (void* ptr, size_t size) noexcept {
    std::cout << "operator delete with size" << std::endl;
    ::operator delete(ptr);
}

void* MemoryDemo::operator new[] (size_t size) {
    std::cout << "operator new[]" << std::endl;
    return ::operator new[](size);
}

void MemoryDemo::operator delete[] (void* ptr) noexcept {
    std::cout << "operator delete[] " << std::endl;
    ::operator delete[](ptr);
}

void* MemoryDemo::operator new (size_t size, const std::nothrow_t&) noexcept {
    std::cout << "operator new nothrow" << std::endl;
    return ::operator new(size, std::nothrow);
}

void MemoryDemo::operator delete (void* ptr, const std::nothrow_t&) noexcept {
    std::cout << "operator delete nothrow" << std::endl;
    ::operator delete(ptr, std::nothrow);
}

void* MemoryDemo::operator new[] (size_t size, const std::nothrow_t&) noexcept {
    std::cout << "operator new[] nothrow" << std::endl;
    return ::operator new[] (size, std::nothrow);
}

void MemoryDemo::operator delete[] (void* ptr, const std::nothrow_t&) noexcept {
    std::cout << "operator delete[] nothrow" << std::endl;
    ::operator delete[] (ptr, std::nothrow);
}

void* MemoryDemo::operator new (size_t size, int extra) {
    std::cout << "operator new withe extra int arg: " << extra << std::endl;
    return ::operator new(size);
}

void MemoryDemo::operator delete(void* ptr, int extra) noexcept {
    std::cout << "operator delete with extra int arg: " << extra << std::endl;
    return ::operator delete(ptr);
}
