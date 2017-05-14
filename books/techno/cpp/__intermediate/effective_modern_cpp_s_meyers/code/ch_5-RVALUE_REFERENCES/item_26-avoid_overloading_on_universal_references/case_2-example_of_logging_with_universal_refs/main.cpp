#include <chrono>
#include <set>
#include <string>


class Logger {
    public:
        template <typename T>
        void logAndAdd(T&& name) {
            auto now = std::chrono::system_clock::now();
            log();
            names.emplace(std::forward<T>(name));
        }

    private:
        // a dump logging function
        void log() {
            // std:: cout << "logAndAdd" << std::endl;
        }
        std::multiset<std::string> names;
};


int main() {
    Logger logger;

    // copy lvalue into multiset
    std::string petName("Darla");
    logger.logAndAdd(petName);

    // move rvalue instead of copying it
    logger.logAndAdd(std::string("Persephone"));

    // create std::string in multiset 
    // instead of copying a temporary std::string
    logger.logAndAdd("Patty Dog");

    return 0;
}

