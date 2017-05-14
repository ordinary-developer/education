#include <iostream>

template <class T>
class list {
    public:
        list()
            : head_{ nullptr }, tail_{ nullptr }, size_{ 0 } { }

        ~list() { clear(); }

        void clear() { }

        void push_back(T const& x) {
            node* n{ new node{ x } };
            if (nullptr == tail_)
                head_ = tail_ = n;
            else {
                n->prev_ = tail_;
                tail_->next = n;
                tail_ = n;
            }
            ++size_;
        }

        void pop_back() {
            node* n{ tail_ };
            if (head_ == tail_)
                head_ = tail_ = nullptr;
            else {
                tail_ = tail_->prev;
                tail_->next_ = nullptr;
            }
            --size_;
            delete n;
        }

    private:
        class node {
            public:
                node(T const& key) 
                    : next_{ nullptr }, prev_{ nullptr }, value_{ key } { }

                node* next_;
                node* prev_;
                T value_;
        };

        node* head_;
        node* tail_;
        std::size_t size_;
};


int main() {
    return 0;
}
