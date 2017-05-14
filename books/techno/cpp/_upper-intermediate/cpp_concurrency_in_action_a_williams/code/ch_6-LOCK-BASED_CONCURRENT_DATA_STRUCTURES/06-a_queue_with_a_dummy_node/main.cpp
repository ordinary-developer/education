#include <memory>

template <typename T>
class queue {
    public:
        queue() : _head(new node()), _tail(_head.get()) { }
        queue(const queue& other) = delete;
        queue& operator= (const queue& other) = delete;

        std::shared_ptr<T> try_pop() {
            if (_head.get() == _tail)
                return std::shared_ptr<T>();
            const std::shared_ptr<T> res(_head->data);
            std::unique_ptr<node> old_head = std::move(_head);
            _head = std::move(old_head->next);
            return res;
        }

        void push(T new_value) {
            std::shared_ptr<T> new_data(
              std::make_shared<T>(std::move(new_value)));
            std::unique_ptr<node> p(new node);
            _tail->data = new_data;
            const node* new_tail = p.get();
            _tail->next = std::move(p);
            _tail = new_tail;
        }

    private:
        struct node {
            std::shared_ptr<T> data;
            std::unique_ptr<node> next;
        };

        std::unique_ptr<node> _head;
        node* _tail;
};

int main() {
    return 0;
}
