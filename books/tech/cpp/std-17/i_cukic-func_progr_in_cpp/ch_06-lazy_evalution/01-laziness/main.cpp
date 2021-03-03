#include <functional>
#include <memory>
#include <mutex>
#include <cassert>
namespace test_01 { // base laziness

template <typename F>
class lazy_val {            
private:
    F m_computation;
    mutable bool m_cache_initialized;
    mutable decltype(m_computation()) m_cache;
    mutable std::mutex m_cache_mutex;
    
public:
    lazy_val(F computation) :
        m_computation{computation},
        m_cache_initialized{false} {}
        
    operator const decltype(m_computation())& () const {
        std::unique_lock<std::mutex> lock{m_cache_mutex};
        
        if (not m_cache_initialized) {
            m_cache = m_computation();
            m_cache_initialized = true;
        }
        return m_cache;
    }

};

template <typename F>
inline lazy_val<F> make_lazy_val(F&& computation) {
    return lazy_val<F>(std::forward<F>(computation));
}
    
void run() {    
    bool sentinel{true};
    auto const& lazy_v = make_lazy_val([sentinel]() { 
        assert(sentinel);
        return 42;
    });
    
    sentinel = false;
    assert(42 == lazy_v);
}
} // test_01


#include <functional>
#include <mutex>
#include <cassert>
namespace test_02 { // the same but with the std::call_once

template <typename F>
class lazy_val {
private:
    F m_computation;
    mutable decltype(m_computation()) m_cache;
    mutable std::once_flag m_value_flag;
    
public:
    lazy_val(F computation) : m_computation{computation} {}
    
    operator const decltype(m_computation())& () const {
        std::call_once(m_value_flag, [this] {
            m_cache = m_computation();
        });
        
        return m_cache;
    }        
    
};

template <typename F>
inline lazy_val<F> make_lazy_val(F&& computation) {
    return lazy_val<F>(std::forward<F>(computation));
}
    
void run() {    
    bool sentinel{true};
    auto const& lazy_v = make_lazy_val([sentinel]() { 
        assert(sentinel);
        return 42;
    });
    
    sentinel = false;
    assert(42 == lazy_v);
}
} // test_02


#include <functional>
#include <memory>
#include <mutex>
#include <optional>
#include <cassert>
namespace test_03 { // example from the book's src code
    
template <typename F>
class lazy_val {
private:
    F m_computation;
    mutable std::optional<decltype(m_computation())> m_value;    
    mutable std::mutex m_value_lock;

public:
    lazy_val(F computation) : m_computation{computation} {}


    lazy_val(lazy_val &&other)
        : m_computation(std::move(other.m_computation)) {}

    operator decltype(m_computation()) () const {
        std::unique_lock<std::mutex> lock{m_value_lock};

        if (not m_value)
            m_value = std::invoke(m_computation);

        return *m_value;
    }
};

template <typename F>
inline lazy_val<F> make_lazy_val(F&& computation) {
    return lazy_val<F>(std::forward<F>(computation));
}


struct _make_lazy_val_helper {
    
template <typename F>
auto operator - (F&& function) const {
    return lazy_val<F>(function);
}
} make_lazy_val_helper;
#define lazy make_lazy_val_helper - [=]

void run() {
    bool sentinel{true};
    
    auto val = lazy {        
        assert(sentinel);
        return 42;
    };
    
    sentinel = false;
    assert(42 == val);
}

} // test_03




#include <iostream>
int main() {
    std::cout << "test_01 => [ok]" << std::endl; test_01::run(); std::cout << std::endl;
    std::cout << "test_02 => [ok]" << std::endl; test_02::run(); std::cout << std::endl;
    std::cout << "test_03 => [ok]" << std::endl; test_03::run(); std::cout << std::endl;

    return 0;
}
