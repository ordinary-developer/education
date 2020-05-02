#include <mutex>
#include <queue>
#include <condition_variable>
#include <memory>

template <typename T>
class threadsafe_queue {
    public:
        threadsafe_queue() = default;

        void push(T new_value) {
            std::lock_guard<std::mutex> lock(_mutex);
            _data_queue.push(std::move(new_value));
            _data_cond.notify_one();
        }

        void wait_and_pop(T& value) {
            std::unique_lock<std::mutex> lock(_mutex);
            _data_cond.wait(lock, [this]() -> bool
                                 {
                                   return !_data_queue.empty();
                                 });
            value = std::move(_data_queue.front());
            _data_queue.pop();
        }

        std::shared_ptr<T> wait_and_pop() {
            std::unique_lock<std::mutex> lock(_mutex);
            _data_cond.wait(lock, [this]() -> bool
                                  {
                                    return !_data_queue.empty();
                                  });
            std::shared_ptr<T> res(std::make_shared<T>(std::move(
                                     _data_queue.front())));
            _data_queue.pop();
            return res;
        }

        bool try_pop(T& value) {
            std::lock_guard<std::mutex> lock(_mutex);
            if (_data_queue.empty())
                return false;
            value = std::move(_data_queue.front());
            _data_queue.pop();
            return true;
        }

        std::shared_ptr<T> try_pop() {
            std::lock_guard<std::mutex> lock(_mutex);
            if (_data_queue.empty())
                return std::shared_ptr<T>();
            std::shared_ptr<T> res(
                std::make_shared<T>(std::move(_data_queue.front())));
            _data_queue.pop();
            return res;
        }

        bool empty() const {
            std::lock_guard<std::mutex> lock(_mutex);
            return _data_queue.empty();
        }
    private:
        mutable std::mutex _mutex;
        std::queue<T> _data_queue;
        std::condition_variable _data_cond;
};

int main() {
    return 0;
}
