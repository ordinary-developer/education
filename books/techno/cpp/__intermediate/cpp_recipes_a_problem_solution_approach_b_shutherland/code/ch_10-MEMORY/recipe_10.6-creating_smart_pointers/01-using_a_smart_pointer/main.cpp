class ReferenceCount {
    public:
        void Increment() { ++m_Count; }
        int Decrement() { return --m_Count; }
        int GetCount() const { return m_Count; }

    private:
        int m_Count{ 0 };
};

#include <iostream>
template <typename T>
class SmartPointer {
    public:
        SmartPointer() { }
        SmartPointer(T* object) 
            : m_Object{ object },
              m_ReferenceCount{ new ReferenceCount }
        {
            m_ReferenceCount->Increment();
            std::cout << "Created smart pointer! Reference count is "
                      << m_ReferenceCount->GetCount() << std::endl;
        }

        virtual ~SmartPointer() {
            if (m_ReferenceCount) {
                int decrementCount = m_ReferenceCount->Decrement();
                std::cout << "Destroyed smart Pointer! Reference count is "
                          << decrementCount << std::endl;
                if (decrementCount <= 0) {
                    delete m_ReferenceCount;
                    delete m_Object;
                }
                m_ReferenceCount = nullptr;
                m_Object = nullptr;
            }
        }

        SmartPointer(const SmartPointer<T>& other) 
            : m_Object{ other.m_Object },
              m_ReferenceCount{ other.m_ReferenceCount } 
        {
            m_ReferenceCount->Increment();

            std::cout << "Copied smart ointer! Reference count is "
                      << m_ReferenceCount->GetCount() << std::endl;
        }

        SmartPointer<T>& operator=(const SmartPointer<T>& other) {
            if (this != &other) {
                if (m_ReferenceCount && m_ReferenceCount->Decrement() == 0) {
                    delete m_ReferenceCount;
                    delete m_Object;
                }

                m_Object = other.m_Object;
                m_ReferenceCount = other.m_ReferenceCount;
                m_ReferenceCount->Increment();
            }

            std::cout << "Assigning smart pointer! Reference count is "
                      << m_ReferenceCount->GetCount() << std::endl;

            return *this;
        }

        SmartPointer(SmartPointer<T>&& other) 
            : m_Object{ other.m_Object },
              m_ReferenceCount{ other.m_ReferenceCount }
        {
            other.m_Object = nullptr;
            other.m_ReferenceCount = nullptr;
        }

        SmartPointer<T>& operator=(SmartPointer<T>&& other) {
            if (this != &other) {
                m_Object = other.m_Object;
                m_ReferenceCount = other.m_ReferenceCount;

                other.m_Object = nullptr;
                other.m_ReferenceCount = nullptr;
            }
        }

        T& operator*() {
            return *m_Object;
        }
    private:
        T* m_Object{ nullptr };
        ReferenceCount* m_ReferenceCount{ nullptr };
};

struct MyStruct {
    public: 
        int m_Value{ 0 };

        ~MyStruct() {
            std::cout << "Destroying MyStruct object!" << std::endl;
        }
};

using SmartMyStructPointer = SmartPointer<MyStruct>;

SmartMyStructPointer PassValue(SmartMyStructPointer smartPointer) {
    SmartMyStructPointer returnValue;
    returnValue = smartPointer;
    return returnValue;
}

int main() {
    SmartMyStructPointer smartPointer{ new MyStruct };
    (*smartPointer).m_Value = 10;

    SmartMyStructPointer secondSmartPointer = PassValue(smartPointer);

    return 0;
}

