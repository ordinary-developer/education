#include <memory>
#include <mutex>


struct some_resource {
    void do_something() { }
};

std::shared_ptr<some_resource> resource_ptr;
std::once_flag resource_flag;

void init_resource() {
    resource_ptr.reset(new some_resource);
}

void foo() {
    std::call_once(resource_flag, init_resource);
    resource_ptr->do_something();
}


int main() {
    foo();

    return 0;
}
