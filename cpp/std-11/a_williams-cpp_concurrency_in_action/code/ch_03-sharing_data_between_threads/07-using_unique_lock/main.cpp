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
            std::unique_lock<std::mutex> lock_a(lhs.m,  
                                                std::defer_lock);
            std::unique_lock<std::mutex> lock_b(rhs.m,
                                                std::defer_lock);
            std::lock(lock_a, lock_b);
            swap(lhs.some_detail, rhs.some_detail);
        }
    private:
        some_big_object some_detail;
        mutable std::mutex m;
};

int main() {
    return 0;
}

