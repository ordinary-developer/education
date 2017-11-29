#include <thread>
#include <memory>
#include <iostream>

struct big_object {
    void prepare_data(int value) {
        data = value;
    }
    int data;
};


void process_big_object(std::unique_ptr<big_object> p) 
{
    std::cout << p->data << std::endl;
}

int main() {
    std::unique_ptr<big_object> p(new big_object);
    p->prepare_data(42);
    std::thread t(process_big_object, std::move(p));
    t.join();

    return 0;
}
