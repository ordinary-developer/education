#include <chrono>
#include <set>
#include <string>

// a dump class
class Logger {
    public:
        void logAndAdd(const std::string& name) {
            auto now = 
                std::chrono::system_clock::now();
            log();
            names.emplace(name);
        }

    private:
        // a dump metho
        void log() {
            // std::cout << "logAndAdd" << std::endl;
        }
        std::multiset<std::string> names;
};


int main() {
    Logger logger;

    // pass lvalue std::string
    std::string petName("Darla");
    logger.logAndAdd(petName);

    // pass rvalue std::string
    logger.logAndAdd(std::string("Persephone"));

    // pass string literal
    logger.logAndAdd("Patty Dog");

    return 0;
}
