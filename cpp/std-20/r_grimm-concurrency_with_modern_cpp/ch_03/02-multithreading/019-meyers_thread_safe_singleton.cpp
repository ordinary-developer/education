#include <iostream>

class MySingleton {
    public:
        static MySingleton & getInstance() {
            static MySingleton instance;
            return instance;
        }

    private:
        MySingleton();
        ~MySingleton();
        MySingleton(const MySingleton &) = delete;
        MySingleton & operator = (const MySingleton &) = delete;
};

MySingleton::MySingleton() = default;
MySingleton::~MySingleton() = default;


int main() {
    std::cout << std::endl;
    MySingleton::getInstance();
    std::cout << std::endl;
}
