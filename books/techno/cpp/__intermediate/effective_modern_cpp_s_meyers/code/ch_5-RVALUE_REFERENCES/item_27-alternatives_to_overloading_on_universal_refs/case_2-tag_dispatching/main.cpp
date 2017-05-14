#include <string>
#include <set>
#include <memory>
#include <type_traits>
#include <chrono>


class Logger {
    public:
        template <typename T>
        void logAndAdd(T&& name)
        {
            logAndAddImpl(std::forward<T>(name),
                      std::is_integral<std::remove_reference_t<T>>());
        }

        template <typename T>
        void logAndAddImpl(T&& name, std::false_type)
        {
            auto now = std::chrono::system_clock::now();
            log();
            names.emplace(std::forward<T>(name));
        }

        // a dump function
        std::string nameFromIdx(int idx) 
        {
            return std::string("exempli gratia");
        }

        void logAndAddImpl(int idx, std::true_type) 
        {
            logAndAdd(nameFromIdx(idx));
        }

    private:
        // a dump function
        void log() { }

        std::multiset<std::string> names;
};


int main() {
    Logger logger;

    logger.logAndAdd("simpel string");

    logger.logAndAdd(0);

    return 0;
}
