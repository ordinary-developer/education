#include <exception> 

template 
<
    class T,
    template <class> class CheckingPolicy,
    template <class> class ThreadingModel
>
class SmartPtr; 


template 
<
    class T,
    template <class> class CheckingPolicy,
    template <class> class ThreadingModel
>
class SmartPtr : public CheckingPolicy<T>, 
                 public ThreadingModel<SmartPtr<T, 
                                                CheckingPolicy,
                                                ThreadingModel>>
{
    T* operator->()
    {
        typename ThreadingModel<SmartPtr>::Lock guard(*this);
        CheckingPolicy<T>::Check(pointee_);
        return pointee_;
    }
private:
    T* pointee_;
};


class Widget { };

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

template <class T> struct SingleThreaded
{
    struct Lock
    {
        Lock(T&) { }
    };
};

typedef SmartPtr<Widget, NoChecking, SingleThreaded> WidgetPtr;
typedef SmartPtr<Widget, EnforceNotNull, SingleThreaded> SafeWidgetPtr;

int main() {
    return 0;
}
