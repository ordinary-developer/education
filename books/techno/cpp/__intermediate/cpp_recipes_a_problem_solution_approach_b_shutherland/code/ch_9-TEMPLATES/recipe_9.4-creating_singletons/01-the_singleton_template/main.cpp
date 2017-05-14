#include <iostream>
#include <cassert>

template <typename T>
class Singleton {
    public:
        Singleton() {
            assert(nullptr == m_Instance);
            m_Instance = static_cast<T*>(this);
        }
        
        virtual ~Singleton() { m_Instance = nullptr; }
        
        static T& GetSingleton() { return *m_Instance; }
        static T* GetSingletonPtr() { return m_Instance; }
        
    private:
        static T* m_Instance;
};

template <typename T>
T* Singleton<T>::m_Instance = nullptr;

class Manager : public Singleton<Manager> {
    public:
        void Print() const {
            std::cout << "Singleton Manager successfully Printing" << std::endl;
        }
        
};

int main()
{
    new Manager(); 
    Manager& manager(Manager::GetSingleton());
    manager.Print();
    delete Manager::GetSingletonPtr();
    
    return 0;
}
