#include <mutex>

// a dumb function
void prepare_data() { }

// a dumb function
void do_something() { }

std::unique_lock<std::mutex> get_lock() {
    std::mutex some_mutex;
    std::unique_lock<std::mutex> lk(some_mutex);
    prepare_data();
    return lk;
}

void process_data() {
    std::unique_lock<std::mutex> lk(get_lock());
    do_something();
}

int main() {
    process_data();
}
