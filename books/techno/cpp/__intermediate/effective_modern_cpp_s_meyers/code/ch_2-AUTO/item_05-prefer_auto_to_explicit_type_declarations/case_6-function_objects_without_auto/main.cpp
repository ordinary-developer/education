#include <iostream>
#include <memory>

class Widget {
    public:
        // a stub operatro
        bool operator < (const Widget& anotherWidget)
        {
            return true;
        }
};

int main() {
    // simple function object declaration
    std::function<bool(const std::unique_ptr<Widget>&,
                       const std::unique_ptr<Widget>&)> func;

    // labmdas without autos
    std::function<bool(const std::unique_ptr<Widget>&,  
                       const std::unique_ptr<Widget>&)> 
    derefUPLess = [] (const std::unique_ptr<Widget>& p1,
                      const std::unique_ptr<Widget>& p2)
    {
        return *p1 < *p2;
    };
}


