#include <mutex>
#include <thread>
namespace example_01 {
    
class foo {
    public:
        foo(int const d = 0) : data_{ d } { }
    
        void update(int const d) {
            std::lock_guard<std::mutex> lock{ m_ };
            internal_update(d);
        }
    
        int update_with_return(int const d) {
            std::lock_guard<std::mutex> lock{ m_ };
            int tmp{ data_ };
            internal_update(d);
            return tmp;
        }
    
    private:
        void internal_update(int const d) { data_ = d; }
    
        std::mutex m_;
        int data_;
};
    
void run() {
    foo f{};
    std::thread t1{ &foo::update, &f, 5 }, t2{ &foo::update, &f, 10 };
    t1.join(); t2.join();
}    

} // example_01

int main() {
    example_01::run();
    
    return 0;
}
