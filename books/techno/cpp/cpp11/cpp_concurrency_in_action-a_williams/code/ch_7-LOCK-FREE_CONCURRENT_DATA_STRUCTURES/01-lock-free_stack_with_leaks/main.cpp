#include <atomic>
#include <memory>

template <typename T>
class lock_free_stack {
    public:
        void push(const T& data) {
            node* const new_node = new node(data);
            new_node->next = head.load();
            while (!head.compare_exchange_weak(new_node->next,
                                               new_node));
        }

        std::shared_ptr<T> pop() {
            node* old_head = head.load();
            while (old_head &&
                   !head.compare_exchange_weak(old_head,
                                               old_head->next));
            return old_head ? old_head->data : std::shared_ptr<T>();
        }

    private:
        struct node {
            node(const T& data_)
                : data(std::make_shared<T>(data_)) { }
                
            std::shared_ptr<T> data;
            node* next;
        };

        std::atomic<node*> head;
};




int main() {
    return 0;
}
