#include <atomic>
#include <memory>

template <typename T>
class lock_free_stack {
    public:
        std::shared_ptr<T> pop() {
            ++threads_in_pop;
            node* old_head = head.load();
            while (old_head &&
                   !head.compare_exchange_weak(old_head, 
                                               old_head->next));
            std::shared_ptr<T> res;
            if(old_head) {
                res.swap(old_head->data);
            }
            try_reclaim(old_head);
            return res;
        }

        void push(const T& data) {
            node* const new_node = new node(data);
            new_node->next = head.load();
            while (!head.compare_exchange_weak(new_node->next,
                                               new_node));
        }

    private:
        struct node {
            node(const T& data_)
                : data(std::make_shared<T>(data_)) { }
                
            std::shared_ptr<T> data;
            node* next;
        };

        void try_reclaim(node* old_head) { 
            if (1 == threads_in_pop) {
                node* nodes_to_delete = 
                    to_be_deleted.exchange(nullptr);
                if (!--threads_in_pop) {
                    delete_nodes(nodes_to_delete);
                }
                else if(nodes_to_delete) {
                    chain_pending_nodes(nodes_to_delete);
                }
                delete old_head;
            }
            else {
                chain_pending_node(old_head);
                --threads_in_pop;
            }
        }

        void chain_pending_node(node* n) {
            chain_pending_nodes(n, n);
        }

        void chain_pending_nodes(node* nodes) {
            node* last = nodes;
            while (node* const next = last->next) {
                last = next;
            }
            chain_pending_nodes(nodes, last);
        }

        void chain_pending_nodes(node* first, node* last) {
            last->next = to_be_deleted;
            while (!to_be_deleted.compare_exchange_weak(last->next,
                                                        first));
        }

        static void delete_nodes(node* nodes) {
            while (nodes) {
                node* next = nodes->next;
                delete nodes;
                nodes = next;
            }
        }

        std::atomic<node*> head;
        std::atomic<unsigned> threads_in_pop;
        std::atomic<node*> to_be_deleted;
};


int main() {
    return 0;
}
