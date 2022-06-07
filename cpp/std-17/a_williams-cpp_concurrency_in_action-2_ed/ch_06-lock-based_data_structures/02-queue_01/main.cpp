#include <queue>
#include <mutex>
#include <condition_variable>
#include <memory>


template <typename T>
class threadsafe_queue {
    public:
        threadsafe_queue() = default;

        void push(T val) {
            std::lock_guard<std::mutex> lock{mut_};
            queue_.push(std::move(val));
            cond_var_.notify_one();
        }

        void wait_and_pop(T& val) {
            std::unique_lock<std::mutex> lock{mut_};
            cond_var_.wait(lock, [this] { return not queue_.empty(); });
            val = std::move(queue_.front());
            queue_.pop();
        }

        std::shared_ptr<T> wait_and_pop() {
            std::unique_lock<std::mutex> lock{mut_};
            cond_var_.wait(lock, [this] { return not queue_.empty(); });
            std::shared_ptr<T> res{
                std::make_shared<T>(std::move(queue_.front())) };
            queue_.pop();
            return res;
        }

        bool try_pop(T& val) {
            std::lock_guard<std::mutex> lock{mut_};
            if (queue_.empty())
                return false;
            val = std::move(queue_.front());
            queue_.pop();
        }

        std::shared_ptr<T> try_pop() {
            std::lock_guard<std::mutex> lock{mut_};
            if (queue_.empty())
                return std::shared_ptr<T>{};
            std::shared_ptr<T> res{
                std::make_shared<T>(std::move(queue_.front()))};
            queue_.pop();
            return res;
        }

        bool empty() const {
            std::lock_guard<std::mutex> lock{mut_};
            return queue_.empty();
        }

    private:
        mutable std::mutex mut_{};
        std::queue<T> queue_;
        std::condition_variable cond_var_;
};


int main() {
    threadsafe_queue<int> var{};

    return 0;
}
