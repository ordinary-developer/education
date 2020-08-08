#include <exception>
#include <stack>
#include <mutex>
#include <memory>


struct empty_stack_exception final : std::exception {
    const char* what() const throw() {
        return "empty stack";
    }
};


template <typename T>
class threadsafe_stack {
    public:
        threadsafe_stack() = default;
        threadsafe_stack(threadsafe_stack const& other) {
            std::lock_guard<std::mutex> lock{other.mut_};
            data_ = other.data_;
        }
        threadsafe_stack& operator=(threadsafe_stack const&) = delete;

        void push(T new_val) {
            std::lock_guard<std::mutex> lock{mut_};
            data_.push(std::move(new_val));
        }

        std::shared_ptr<T> pop() {
            std::lock_guard<std::mutex> lock{mut_};
            if (data_.empty())
                throw empty_stack_exception{};
            std::shared_ptr<T> const res{
                std::make_shared<T>(std::move(data_.top())) };
            data_.pop();
            return res;
        }

        void pop(T& val) {
            std::lock_guard<std::mutex> lock{mut_};
            if (data_.empty())
                throw empty_stack_exception{};
            val = std::move(data_.top());
            data_.pop();
        }

        bool empty() const {
            std::lock_guard<std::mutex> lock{mut_};
            return data_.empty();
        }

    private:
        std::stack<T> data_;
        mutable std::mutex mut_;
};


int main() {
    threadsafe_stack<int>{};
}
