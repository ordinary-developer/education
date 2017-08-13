#include <cstdlib>
#include <iostream>
#include <stack>
#include <thread>
#include <vector>
#include <mutex>


class MyManagedObject {
    private:
        static const unsigned int MAX_OBJECTS{ 8 };

        using MyManagedObjectCollection = std::vector<MyManagedObject>;
        static MyManagedObjectCollection s_ManagedObjects;

        static std::stack<unsigned int> s_FreeList;

        static std::mutex s_Mutex;

        unsigned int m_Value{ 0XFFFFFFFF };

    public:
        MyManagedObject() = default;
        MyManagedObject(unsigned int value) : m_Value{ value } { }

        void* operator new(size_t numBytes) {
            std::lock_guard<std::mutex> lock{ s_Mutex };
            void* objectMemory{};

            if (s_ManagedObjects.capacity() < MAX_OBJECTS)
                s_ManagedObjects.reserve(MAX_OBJECTS);

            if (numBytes == sizeof(MyManagedObject) and
                s_ManagedObjects.size() < s_ManagedObjects.capacity())
            {
                unsigned int index{ 0xFFFFFFFF };
                if (s_FreeList.size() > 0) {
                    index = s_FreeList.top();
                    s_FreeList.pop();
                }
                if (index == 0xFFFFFFFF) {
                    s_ManagedObjects.push_back({});
                    index = s_ManagedObjects.size() - 1;
                }
                objectMemory = s_ManagedObjects.data() + index;
            }
            else
                objectMemory = malloc(numBytes);

            return objectMemory;
        }

        void operator delete(void* pMem) {
            std::lock_guard<std::mutex> lock{ s_Mutex };

            const intptr_t index = {
                (static_cast<MyManagedObject*>(pMem) - s_ManagedObjects.data()) /
                static_cast<intptr_t>(sizeof(MyManagedObject)) };
            if (0 <= index and 
                index < static_cast<intptr_t>(s_ManagedObjects.size()))
            {
                s_FreeList.emplace(static_cast<unsigned int>(index));
            }
            else
                free(pMem);
        }
};

MyManagedObject::MyManagedObjectCollection MyManagedObject::s_ManagedObjects{};
std::stack<unsigned int> MyManagedObject::s_FreeList{};
std::mutex MyManagedObject::s_Mutex{};

void ThreadTask() {
    MyManagedObject* pObject4{ new MyManagedObject{5} };
    std::cout << "pObject4: " << pObject4 << std::endl;

    MyManagedObject* pObject5{ new MyManagedObject{6} };
    std::cout << "pObject5: " << pObject5 << std::endl;

    delete pObject4;
    pObject4 = nullptr;

    MyManagedObject* pObject6{ new MyManagedObject{7} };
    std::cout << "pObject6: " << pObject6 << std::endl;

    pObject4 = new MyManagedObject{7};
    std::cout << "pObject4: " << pObject4 << std::endl;

    delete pObject5;
    pObject5 = nullptr;

    delete pObject6;
    pObject6 = nullptr;

    delete pObject4;
    pObject4 = nullptr;
}

int main() {
    std::cout << std::hex << std::showbase;

    std::thread myThread{ ThreadTask };

    MyManagedObject* pObject1{ new MyManagedObject{1} };
    std::cout << "pObject1: " << pObject1 << std::endl;

    MyManagedObject* pObject2{ new MyManagedObject{2} };
    std::cout << "pObject2: " << pObject2 << std::endl;

    delete pObject1;
    pObject1 = nullptr;

    MyManagedObject* pObject3{ new MyManagedObject{3} };
    std::cout << "pObject3: " << pObject3 << std::endl;

    pObject1 = new MyManagedObject{4};
    std::cout << "pObject1: " << pObject1 << std::endl;


    delete pObject2;
    pObject2 = nullptr;

    delete pObject3;
    pObject3 = nullptr;

    delete pObject1;
    pObject1 = nullptr;

    myThread.join();

    return 0;
}
