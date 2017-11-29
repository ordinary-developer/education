#include <thread>
#include <assert.h>

void do_background_work() { }

int main() { 
    std::thread t(do_background_work);
    t.detach();
    assert(!t.joinable());

    return 0;
}
