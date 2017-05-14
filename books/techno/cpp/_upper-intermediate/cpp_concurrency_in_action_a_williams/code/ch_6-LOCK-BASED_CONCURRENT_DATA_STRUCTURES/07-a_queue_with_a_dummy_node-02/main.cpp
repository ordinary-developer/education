#include <memory>
#include <cstdint>
#include <iostream>


template <typename T>
class queue {
    public:
        queue() : _head(new node()), _tail(_head.get()) { }
        queue(const queue&) = delete;
        queue& operator=(const queue&) = delete;

        std::shared_ptr<T> try_pop() {
            if (_head.get() == _tail)
                return std::shared_ptr<T>();

            std::shared_ptr<T> result(_head->data);
            _head = std::move(_head->next);
            return result;
        }

        void push(T new_value) {
            std::shared_ptr<T> new_data(
                std::make_shared<T>(std::move(new_value)));
            _tail->data = new_data;

            std::unique_ptr<node> p(new node());
            node* const new_tail = p.get();
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
    queue<uint32_t> queue;

    for (uint32_t i = 0; i < 10; ++i)
        queue.push(i);

    for (uint32_t i = 0; i < 10; ++i) {
        auto element = queue.try_pop();
        if (element)
            std::cout << *element << std::endl;
    }

    return 0;
}
