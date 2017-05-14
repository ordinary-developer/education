#include <memory>

class Widget {
    public:
        bool isValidated() const { return true; }
        bool isArchived() const { return true; }
};

class IsValAndArch {
    public:
        using DataType = std::unique_ptr<Widget>;

        explicit IsValAndArch(DataType&& ptr) 
            : pw(std::move(ptr)) { }

        bool operator() () const {
            return pw->isValidated() && pw->isArchived();
        }
    private:
        DataType pw;
};


int main() {
    auto func = IsValAndArch(std::make_unique<Widget>());

    return 0;
}
