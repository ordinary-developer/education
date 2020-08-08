#include <mutex>
#include <memory>
#include <queue>
#include <condition_variable>

template <typename T>
class threadsafe_queue {
    public:
        threadsafe_queue() = default;

        void wait_and_pop(T& value) {
            std::unique_lock<std::mutex> lock(_mutex);
            _data_cond.wait(lock, [this]() -> bool
                                  {
                                    return !_data_queue.empty();
                                  });
            value = std::move(*_data_queue.front());
            _data_queue.pop();
        }

        bool try_pop(T& value) {
            std::lock_guard<std::mutex> lock(_mutex);
            if (_data_queue.empty())
                return false;
            value = std::move(*_data_queue.front());
            _data_queue.pop();
            return true;
        }

        std::shared_ptr<T> wait_and_pop() {
            std::unique_lock<std::mutex> lock(_mutex);
            _data_cond.wait(lock, [this]() -> bool
                                  {
                                    return !_data_queue.empty();
                                  });
            std::shared_ptr<T> res = _data_queue.front();
            _data_queue.pop();
            return res;
        }

        std::shared_ptr<T> try_pop() {
            std::lock_guard<std::mutex> lock(_mutex);
            if (_data_queue.empty())
                return std::shared_ptr<T>();
            std::shared_ptr<T> res = _data_queue.front();
            _data_queue.pop();
            return res;
        }

        void push(T new_value) {
            std::shared_ptr<T> data(
                std::make_shared<T>(std::move(new_value)));
            std::lock_guard<std::mutex> lock(_mutex);
            _data_queue.push(data);
            _data_cond.notify_one();
        }

        bool empty() const {
            std::lock_guard<std::mutex> lock(_mutex);
            return _data_queue.empty();
        }

    private:
        mutable std::mutex _mutex;
        std::queue<std::shared_ptr<T>> _data_queue;
        std::condition_variable _data_cond;
};

int main() {
    return 0;
}
