#include <exception>
#include <mutex>
#include <stack>
#include <memory>

struct empty_stack : std::exception {
    const char* what() const throw();
};

template <typename T>
class threadsafe_stack {
    public:
        threadsafe_stack() { }
        threadsafe_stack(const threadsafe_stack& other) {
            std::lock_guard<std::mutex> lock(other._m);
            _data = other._data;
        }
        threadsafe_stack& operator=(const threadsafe_stack&) = delete;

        void push(T new_value) {
            std::lock_guard<std::mutex> lock(_m);
            _data.push(std::move(new_value));
        }
        std::shared_ptr<T> pop() {
            std::lock_guard<std::mutex> lock(_m);
            if (_data.empty())
                throw empty_stack();
            const std::shared_ptr<T> res(std::make_shared<T>(
                                           std::move(_data.top())));
            _data.pop();
            return res;
        }
        void pop(T& value) {
            std::lock_guard<std::mutex> lock(_m);
            if (_data.empty())
                throw empty_stack();
            value = std::move(_data.top());
            _data.pop();
        }
        bool empty() const {
            std::lock_guard<std::mutex> lock(_m);
            return _data.empty();
        }
        
    private:
        std::stack<T> _data;
        mutable std::mutex _m;
};

int main() {
    return 0;
}
