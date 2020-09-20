#include <cstdlib>

template <class T>
struct OpNewCreator {
    static T* Create() {
        return new T;
    }
protected:
    ~OpNewCreator() { }
};

class Widget { };

template <template <class> class CreationPolicy = OpNewCreator>
class WidgetManager : public CreationPolicy<Widget>
{
};

template <class T, template <class> class CreationPolicy>
class TManager : public CreationPolicy<T>
{
    public:
        TManager() : _p(CreationPolicy<T>::Create()) { }
    private:
        T* _p;
};

int main() {
    TManager<Widget, OpNewCreator> manager; 
    return 0;
}
