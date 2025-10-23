#ifndef ERROR_CORRELATOR_HPP
#define ERROR_CORRELATOR_HPP


#include <string>
#include <ostream>
#include <stack>

class Error {
    public:
        Error(int priority, const std::string& errorMessage)
            : _priority(priority), _errorMessage(errorMessage) { } 

        int getPriority() const { return _priority; }
        const std::string& getErrorMessage() const { return _errorMessage; }

        friend bool operator < (const Error& lhs, const Error& rhs);
        friend std::ostream& operator << (std::ostream& os, const Error& err);
    private:
        int _priority;
        std::string _errorMessage;
};


class ErrorCorrelator {
    public:
        void addError(const Error& error);
        Error getError();
    private:
        std::stack<Error> _errors;
};

#endif
