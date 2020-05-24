#include <memory>

template <typename T>
class queue {
    public:
        queue() = default;

        queue(const queue& other) = delete;
        queue& operator= (const queue& other) = delete;

        std::shared_ptr<T> try_pop() {
            if (!_head) 
                return std::shared_ptr<T>();
            const std::shared_ptr<T> res(
              std::make_shared<T>(std::move(_head->data)));
            const std::unique_ptr<node> old_head = std::move(_head);
            _head = std::move(old_head->next);
            return res;
        }

        void push (T new_value) {
            std::unique_ptr<node> p(new node(std::move(new_value)));
            const node* new_tail = p.get();
            if (_tail)
                _tail->next = std::move(p);
            else
               _head = std::move(p);
            _tail = new_tail;
        }

    private:
        struct node {
            T data;
            std::unique_ptr<node> next;

            node(T data_) : data(std::move(data_)) { }
        };

        std::unique_ptr<node> _head;
        node* _tail;
};

int main() {
    return 0;
}
