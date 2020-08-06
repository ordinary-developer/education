#include <memory>
#include <string_view>
#include <iostream>
#include <string>
#include <sstream>

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

class LoggerFactory1 {
    public:
        static Logger create() {
            return std::make_shared<StandardOutputLogger>();
        }
};


// dump realization
class FileSystemLogger : public LoggingFacility {
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

class LoggerFactory2 {
    private:
        enum class OutputTarget : int {
            STDOUT,
            FILE
        };

    public:
        explicit LoggerFactory2(std::string_view configurationFileName) 
            : configurationFileName_{ configurationFileName } { }

        Logger create() const {
            std::string const configurationFileContent = 
                readConfigurationFile();
            OutputTarget outputTarget = 
                evaluateConfiguration(configurationFileContent);
            return createLogger(outputTarget);
        }

    private:
        std::string readConfigurationFile() const {
            return std::string("simple value");
        }

        OutputTarget evaluateConfiguration(
                        std::string_view configurationFileContent) const
        {
            return OutputTarget::STDOUT;
        }

        Logger createLogger(OutputTarget outputTarget) const {
            switch (outputTarget) {
                case OutputTarget::FILE:
                    return std::make_shared<FileSystemLogger>();
                case OutputTarget::STDOUT: 
                default:
                    return std::make_shared<StandardOutputLogger>();
            }
        }

    private:
        std::string const configurationFileName_;
};

int main() {
    Logger logger1 = LoggerFactory1::create();

    return 0;
}

