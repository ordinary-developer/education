#include <thread>
#include <mutex>
namespace workspace {
    
class Foo {
    public:
        Foo(int const d = 0) : data_{d} {}
    
        void update(int const d) {
            std::lock_guard<std::mutex> lock{ mut_ };
            internal_update(d);
        }
    
        int update_with_ret(int const d) {
            std::lock_guard<std::mutex> lock{ mut_ };
            int const tmp{ data_ };
            internal_update(d);
            return tmp;
        }
    
    private:
        void internal_update(int const d) { data_ = d; }
    
        std::mutex mut_;
        int data_;
};
    
void run() {
    Foo foo{};
    std::thread t1{ &Foo::update, &foo, 5 }, t2{ &Foo::update, &foo, 10 };
    t1.join(); t2.join();
}    
    
} // workspace


int main() {
    workspace::run();
    
    return 0;
}
