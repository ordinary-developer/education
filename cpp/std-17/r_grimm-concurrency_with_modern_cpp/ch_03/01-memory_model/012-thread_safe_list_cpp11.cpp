#include <memory>
#include <random>
#include <thread>
#include <iostream>

template <typename T> class concurrent_stack {
    struct Node { T t; std::shared_ptr<Node> next; };
    std::shared_ptr<Node> head;
    concurrent_stack(concurrent_stack &) = delete;
    void operator=(concurrent_stack&) = delete;
    
public:
    concurrent_stack() = default;
    ~concurrent_stack() = default;
    
    class reference {
        std::shared_ptr<Node> p;
    public:
        reference(std::shared_ptr<Node> p_) : p{p_} {}
        T& operator* () { return p->t; }
        T* operator->() { return &p->t; }
    };
    
    auto find(T t) const {
        auto p = std::atomic_load(&head);
        while (p && p->t != t) {
            p = p->next;
        }
        return reference(std::move(p));
    }
    
    auto front() const {
        return reference(std::atomic_load(&head));
    }
    
    void push_front(T t) {
        auto p = std::make_shared<Node>();
        p->t = t;
        p->next = std::atomic_load(&head);
        while (!std::atomic_compare_exchange_weak(&head, &p->next, p)) {}
    }
    
    void pop_front() {
        auto p = std::atomic_load(&head);
        while (p && !std::atomic_compare_exchange_weak(&head, &p, p->next)) {}
    }
};


concurrent_stack<int> stack;

void run() {
    std::random_device device;
    std::mt19937 gen(device());
    std::uniform_int_distribution<std::mt19937::result_type> distrib(1, 3);
    const int cnt = distrib(gen);
    
    for (int i = 0; i < cnt; i++)
        stack.pop_front();
}


int main()
{
    for (int i = 0; i < 10; i++) {
        stack.push_front(i);
    }
    
    std::thread t1(run);
    std::thread t2(run);
    
    t1.join();
    t2.join();
    
    std::cout << "front value = [" << *stack.front() << "]" << std::endl;
    auto rf = stack.find(1);
    std::cout << "found value = [" << *rf << "]" << std::endl;
}
