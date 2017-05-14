#include <memory>

class Widget { 
    public:
        // a stub operator
        bool operator < (const Widget& otherWidget) 
        {
            return true;
        }
};

int main() {
    auto derefUPLess = []
        (const std::unique_ptr<Widget>& p1,
         const std::unique_ptr<Widget>& p2)
    {
        return *p1 < *p2;
    };

    auto derefLess = 
        [] (const auto& p1, const auto& p2)
        {
            return *p1 < *p2;
        };
}
