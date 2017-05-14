#include <thread>
#include <future>
#include <vector>

class Widget {
    private:
        std::shared_future<double> fut;
};

int main() {
    std::vector<std::future<void>> futs;
    return 0;
}
