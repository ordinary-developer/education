#include <cstdlib>

template <class T>
struct OpNewCreator {
    static T* Create() {
        return new T;
    }
};

template <class T>
struct MallocCreator {
    static T* Create() {
        void* buf = std::malloc(sizeof(T));
        if (!buf) return 0;
        return new(buf) T;
    }
};

template <class T>
struct PrototypeCreator {
    PrototypeCreator(T* pObj = 0)
        : pPrototype_(pObj) { }
    
    T* Create() {
        return pPrototype_ ? pPrototype_->Clone() : 0;
    }

    T* GetPrototype() { return pPrototype_; }
    void SetPrototype(T* pObj) { pPrototype_ = pObj; }
private:
    T* pPrototype_;
};

class Widget { };

template <class T>
class WidgetManager1 { };
typedef WidgetManager1<OpNewCreator<Widget>> MyWidgetMgr1;

template <template <class Created> class CreationPolicy>
class WidgetManager2 : public CreationPolicy<Widget> 
{
};
typedef WidgetManager2<OpNewCreator> MyWidgetMgr2;

class Gadget { };
template <template <class> class CreationPolicy>
class WidgetManager : public CreationPolicy<Widget> {
    void DoSomething() {
        Gadget* pW = CreationPolicy<Gadget>().Create();
    }
};

template <template <class> class CreationPolicy = OpNewCreator>
class WidgetManger4 { };

struct RedefinedOpNewCreator {
    template <class T>
    static T* Create() {
        return new T;
    }
};

int main() {
    return 0;
}
