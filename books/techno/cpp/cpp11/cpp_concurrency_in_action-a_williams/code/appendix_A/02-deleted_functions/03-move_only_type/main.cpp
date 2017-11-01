#include <memory>

class my_class { };

class move_only {
    private:
        std::unique_ptr<my_class> data;
    public:
        move_only() = default;
        move_only(const move_only&) = delete;
        move_only(move_only&& other) 
            : data(std::move(other.data)) { }
        move_only& operator = (const move_only&) = delete;
        move_only& operator = (move_only&& other) 
        {
            data = std::move(other.data);
            return *this;
        }
};

int main() {
    move_only m1;
    move_only m3(std::move(m1));

    return 0;
}
