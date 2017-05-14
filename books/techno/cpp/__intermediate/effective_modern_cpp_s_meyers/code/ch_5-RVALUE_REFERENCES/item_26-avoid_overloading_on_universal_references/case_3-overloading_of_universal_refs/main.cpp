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

        // overloading of a function
        void logAndAdd(int idx) {
            auto now = std::chrono::system_clock::now();
            log();
            names.emplace(nameFromIdx(idx));
        }

    private:
        // a dump logging function
        void log() {
            // std:: cout << "logAndAdd" << std::endl;
        }

        // a dump function
        std::string nameFromIdx(int idx) {
            return std::string("exemli gratia");
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

    // calls int overload
    logger.logAndAdd(22);

    // an error
    // short nameIdx = 0;
    // logger.logAndAdd(nameIdx);

    return 0;
}

