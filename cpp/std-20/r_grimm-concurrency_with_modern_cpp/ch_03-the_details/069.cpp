#include <mutex>

std::mutex gMut;

class MySingleton {
public:
    static MySingleton & getInstance() {
        std::lock_guard<std::mutex> _{gMut};
        if (not instance)
            instance = new MySingleton();
        return *instance;
    }

private:
    MySingleton() = default;
    ~MySingleton() = default;
    MySingleton(const MySingleton &) = delete;
    MySingleton & operator = (const MySingleton &) = delete;

    static MySingleton * instance;
};

MySingleton * MySingleton::instance = nullptr;


int main() {
    
}
