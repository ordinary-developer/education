#include <exception> 

template 
<
    class T,
    template <class> class CheckingPolicy
>
class SmartPtr; 

template 
<
    class T,
    template <class> class CheckingPolicy
>
class SmartPtr : public CheckingPolicy<T>
{
public:
    SmartPtr() { pointee_ = nullptr; }

    template 
    <
        class T1, 
        template <class> class CP1
    >
    SmartPtr(const SmartPtr<T1, CP1>& other)
      //: pointee_(other.pointee_), 
      : pointee_(
          (reinterpret_cast<const SmartPtr<T, CP1>&>(other)).pointee_),
        CheckingPolicy<T>(
          reinterpret_cast<const CheckingPolicy<T>&>(other))
    { }

private:
    T* pointee_;
};


class Widget { };
class ExtendedWidget : public Widget { };

template <class T> struct NoChecking 
{
    static void Check(T*) { }
};
template <class T> struct EnforceNotNull 
{
    class NullPointerException : public std::exception { };
    static void Check(T* ptr) { 
        if (!ptr)
            throw NullPointerException();
    }

};

int main() {
    SmartPtr<ExtendedWidget, NoChecking> a1;
    SmartPtr<Widget, NoChecking> a2(a1);

    return 0;
}
