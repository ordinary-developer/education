

#include <algorithm>
#include <vector>
#include <cassert>
namespace test {

class error_test_t {
public:
    error_test_t(bool const error = true) : m_error{error} {}

    template <typename T>
    bool operator()(T&& value) const {
        return m_error == (bool)std::forward<T>(value).error();
    }

    error_test_t operator==(bool test) const { 
        return error_test_t(test ? m_error : not m_error);
    }

    error_test_t operator!() const { return error_test_t(!m_error); }

private:
    bool m_error;
};

error_test_t error{true};
error_test_t not_error{false};

class response_t {
public:
    response_t(bool const error = false) : m_error{error} {}

    bool error() const { return m_error; }

private:
    bool m_error;

};


void run() {
    std::vector<response_t> responses {
        {false}, {false}, {true}, {false}, {false} };    

    std::vector<response_t> responsesWithErrs{};
    std::copy_if(std::cbegin(responses), std::cend(responses),
        std::back_inserter(responsesWithErrs), error);
    assert(1 == responsesWithErrs.size());

    std::vector<response_t> responsesWithoutErrs{};
    std::copy_if(std::cbegin(responses), std::cend(responses),
        std::back_inserter(responsesWithoutErrs), not_error);
    assert(4 == responsesWithoutErrs.size());
}

} // test


#include <iostream>
int main() {
    std::cout << "test => [ok]" << std::endl; test::run();     

    return 0;
}
