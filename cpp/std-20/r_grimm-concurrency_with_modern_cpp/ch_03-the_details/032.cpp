#include <iostream>
#include <mutex>


class MySingleton {
private:
    static std::once_flag initInstanceFlag_;
    static MySingleton * instance_;

    MySingleton() = default;
    ~MySingleton() = default;

public:
    MySingleton(const MySingleton &) = delete;
    MySingleton & operator = (const MySingleton &) = delete;

    static MySingleton * getInstance() {
        std::call_once(initInstanceFlag_, MySingleton::initSingleton);
        return instance_;
    } 

    static void initSingleton() {
        instance_ = new MySingleton();
    }
};

MySingleton * MySingleton::instance_ = nullptr;
std::once_flag MySingleton::initInstanceFlag_;

int main() {
    std::cout << std::endl;

    std::cout << "MySingleton::getInstance(): " << MySingleton::getInstance() << std::endl;
    std::cout << "MySingleton::getInstance(): " << MySingleton::getInstance() << std::endl;

    std::cout << std::endl;
}
