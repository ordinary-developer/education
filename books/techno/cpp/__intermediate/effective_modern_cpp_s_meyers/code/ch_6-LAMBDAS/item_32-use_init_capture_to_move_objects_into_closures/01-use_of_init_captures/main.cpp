#include <memory>

class Widget {
    public:
        bool isValidated() const { return true; }
        bool isProcessed() const { return true; }
        bool isArchived() const { return true; }

};


int main() {
    auto pw = std::make_unique<Widget>();

    auto func1 = [pw = std::move(pw)]
                { 
                    return pw->isValidated() &&
                         pw->isArchived();
                };

    auto func2 = [pw = std::make_unique<Widget>()]
                 {
                     return pw->isValidated() &&
                            pw->isArchived();
                 };

    return 0;
}
