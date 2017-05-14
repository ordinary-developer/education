#include <iostream>

class generate_id {
    public:
        generate_id() : counter_{ 0 } { }
        long next();
    private:
        short counter_;
        static short prefix_;
        static short const max_counter_ = 32767;
};


int main() {
    generate_id gen{};
    for (int i{ 0 }; i != 10; ++i)
        std::cout << gen.next() << '\n';

    return 0;
}

