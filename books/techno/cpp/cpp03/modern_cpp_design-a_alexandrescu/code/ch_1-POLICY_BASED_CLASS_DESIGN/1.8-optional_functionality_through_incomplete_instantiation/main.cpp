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

template <template <class> class CreationPolicy>
class WidgetManager : public CreationPolicy<Widget> 
{
    void SwitchPrototype(Widget* pNewPrototype) {
        CreationPolicy<Widget>& myPolicy = *this;
        delete myPolicy.GetPrototype();
        myPolicy.SetPrototype(pNewPrototype);
    }
};

int main() {
    return 0;
}
