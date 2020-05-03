#include <gtest/gtest.h>

#include <memory>
#include <string_view>
#include <iostream>
#include <string>

class LoggingFacility {
    public:
        virtual ~LoggingFacility() = default;

        virtual void writeInfoEntry(std::string_view entry) = 0;
        virtual void writeWarnEntry(std::string_view entry) = 0;
        virtual void writeErrorEntry(std::string_view entry) = 0;
};
using Logger = std::shared_ptr<LoggingFacility>; 

class StandardOutputLogger : public LoggingFacility {
    public:
        virtual void writeInfoEntry(std::string_view entry) override {
            std::cout << "[INFO] " << entry << std::endl;
        }

        virtual void writeWarnEntry(std::string_view entry) override {
            std::cout << "[WARNING] " << entry << std::endl;
        }

        virtual void writeErrorEntry(std::string_view entry) override {
            std::cout << "[ERROR] " << entry << std::endl;
        }
};

class Customer {};
class Identifier {};
class CustomerRepository {
    public:
        CustomerRepository() = delete;
        explicit CustomerRepository(Logger const& loggingService)
            : logger_{ loggingService } {}

        Customer findCustomerById(Identifier const&) {
            logger_->writeInfoEntry("Starting to search for a customer");
            return Customer{};
        }

    private:
        Logger logger_;
};

class LoggingFacilityMock : public LoggingFacility {
    public:
        virtual void writeInfoEntry(std::string_view entry) override {
            recentlyWrittenLogEntry = entry;
        }

        virtual void writeWarnEntry(std::string_view entry) override {
            recentlyWrittenLogEntry = entry;
        }

        virtual void writeErrorEntry(std::string_view entry) override {
            recentlyWrittenLogEntry = entry;
        }

        std::string_view getRecentlyWrittenLogEntry() const {
            return recentlyWrittenLogEntry;
        }

    private:
        std::string recentlyWrittenLogEntry;
};
using MockLogger = std::shared_ptr<LoggingFacilityMock>;


TEST(CustomerTestCase, WrittenLogEntryIaAsExpected) {
    MockLogger logger{ std::make_shared<LoggingFacilityMock>() };
    CustomerRepository customerRepositoryToTest{ logger };

    customerRepositoryToTest.findCustomerById(Identifier{});
    
    ASSERT_EQ("Starting to search for a customer",
              logger->getRecentlyWrittenLogEntry());
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

