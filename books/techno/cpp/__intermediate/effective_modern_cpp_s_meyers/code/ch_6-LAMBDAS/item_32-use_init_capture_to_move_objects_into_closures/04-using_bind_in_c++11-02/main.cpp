#include <memory>

class Widget {
    public:
        bool isValidated() { return true; }
        bool isArchived() { return true; }
};

void c_plus_plus_14() {
    auto func = [pw = std::make_unique<Widget>()]
                {
                    return pw->isValidated() &&
                           pw->isArchived();
                };
}

void c_plus_plus_11() {
    auto func = 
        std::bind([](const std::unique_ptr<Widget>& pw)
                    {
                        return pw->isValidated() &&
                               pw->isArchived();
                    },
                    std::make_unique<Widget>()
        );
}


int main() {
    c_plus_plus_14();
    c_plus_plus_11();

    return 0;
}
