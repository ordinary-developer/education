#include <mutex>

class some_big_object { };

void swap(some_big_object& lhs, some_big_object& rhs) { }

class X {
    public:
        X(const some_big_object& sd) : some_detail(sd) { }

        friend void swap(X& lhs, X& rhs) {
            if (&lhs == &rhs) {
                return;
            }
            std::lock(lhs.m, rhs.m);
            std::lock_guard<std::mutex> lock_a(lhs.m, 
                                               std::adopt_lock);
            std::lock_guard<std::mutex> lock_b(rhs.m, 
                                               std::adopt_lock);
            swap(lhs.some_detail, rhs.some_detail);
        }
    private:
        some_big_object some_detail;
        mutable std::mutex m;
};

int main() { 
    return 0;
}
