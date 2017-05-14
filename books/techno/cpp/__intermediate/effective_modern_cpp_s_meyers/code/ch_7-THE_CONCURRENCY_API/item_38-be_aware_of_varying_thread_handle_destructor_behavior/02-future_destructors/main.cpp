#include <thread>
#include <future>

int calcValue() { return 42; }

int main() {
    {
        std::packaged_task<int()> pt(calcValue);
        auto fut = pt.get_future();
        std::thread t(std::move(pt));
    }
    return 0;
}
