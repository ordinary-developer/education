#include <memory>
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>
#include <variant>
#include <cassert>
namespace workspace {

// errors
template <typename T, typename E>
class expected {
private:
    union {
        T m_value;
        E m_error;
    };

    bool m_valid;

public:
    template <typename... Args>
    static expected success(Args&&... params) {
        expected result;
        result.m_valid = true;
        new (&result.m_value)     
            T(std::forward<Args>(params)...);
        return result;
    }
    
    template <typename... Args>
    static expected error(Args&&... params) {
        expected result;
        result.m_valid = false;
        new (&result.m_error)
            E(std::forward<Args>(params)...);
        return result;
    }
    
    expected(expected const& other) : m_valid{other.m_valid} {
        (m_valid ? new (&m_value) T{other.m_value} : new (&m_error) E{other.m_error});
    }
    
    expected(expected&& other) : m_valid{other.m_valid} {
        (m_valid ? new (&m_value) T{std::move(other.m_value)} : new (&m_error) E{std::move(other.m_error)});
    }
    
    ~expected() {
        (m_valid ? m_value.~T() : m_error.~E());
    }
    
    void swap(expected& other) {
        using std::swap;
        if (m_valid) {
            if (other.m_valid) {
                std::swap(m_value, other.m_value);
            }
            else {
                auto tmp = std::move(other.m_error);
                other.m_error.~E();
                new (&other.m_value) T(std::move(m_value));
                m_value.~T();
                new (&m_error) E(std::move(tmp));
                std::swap(m_valid, other.m_valid);
            }
        }
        else {
            if (other.m_valid) {
                other.swap(*this);
            }
            else {
                swap(m_error, other.m_error);
            }
        }
    }
    
    expected& operator= (expected other) {
        swap(other);
        return *this;
    }
    
    T& get() {
        if (not m_valid) {
            throw std::logic_error{"missing a value"};
        }
        
        return m_value;
    }
    
    E& error() {
        if (m_valid) {
            throw std::logic_error{"there is no error"};
        }
        
        return m_error;
    }
    
    operator bool() const { return m_valid; }
    
    operator std::optional<T>() const {
        if (m_valid) { 
            return m_value;
        }
        else {
            return std::optional<T>();
        }
    }
};

// AN ERROR HERE
template <typename T, typename Variant,
          typename Expected = expected<T, std::string>>
Expected local_get_if(Variant const& variant)
{
    decltype(std::get_if<T>(&variant)) ptr = std::get_if<T>(&variant);
    
    // T* ptr = std::get_if<T>(variant)::value;    
    // if (ptr) {
    //     return Expected::success(T{*ptr});
    // }
    // else {
    //     return Expected::error("variant doesn't contain the desired type");
    // }
}          


// states
class init_t {};

class running_t {
public:
    unsigned count() const { return m_count; }

private:
    unsigned m_count = 0;
};

class finished_t {
public:
    finished_t(unsigned const count) : m_count{count} {}
        
    unsigned count() const { return m_count; }

private:
    unsigned m_count;
}; 


// program
class program_t {
public:
    program_t() : m_state{init_t{}} {}

    void start() {
        assert((nullptr != std::get_if<init_t>(&m_state)));
        m_state = running_t{};
    }

    void finish() {

        auto status = local_get_if<running_t>(m_state);
        
        // try {
        //     running_t state = status.get();
        //     assert((true));
        //     m_state = finished_t(state.count()); 
        // }
        // catch (std::exception const&) { assert((false)); }
        
        // try {
        //     status.error();
        //     assert((false));
        // }
        // catch (std::logic_error const&) { assert((true)); }
        
    }

private:
    std::variant<init_t, running_t, finished_t> m_state;
}; 


void run() {

}

} // workspace


#include <iostream>
int main() {
    std::cout << "test => [ok]" << std::endl;
    workspace::run();
    std::cout << std::endl << std::endl;

    return 0;
}
