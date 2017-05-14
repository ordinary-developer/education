#include <memory>
#include <mutex>

template <typename T>
class threadsafe_queue {
    public:
        threadsafe_queue() 
            : _head(new node()), _tail(_head.get()) { }
        threadsafe_queue(const threadsafe_queue&) = delete;
        threadsafe_queue& operator= (const threadsafe_queue&) = delete;

        std::shared_ptr<T> try_pop() {
            std::unique_ptr<node> old_head = pop_head();
            return old_head ? old_head->data : std::shared_ptr<T>();
        }

        void push(T new_value) {
            std::shared_ptr<T> new_data(
              std::make_shared<T>(std::move(new_value)));
            std::unique_ptr<node> p(new node());
            const node* new_tail = p.get();
            std::lock_guard<std::mutex> tail_lock(_tail_mutex);
            _tail->data = new_data;
            _tail->next = std::move(p);
            _tail = new_tail;
        }
    private:
        node* get_tail() {
            std::lock_guard<std::mutex> tail_lock(_tail_mutex);
            return _tail;
        }

        std::unique_ptr<node> pop_head() {
            std::lock_guard<std::mutex> head_lock(_head_mutex);
            if (_head.get() == get_tail()) 
                return nullptr;
            std::unique_ptr<node> old_head = std::move(_head);
            _head = std::move(old_head->next);
            return old_head;
        }

        struct node {
            std::shared_ptr<T> data;
            std::unique_ptr<node> next;
        };

        std::mutex _head_mutex;
        std::unique_ptr<node> _head;
        std::mutex _tail_mutex;
        node* _tail;
};

int main() {
    return 0;
}
