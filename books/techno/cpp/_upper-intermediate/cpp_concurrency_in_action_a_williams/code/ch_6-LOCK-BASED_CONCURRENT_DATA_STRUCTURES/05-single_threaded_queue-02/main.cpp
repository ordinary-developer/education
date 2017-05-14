#include <memory>
#include <cstdint>
#include <iostream>

template <typename T>
class queue {
    public:
        queue() = default;
        queue(const queue&) = delete;
        queue& operator= (const queue&) = delete;

        std::shared_ptr<T> try_pop() {
            if (!_head)
                return std::shared_ptr<T>();

            std::shared_ptr<T> result(
                std::make_shared<T>(std::move(_head->data)));
            _head = std::move(_head->next);
            return result;
        }

        void push(T new_value) {
            std::unique_ptr<node> p(new node(std::move(new_value)));
            node* const newTail = p.get();
            if (_tail)
                _tail->next = std::move(p);
            else
                _head = std::move(p);
            _tail = newTail;
        }
    private:
        struct node {
            node(T data_) : data(data_) { }

            T data;
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
        auto pointerToValue = queue.try_pop();
        if (pointerToValue)
           std::cout << *pointerToValue << std::endl;
    }

    return 0;
}
