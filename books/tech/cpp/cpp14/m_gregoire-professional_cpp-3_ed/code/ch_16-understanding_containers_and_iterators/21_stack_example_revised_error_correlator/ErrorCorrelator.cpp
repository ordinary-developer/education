#include "ErrorCorrelator.hpp"

#include <stdexcept>


bool operator < (const Error& lhs, const Error& rhs) {
    return (lhs._priority < rhs._priority);
}

std::ostream& operator << (std::ostream& os, const Error& err) {
    os << err._errorMessage << " (priority " << err._priority << ")";
    return os;
}

void ErrorCorrelator::addError(const Error& error) {
    _errors.push(error);
}

Error ErrorCorrelator::getError() {
    if (_errors.empty()) {
        throw std::out_of_range("No more errors.");
    }
    Error top = _errors.top();
    _errors.pop();
    return top;
}
