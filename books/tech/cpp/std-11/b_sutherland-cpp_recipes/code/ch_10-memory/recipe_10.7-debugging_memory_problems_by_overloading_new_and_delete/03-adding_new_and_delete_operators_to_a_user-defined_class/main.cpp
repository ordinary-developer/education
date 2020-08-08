#include <cstdlib>
#include <iostream>

struct MemoryHeader {
    const char* m_Filename{ nullptr };
    int m_Line{ -1 };
};

void* operator new(size_t size, const char* filename, int line) noexcept {
    void* pMemory { malloc(size + sizeof(MemoryHeader)) };

    MemoryHeader* pMemoryHeader{ reinterpret_cast<MemoryHeader*>(pMemory) };
    pMemoryHeader->m_Filename = filename;
    pMemoryHeader->m_Line = line;

    return static_cast<void*>(static_cast<char*>(pMemory) + sizeof(MemoryHeader));
}

void* operator new[](size_t size, const char* filename, int line) noexcept {
    void* pMemory { malloc(size + sizeof(MemoryHeader)) };

    MemoryHeader* pMemoryHeader{ reinterpret_cast<MemoryHeader*>(pMemory) };
    pMemoryHeader->m_Filename = filename;
    pMemoryHeader->m_Line = line;

    return static_cast<void*>(static_cast<char*>(pMemory) + sizeof(MemoryHeader));
}

void operator delete(void* pMemory) noexcept {
    char* pMemoryHeaderStart{ 
        reinterpret_cast<char*>(pMemory) - sizeof(MemoryHeader) };

    MemoryHeader* pMemoryHeader{ 
        reinterpret_cast<MemoryHeader*>(pMemoryHeaderStart) };

    std::cout << "Deleting memory allocated from: "
              << pMemoryHeader->m_Filename << ":" << pMemoryHeader->m_Line
              << std::endl;

    free(pMemoryHeader);
}

void operator delete[](void* pMemory) noexcept {
    char* pMemoryHeaderStart{ 
        reinterpret_cast<char*>(pMemory) - sizeof(MemoryHeader) };

    MemoryHeader* pMemoryHeader{ 
        reinterpret_cast<MemoryHeader*>(pMemoryHeaderStart) };

    std::cout << "Deleting memory allocated from: "
              << pMemoryHeader->m_Filename << ":" << pMemoryHeader->m_Line
              << std::endl;

    free(pMemoryHeader);
}


class MyClass {
    public:
        void* operator new(size_t size, const char* filename, int line) noexcept {
            std::cout << "Allocating memory for MyClass!" << std::endl;
            return malloc(size);
        }

        void operator delete(void* pMemory) noexcept {
            std::cout << "Freeing memory for MyClass" << std::endl;
            free(pMemory);
        }

    private:
        int m_Value{ 1 };
};

#define new new(__FILE__, __LINE__)

int main() {
    int* pInt{ new int };
    *pInt = 1;
    delete pInt;

    MyClass* pClass{ new MyClass };
    delete pClass;

    const unsigned int NUM_ELEMENTS{ 5 };
    int* pArray{ new int[NUM_ELEMENTS] };
    delete[] pArray;

    return 0;
}
