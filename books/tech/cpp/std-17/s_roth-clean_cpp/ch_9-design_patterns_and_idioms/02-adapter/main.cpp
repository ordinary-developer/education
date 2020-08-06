#include <memory>
#include <string_view>
#include <boost/log/trivial.hpp>
class LoggingFacility {
    public:
        virtual ~LoggingFacility() = default;

        virtual void writeInfoEntry(std::string_view entry) = 0;
        virtual void writeWarnEntry(std::string_view entry) = 0;
        virtual void writeErrorEntry(std::string_view entry) = 0;
};

class BostTrivialLogAdatper : public LoggingFacility {
    virtual void writeInfoEntry(std::string_view entry) override {
        BOOST_LOG_TRIVIAL(info) << entry;
    }

    virtual void writeWarnEntry(std::string_view entry) override {
        BOOST_LOG_TRIVIAL(warn) << entry;
    }

    virtual void writeErrorEntry(std::string_view entry) override {
        BOOST_LOG_TRIVIAL(error) << entry;
    }
};

int main() {
    return 0;
}
