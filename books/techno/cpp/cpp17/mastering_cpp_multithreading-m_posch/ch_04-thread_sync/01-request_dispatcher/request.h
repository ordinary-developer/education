#pragma once

class AbstractRequest {
    public:
        virtual ~AbstractRequest() = default;

        virtual void setValue(int value) = 0;
        virtual void process() = 0;
        virtual void finish() = 0;
};

#include <string>

typedef void (*LogFn)(std::string const&);

class Request : public AbstractRequest {
    public:
        virtual ~Request() = default;

        virtual void setValue(int value) override final {
            value_ = value;
        }

        virtual void process() override final {
            outFn_("Starting processing request "
                   + std::to_string(value_) + " ...");
        }

        virtual void finish() override final {
            outFn_("Finished request " + std::to_string(value_));
        }

        void setOutput(LogFn fn) { outFn_ = fn; }

    private:
        int value_;
        LogFn outFn_;
};
