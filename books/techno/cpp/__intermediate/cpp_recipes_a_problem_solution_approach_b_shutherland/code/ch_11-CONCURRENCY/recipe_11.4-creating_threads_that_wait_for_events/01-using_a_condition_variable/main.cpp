#include <cstdlib>
#include <iostream>
#include <functional>
#include <stack>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>


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

        unsigned int GetValue() const { return m_Value; }

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

using ProducerQueue = std::vector<unsigned int>;

void ThreadTask(std::reference_wrapper<std::condition_variable> condition,
                std::reference_wrapper<std::mutex> queueMutex,
                std::reference_wrapper<ProducerQueue> queueRef,
                std::reference_wrapper<bool> die)
{
    ProducerQueue& queue{ queueRef.get() };

    while (not die.get() or queue.size()) {
        std::unique_lock<std::mutex> lock{ queueMutex.get() };

        std::function<bool()> predicate {
            [&queue]() { return not queue.empty(); }
        };

        condition.get().wait(lock, predicate);

        unsigned int numberToCreate{ queue.back() };
        queue.pop_back();

        std::cout << "Creating " << numberToCreate << " objects on thread "
                  << std::this_thread::get_id() << std::endl;

        for (unsigned int i{0}; i < numberToCreate; ++i)
        {
            MyManagedObject* pObject{ new MyManagedObject{i} };
            delete pObject;
            pObject = nullptr;
        }
    }
}

using namespace std::literals;

int main() {
    std::condition_variable condition{};
    std::mutex queueMutex{};
    ProducerQueue queue{};
    bool die{ false };

    std::thread myThread1{ ThreadTask, 
                           std::ref(condition), 
                           std::ref(queueMutex),
                           std::ref(queue),
                           std::ref(die) };

    std::thread myThread2{ ThreadTask, 
                           std::ref(condition), 
                           std::ref(queueMutex),
                           std::ref(queue),
                           std::ref(die) };

    queueMutex.lock();
    queue.emplace_back(300000);
    queue.emplace_back(400000);
    queueMutex.unlock();

    condition.notify_all();

    std::this_thread::sleep_for(10ms);
    while (not queueMutex.try_lock()) {
        std::cout << "Main waiting for queue access!" << std::endl;
        std::this_thread::sleep_for(100ms);
    }

    queue.emplace_back(100000);
    queue.emplace_back(200000);

    std::this_thread::sleep_for(1000ms);
    condition.notify_one();

    std::this_thread::sleep_for(1000ms);
    condition.notify_one();

    std::this_thread::sleep_for(1000ms);
    queueMutex.unlock();

    die = true;

    std::cout << "main waiting for join!" << std::endl;

    myThread1.join();
    myThread2.join();

    return 0;
}
