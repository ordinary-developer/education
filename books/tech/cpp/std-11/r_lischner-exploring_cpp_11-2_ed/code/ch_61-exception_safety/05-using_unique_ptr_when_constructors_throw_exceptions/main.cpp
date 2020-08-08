#include <iostream>
#include <memory>


class see_me {
    public:
        see_me(int x) : x_{x} { std::cout << "see_me(" << x_ << ")\n"; }
        ~see_me() { std::cout << "~see_me(" << x_ << ")\n"; }
        
    private:
        int x_;
};

class bomb : public see_me {
    public:
        bomb() : see_me{1}, a_{ new see_me{2} } { throw 0; }
        ~bomb() = default;

    private:
        std::unique_ptr<see_me> a_;
};


int main() {
    bomb* b{nullptr};
    try {
        b = new bomb{};
    }
    catch (int) {
        if (nullptr == b)
            std::cout << "b is null\n";
    }

    return 0;
}
